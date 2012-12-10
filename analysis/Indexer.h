//
//  Indexer2.0.h
//  HiPerCrCic
//
//  Created by Thomas Scott on 12/1/12.
//
//

#ifndef __HiPerCrCic__Indexer__
#define __HiPerCrCic__Indexer__

//#include "stdafx.h"
#include "HardCoded.h"

#include <CLucene.h>
#include <CLucene/util/Reader.h>
#include <CLucene/util/Misc.h>
#include <CLucene/util/dirent.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace lucene::index;
using namespace lucene::analysis;
using namespace lucene::util;
using namespace lucene::store;
using namespace lucene::document;
#include <iostream>
#include <stdio.h>
#include <CLucene/StdHeader.h>
#include "CLucene/clucene-config.h"
#include <CLucene/config/repl_tchar.h>
#include <CLucene/config/repl_wchar.h>

#include "HardCoded.h"


class Indexer{
    IndexWriter* writer;
    uint64_t elapsed;
    char* path;
    char* target;
    bool clearIndex;
    lucene::analysis::standard::StandardAnalyzer an;//("stopWords.txt",NULL);
    void verifyIndex(char* target,bool clearIndex);
    void setUpWriter();
    Document* FileDocument(const char* path);
    void indexDocs(IndexWriter* writer, char* directory);
    void init(char* p, char* t, bool cI);
public:
    void execute();
    Indexer(char* path, char* target, bool clearIndex);
};


#endif /* defined(__HiPerCrCic__Indexer__) */
