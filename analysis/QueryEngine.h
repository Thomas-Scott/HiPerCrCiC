//
//  QueryEngine.h
//  
//
//  Created by Thomas Scott on 11/18/12.
//
//

#ifndef ____QueryEngine__
#define ____QueryEngine__

#include "HardCoded.h"

#include <iostream>
#include <stdio.h>
#include <CLucene/StdHeader.h>
#include <CLucene/clucene-config.h>
#include <CLucene.h>
#include <CLucene/config/repl_tchar.h>
#include <CLucene/config/repl_wchar.h>
#include <CLucene/util/Misc.h>
//#include "stdafx.h"

#include <CLucene.h>
#include <iostream>

using namespace std;
using namespace lucene::analysis;
using namespace lucene::index;
using namespace lucene::util;
using namespace lucene::queryParser;
using namespace lucene::document;
using namespace lucene::search;


class QueryEngine{
    IndexReader* reader;
    lucene::analysis::standard::StandardAnalyzer analyzer;//("stopWords.txt",NULL);
    const TCHAR* buffer;
    TCHAR tline[80];
    void verifyReader();
    void setUpQuery(char *);
    void runFuzzyQuery(char *);
    Hits* hits;
    void runLuceneQuery(char* tmp);
    uint64_t endSearch;
public:
    void loadIndex(const char* index);
    void execute();
    void getResults();
    void clean();
    //TODO: flesh out QueryEngine - look into different kinds of analyzers
};

#endif /* defined(____QueryEngine__) */
