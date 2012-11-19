//
//  QueryEngine.cpp
//  
//
//  Created by Thomas Scott on 11/18/12.
//
//

#include "QueryEngine.h"
#include <iostream>
#include <stdio.h>
#include "CLucene/StdHeader.h"
#include "CLucene/_clucene-config.h"
#include "CLucene.h"
#include "CLucene/config/repl_tchar.h"
#include "CLucene/config/repl_wchar.h"
#include "CLucene/util/Misc.h"

using namespace std;
using namespace lucene::analysis;
using namespace lucene::index;
using namespace lucene::util;
using namespace lucene::queryParser;
using namespace lucene::document;
using namespace lucene::search;

void QueryEngine::loadIndex(const char* index){
    reader = IndexReader::open(index);
    return;
}

bool QueryEngine::verifyReader(){
    IndexReader* newreader = reader->reopen();
    if ( newreader != reader ){
        _CLLDELETE(reader);
        reader = newreader;
    }
    
}
void QueryEngine::setUpQuery(char*tmp){
    //TODO: take input from UI and set as query term
    TCHAR tline[80];
    STRCPY_AtoT(tline,tmp,80);
    term=Term(FRAGMENTS,tline,);
    
}

void QueryEngine::runQuery(char* tmp){
    //TODO: make this work, possibly different kind of Query
    //TODO: return values that can have stuff done to them from query.
    setUpQuery(tmp);
    verifyReader();
    IndexSearcher s(reader);
    if ( tmp[0] == '\0' ) break;
    FuzzyQuery* q = FuzzyQuery(,float_t minimumSimilarity=0.9,)&analyzer);
}
