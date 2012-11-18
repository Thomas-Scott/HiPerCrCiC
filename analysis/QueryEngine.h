//
//  QueryEngine.h
//  
//
//  Created by Thomas Scott on 11/18/12.
//
//

#ifndef ____QueryEngine__
#define ____QueryEngine__

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
class QueryEngine{
    IndexReader* reader;
    Term term;
    bool verifyReader();
public:
    void loadIndex(const char* index);
    void runQuery(char* tmp);
}

#endif /* defined(____QueryEngine__) */
