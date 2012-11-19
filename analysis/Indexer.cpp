//
//  Indexer.cpp
//  
//
//  Created by Thomas Scott on 11/18/12.
//
//

#include "Indexer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cctype>
#include <string.h>
#include <algorithm>

#include "CLucene/StdHeader.h"
#include "CLucene/_clucene-config.h"

#include "CLucene.h"
#include "CLucene/util/CLStreams.h"
#include "CLucene/util/dirent.h"
#include "CLucene/config/repl_tchar.h"
#include "CLucene/util/Misc.h"
#include "CLucene/util/StringBuffer.h"
#include "Docs.pb.h"
#include <string.h>

using namespace std;
using namespace lucene::index;
using namespace lucene::analysis;
using namespace lucene::util;
using namespace lucene::store;
using namespace lucene::document;


void Indexer::fileDocumentGenerator(Document* doc,path){
    fstream input(path, ios::in | io::binary);
    Page p;
    p.ParseFromIstream(&input)
    addURI(&doc,p);
    if (p.has_Author()) addAuthor(&doc,p);
    if (p.has_Fragments()) addFragments(&doc,p);
    if (p.has_Title()) addTitle(&doc,p);
    return void;
}

void Indexer::addURI(Document* doc,Page p){
    char* uri = p.uri();
    doc->add( *_CLNEW Field(_T("uri"), uri, Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    return;
}

void Indexer::addTitle(Document* doc,Page p){
    char* title;
    for (int i=0; p.title_size(); i++) {
        title=p.title(i);
    }
    doc->add( *_CLNEW Field(_T("title"), title, Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    return;
}

void Indexer::addAuthor(Document* doc, Page p){
    char* author;
    for (int i=0; p.author_size(); i++) {
        Author a=p.author(i);
        strcpy(author, last);
        strcat(author,",");
        strcat(author,a.first());
        strcat(author,a.middle());
        doc->add( *_CLNEW Field(_T("author"), author, Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    }
    return;
}

void Indexer::addDate(Document* doc,Page p){
    //char* date;
    //TODO implement date conversion from three ints to a formatted string
    cerr <<"addDate Unimplemented."
    //doc->add( *_CLNEW Field(_T("date"), date, Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    return;
}

void Indexer::addFragments(Document* doc,Page p){
    for (int i=0; p.fragment_size(); i++) {
        doc->add( *_CLNEW Field(_T("fragments"), p.Fragment(i).text(), Field::STORE_YES | Field::INDEX_UNTOKENIZED ) );
    }
}

void Indexer::writeDocs(IndexWriter* writer, const char* directory) {
    vector<string> files;
    std::sort(files.begin(),files.end());
    Misc::listFiles(directory,files,true);
    vector<string>::iterator itr = files.begin();
    
    // Re-use the document object
    //TODO: make sure this works properly
    Document doc;
    int i=0;
    while ( itr != files.end() ){
        const char* path = itr->c_str();
        //printf( "adding file %d: %s\n", ++i, path );
        doc.clear();
        fileDocumentGenerator(&doc,path);
        writer->addDocument( &doc );
        ++itr;
    }
    return void;
}

void Indexer::indexFiles(const char* path, const char* target, const bool clearIndex){
	if ( !clearIndex && IndexReader::indexExists(target) ){
		if ( IndexReader::isLocked(target) ){
			printf("Index was locked... unlocking it.\n");
			IndexReader::unlock(target);
		}
        
		writer = _CLNEW IndexWriter( target, &an, false);
	}else{
		writer = _CLNEW IndexWriter( target ,&an, true);
	}
    writer->setRAMBufferSizeMB(256d);
    writer->setMaxBufferedDocs(50);
    writer->setMaxBufferedDocs(IndexWriter.DISABLE_AUTO_FLUSH);
    writer->setMaxFieldLength(0x7FFFFFFFL); // LUCENE_INT32_MAX_SHOULDBE
    writer->setUseCompoundFile(false);
	uint64_t str = Misc::currentTimeMillis();
	writeDocs(writer, path);
    writer->setUseCompoundFile(true);
    writer->optimize();
    writer->close();
	_CLLDELETE(writer);
	printf("Indexing took: %d ms.\n\n", (int32_t)(Misc::currentTimeMillis() - str));
    return void;
}

