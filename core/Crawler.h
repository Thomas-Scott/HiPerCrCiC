#ifndef _CRAWLER_
#define _CRAWLER_

#include <iostream>
#include <urlmon.h>
#include <vector>
#include <fstream>
#pragma comment(lib, "urlmon.lib")


class Crawler
{
public:
        char * startUrl;
        vector<char*> queue;
        vector<char*> doneQueue;
        vector<char*> content;
        vector<char*> blacklistedDomains;
        vector<char*> allowedDomains;
        double maxPageCount;
        // getting and setting functions
        double getPageCount();
        void setPageCount(double d);
        char* getStartUrl();
        void setStartUrl(char * c);
        void addBlacklist(char * c);
        void addAllowed(char * c);
        vector<char*>& getBlacklisted();
        vector<char*>& getAllowed();
        // crawling functions
        void download(char * c);
        void check(char * c);
        void crawl(char * start, vector<char*> blacklist, vector<char*> allowed, double max);
        bool notBlacklisted(char * c);
        bool allowed(char * c);
};

#endif //_CRAWLER_
