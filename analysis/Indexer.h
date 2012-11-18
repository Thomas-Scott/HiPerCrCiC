//
//  Indexer.h
//  
//
//  Created by Thomas Scott on 11/18/12.
//
//

#ifndef ____Indexer__
#define ____Indexer__

#include <iostream>
#include <stdio.h>
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

using namespace std;
using namespace lucene::index;
using namespace lucene::analysis;
using namespace lucene::util;
using namespace lucene::store;
using namespace lucene::document;

class Indexer{
    IndexWriter* writer = NULL;
    lucene::analysis::standard::StandardAnalyzer an("stopWords.txt",NULL);
    void writeDocs(IndexWriter* writer, const char* directory);
    void addFragments(Document* doc,Page p);
    void addDate(Document* doc,Page p);
    void addAuthor(Document* doc, Page p);
    void addTitle(Document* doc,Page p);
    void addURI(Document* doc,Page p);
    void fileDocumentGenerator(Document* doc,path);
public:
    void indexFiles(const char* path, const char* target, const bool clearIndex);
    
}
#endif /* defined(____Indexer__) */
