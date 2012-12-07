/*
Crawler with allowed and restricted domains and url cleaning
Main crawling class
Maggie Wanek 2012
*/
#ifndef _CRAWLER_
#define _CRAWLER_

#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "QueueNode.h"
#include "Parser.h"
#include "JobInfo.h"

using namespace std;

class Crawler
{
public:
	char* startUrl;
	QueueNode queue;
	QueueNode doneQueue;
	QueueNode content;
	QueueNode blacklistedDomains;
	QueueNode allowedDomains;
	double maxPageCount;
	JobInfo * currentJob;

	Crawler();
	// getting and setting functions
	double getPageCount();
	void setPageCount(double d);
	char* getStartUrl();
	void setStartUrl(char * c);
	void addBlacklist(char * c);
	void addAllowed(char * c);
	QueueNode getBlacklisted();
	QueueNode getAllowed();
	// crawling functions
	void download(char * webAddress, char * fileName);
	void check(char * fileName, char * sourceURL);
	string convertDouble(double number);
<<<<<<< HEAD
	void crawl(char * start, char** a, char** b, double max);
=======
	void crawl(JobInfo * job);
	void crawl(char * start, double max);
>>>>>>> ui-dev
	bool blacklisted(char * c);
	bool allowed(char * c);
};
#endif
