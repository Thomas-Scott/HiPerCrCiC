//thomas leave my crap alone!! I like things in one file while I work, will split up later. <3

/* 
allowed
blacklisted
crawl
*/
#define CURL_STATICLIB
#include <stdio.h>
//#include <curl/curl.h>
//#include <curl/easy.h>
#include <iostream>
#include <string>
#include <fstream>
#include "QueueNode.h"
#include "Parser.h"

#pragma comment(lib, "urlmon.lib")
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
	size_t write_data(void * ptr, size_t size, size_t nmemb, FILE *stream);
	void download(char * webAddress, char * fileName);
	void check(char * fileName, char * sourceURL);
	void crawl(char * start, double max);
	bool notBlacklisted(char * c);
	bool allowed(char * c);
};
double Crawler::getPageCount()
{
	return maxPageCount;
}
void Crawler::setPageCount(double d)
{
	maxPageCount = d;
}
char* Crawler::getStartUrl()
{
	return startUrl;
}
void Crawler::setStartUrl(char * c)
{
	int length = 0;
	startUrl = new char[strlen(c)+1];
	strcpy(startUrl,c);
	queue.url = new char[strlen(c)+1];
	strcpy(queue.url,startUrl);
}
size_t Crawler::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
/*
void Crawler::download(char * webAddress, char * fileName)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = new char[strlen(webAddress)+1];
    strcpy(url, webAddress);
    char *outfilename[FILENAME_MAX];
    strcpy(outfilename,fileName);
    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}
*/
void Crawler::addBlacklist(char * c)
{
	char * newBlacklisted;
	newBlacklisted = new char[(strlen(c))+1];
	strcpy(newBlacklisted, c);
	blacklistedDomains.enqueue(newBlacklisted);
}
void Crawler::addAllowed(char * c)
{
	char * newAllowed;
	newAllowed = new char[(strlen(c))+1];
	strcpy(newAllowed,c);
	allowedDomains.enqueue(newAllowed);
}
QueueNode Crawler::getBlacklisted()
{
	return blacklistedDomains;
}
QueueNode Crawler::getAllowed()
{
	return allowedDomains;
}
bool Crawler::notBlacklisted(char * c)
{
/*	if(blacklistedDomains.size() > 0)
		for(int i = 0; i < blacklistedDomains.size(); i++)
		{
			if(!strcmp(c,blacklistedDomains[i]))
				return false;
		}
*/	return true;
}
bool Crawler::allowed(char * c)
{
/*	string arg = c;
	if(allowedDomains.size() > 0)
	{	
		for(int i = 0; i < allowedDomains.size(); i++)
		{
			string current = allowedDomains[i];
			if(arg.find(current) != string::npos)
				return true;
		}
		return false;
	}
	else */
		return true;
}
void Crawler::check(char * fileName, char * sourceURL)
{
	fstream f(fileName, fstream::in );
  	string content;
  	getline( f, content, '\0');
	f.close();
	string search = "<a ";
	int contentLocation = 0;
	while(true)
	{
		bool duplicate = false;
		int startpos = content.find(search,contentLocation);
		if(startpos <= 0)
			break;
		int startpos2 = content.find("\"",startpos);
		startpos2++;
		int endpos = content.find("\"",startpos2);
		string hreftag = content.substr(startpos2, (endpos-startpos2));
		char * url;
		url = new char[hreftag.size()+1];
		for(int i = 0; i < hreftag.size()+1; i++)
		{
			url[i] = hreftag[i];
		}
		url[hreftag.size()+1] = '\0';
		contentLocation = endpos;
		for(int s = 0; s < queue.size(); s++)
		{
			if(strcmp(queue[s].url,url) == 0)
			{
				duplicate = true;
				break;
			}
		}
		if(!duplicate)
		{
			for(int b = 0; b < doneQueue.size(); b++)
			{
				if(strcmp(queue[b].url,url) == 0)
				{
					duplicate = true;
					break;
				}
			}
		}
		if(!duplicate)
		{
			if(notBlacklisted(url) && allowed(url))
			{
				// make parser and parse url to see if it's got a domain and stuff
				urlParser parser;
				char * cleanedURL = parser.cleanUrl(url,sourceURL);
				queue.enqueue(cleanedURL);
			}
		}
	}
}
void Crawler::crawl(char * start, double max = 1000)
{
/*	setStartUrl(start);
	// insert set blacklist and allowed here
	double currentCount = 0;
	maxPageCount = max;
	// download the start, and check it 
	download(startUrl, "startPage.html");
	doneQueue.enqueue(startUrl);
	check("startPage.html",startUrl);
	queue.dequeue();
	currentCount++;
	while(pageCount <= maxPageCount && queue.size() < 0)
	{
		string currentTitle = "";
		currentTitle.append((string)currentCount);
		currentTitle.append(".html");
		urlParser p;
		char * title = p.stringToChar(currentTitle);
		download(queue[0].url, title);
		check(title, queue[0].url);
		doneQueue.enqueue(queue[0].url);
		queue.dequeue();
	}
*/
}

int main()
{
	//Crawler sharp;
	//sharp.setStartUrl("http://www.wanek.com/");
	//sharp.check("tester.txt");
	//sharp.queue.printQueue();
}
