/*
Crawler with allowed and restricted domains and url cleaning
Main crawling class
Maggie Wanek 2012
*/
#define CURL_STATICLIB
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "QueueNode.h"
#include "Parser.h"
#include "Crawler.h"
#include "../UI/GlobalState.h"
#include "JobInfo.h"

using namespace std;

Crawler::Crawler()
{
	currentJob = 0;
}

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
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
void Crawler::download(char * webAddress, char * fileName)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = new char[strlen(webAddress)+1];
    strcpy(url, webAddress);
    char outfilename[FILENAME_MAX];
    strcpy(outfilename,fileName);
    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, webAddress);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    cout << webAddress << endl;
}
void Crawler::addBlacklist(char * c)
{
	if(blacklistedDomains.url == 0)
	{
		blacklistedDomains.url = new char[strlen(c)+1];
		strcpy(blacklistedDomains.url, c);
	}
	else
		blacklistedDomains.enqueue(c);
}
void Crawler::addAllowed(char * c)
{
	if(allowedDomains.url == 0)
	{
		allowedDomains.url = new char[strlen(c)+1];
		strcpy(allowedDomains.url, c);
	}
	else
		allowedDomains.enqueue(c);

}
QueueNode Crawler::getBlacklisted()
{
	return blacklistedDomains;
}
QueueNode Crawler::getAllowed()
{
	return allowedDomains;
}
bool Crawler::blacklisted(char * c)
{
	if(blacklistedDomains.size() > 0)
		for(int i = 0; i < blacklistedDomains.size(); i++)
		{
			string temp = "";
			temp.append(c);
			string temp2 = "";
			temp2.append(blacklistedDomains[i].url);
			if(temp.find(temp2) !=  -1)
				return true;
		}
	return false;
}
bool Crawler::allowed(char * c)
{
	if(allowedDomains.size() > 0)
	{
		for(int i = 0; i < allowedDomains.size(); i++)
		{
			string temp = "";
			temp.append(c);
			string temp2 = "";
			temp2.append(allowedDomains[i].url);
			if(temp.find(temp2) !=  -1)
				return true;
		}
		return false;
	}
	else 
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
		for(int i = 0; i < hreftag.size(); i++)
		{
			url[i] = hreftag[i];
		}
		url[hreftag.size()] = '\0';
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
			// make parser and parse url and then test if it's blacklisted
			urlParser parser;
			char * cleanedURL = parser.cleanUrl(url,sourceURL);
			if(!(blacklisted(cleanedURL)) && allowed(cleanedURL))
			{
				queue.enqueue(cleanedURL);
			}
		}
	}
}
string Crawler::convertDouble(double number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void Crawler::crawl(JobInfo * job)
{
	string startPage = job->getStartPage();
	char * startPageCS = new char[startPage.length()+1];
  for (int i = 0; i<startPage.length();++i)
  {
    startPageCS[i] = startPage[i];
  }
  startPageCS[startPage.length()] = '\0';
  currentJob = job;
  job->setStatus(RUNNING);
  crawl(startPageCS, job->getMaxPages());
}

void Crawler::crawl(char * start, double max = 1000)
{

	setStartUrl(start);
	double currentCount = 0;
	maxPageCount = max;
	// copy blacklisted domains from b in
	/* 
	blacklistedDomains.url = new char[strlen(b.url)+1];
	strcpy(blacklistedDomains.url, b.url);
	for(int i = 1; i < b.size(); i++)
		blacklistedDomains.enqueue(b[i].url);
	// copy allowed domains from b in
	allowedDomains.url = new char[strlen(a.url)+1];
	strcpy(allowedDomains.url, a.url);
	for(int i = 1; i < a.size(); i++)
		allowedDomains.enqueue(a[i].url);
	// download the start, and check it 
	*/
	download(startUrl, "startPage.html");
	doneQueue.enqueue(startUrl);
	check("startPage.html",startUrl);
	queue.dequeue();
	currentCount++;
	while(currentCount <= maxPageCount)
	{
		string currentTitle = "";
		currentTitle.append(convertDouble(currentCount));
		currentTitle.append(".html");
		urlParser p;
		char * title = p.stringToChar(currentTitle);
		char * currentDownload = new char[strlen(queue[0].url) + 1];
		strcpy(currentDownload,queue[0].url);

		stringstream output1;
		output1 << "title: " << title << " currentDownload: " << currentDownload << endl;		
		
		
		download(currentDownload, title);
		check(title, currentDownload);

		stringstream output2;
		output2 << "checking: " << title << endl;

		// Update the data in the JobInfo object
		currentJob->setPagesCrawled(currentCount);
		GlobalState::eventDisp->pushCrawlerEvent(CrawlerEvent(CRAWLER_UPDATE));

		doneQueue.enqueue(queue[0].url);
		queue.dequeue();
		currentCount++;
	}
	currentJob->setStatus(COMPLETE);
	GlobalState::eventDisp->pushCrawlerEvent(CrawlerEvent(CRAWLER_UPDATE));
}

