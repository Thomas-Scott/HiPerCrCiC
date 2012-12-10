//
//  Indexer.cpp
//  HiPerCrCic
//
//  Created by Thomas Scott on 12/1/12.
//
//

#include "Indexer.h"


void Indexer::verifyIndex(char* target,bool clearIndex){
    if ( !clearIndex && IndexReader::indexExists(target) ){
		if ( IndexReader::isLocked(target) ){
			printf("Index was locked... unlocking it.\n");
			IndexReader::unlock(target);
		}
        
		writer = _CLNEW IndexWriter( target, &an, false);
	}else{
		writer = _CLNEW IndexWriter( target ,&an, true);
	}
}

void Indexer::setUpWriter(){
    writer->setMaxFieldLength(IndexWriter::DEFAULT_MAX_FIELD_LENGTH);
    writer->setMaxBufferedDocs(50);
    writer->setMaxFieldLength(0x7FFFFFFFL); // LUCENE_INT32_MAX_SHOULDBE
    writer->setUseCompoundFile(false);
}



Document* Indexer::FileDocument(const char* path){
	Document* doc = _CLNEW Document();
    TCHAR tf[CL_MAX_DIR];
    STRCPY_AtoT(tf,path,CL_MAX_DIR);
    doc->add( *_CLNEW Field(_T("path"), tf, Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    FILE* fh = fopen(path,"r");
	if ( fh != NULL ){
		StringBuffer str;
		//int fn = fileno(fh);
		//struct stat filestat;
		//fstat(fn, &filestat);
		//str.reserve(filestat.st_size);
		char abuf[1024];
		TCHAR tbuf[1024];
		size_t r;
		do{
            r = fread(abuf,1,1023,fh);
			abuf[r]=0;
			STRCPY_AtoT(tbuf,abuf,r);
			tbuf[r]=0;
			str.append(tbuf);
		}while(r>0);
		fclose(fh);
		doc->add( *_CLNEW Field(_T("contents"),str.getBuffer(), Field::STORE_YES | Field::INDEX_TOKENIZED) );
	}
	return doc;
}

void Indexer::indexDocs(IndexWriter* writer, char* directory) {
	DIR* dir = opendir(directory);
	if ( dir != NULL ){
		struct dirent* fl;
		struct fileStat buf;
		char path[CL_MAX_DIR];
		strcpy(path,directory);
		strcat(path,PATH_DELIMITERA);
		char* pathP = path + strlen(path);
		fl = readdir(dir);
		while ( fl != NULL ){
			if ( (strcmp(fl->d_name, ".")) && (strcmp(fl->d_name, "..")) ) {
                pathP[0]=0;
                strcat(pathP,fl->d_name);
                //int32_t ret = fileStat(path,&buf);
                if ( buf.st_mode & S_IFDIR ) {
                    indexDocs(writer, path );
                }else{
                    //printf( "adding: %s\n", fl->d_name );
                    Document* doc = FileDocument( path );
                    writer->addDocument( doc );
                    _CLDELETE(doc);
                }
            }
            fl = readdir(dir);
		}
		closedir(dir);
	}else{
        printf( "adding: %s\n", directory);
        
        Document* doc = FileDocument( directory );
        writer->addDocument( doc );
        _CLDELETE(doc);
	}
}

void Indexer::execute(){
    verifyIndex(target,clearIndex);
    setUpWriter();
    uint64_t startTime = lucene::util::Misc::currentTimeMillis();
    indexDocs(writer, path);
	writer->optimize();
	writer->close();
    elapsed =lucene::util::Misc::currentTimeMillis() - startTime;
	_CLDELETE(writer);
    //printf("Indexing took: %d ms.\n\n", lucene::util::Misc::currentTimeMillis() - startTime);
}

void Indexer::init(char* p, char* t, bool cI){
	path=p;
	target=t;
	clearIndex=cI;
}

Indexer::Indexer(char* path, char* target, bool clearIndex){
	init(path,target,clearIndex);
}
