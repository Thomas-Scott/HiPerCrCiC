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
#include <string.h>
#include <fstream>
#include <sstream>
#include "QueueNode.h"
#include "Parser.h"
#include "Crawler.h"
#include <sys/stat.h>
#include <sys/types.h>
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
void Crawler::parseRobots()
{
	urlParser p;
	string s = "";
	s.append(p.getDomain(startUrl));
	s.append("robots.txt");
	char * robotsAddr = p.stringToChar(s);
	download(robotsAddr, "robots.txt"); 
	fstream f("robots.txt", fstream::in );
  	string content;
  	getline( f, content, '\0');
	f.close();
	string search = "Disallow: ";
	int contentLocation = 0;
	while(true)
	{
		bool duplicate = false;
		int startpos = content.find(search,contentLocation);
		if(startpos <= 0)
			break;
		int startpos2 = content.find("/",startpos);
		int endpos = content.find("\n",startpos2);
		string directories = content.substr(startpos2, (endpos-startpos2));
		string s2 = "";
		if(p.getDomain(startUrl)[strlen(p.getDomain(startUrl))-1] == '/' && directories.at(0)== '/')
			directories.erase(0,1);
		s2.append(p.getDomain(startUrl)); 
		s2.append(directories);
		char * currentLink = p.stringToChar(s2);
		contentLocation = endpos;
		if(!(blacklisted(currentLink)))
		{
			addBlacklist(currentLink);
		}
	}
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
		char * anchor;
		anchor = new char[hreftag.size()+1];
		for(int i = 0; i < hreftag.size(); i++)
		{
			anchor[i] = hreftag[i];
		}
		anchor[hreftag.size()] = '\0';
		contentLocation = endpos;
		urlParser parser;
		char * url = parser.cleanUrl(anchor, sourceURL);
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
			if(!(blacklisted(url)) && allowed(url))
			{
				queue.enqueue(url);
			}
		}
	}
}
string Crawler::convertDouble(double number)
{
   stringstream ss; //create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
void Crawler::crawl(JobInfo * job)
{
	urlParser p;
	// directory name
	char * dirNameCS = p.stringToChar(job->getDownloadDir());
  	// set start page
 	char * startPageCS = p.stringToChar(job->getStartPage());
 	// set allowed and blacklisted

 	char ** a;
 	int alength = 0;
 	while((job->getAllowedPtr()[alength]) != 0)
 		alength++;
 	if(alength = 1 && (*(job->getAllowedPtr()[0])).length() == 0)
 	{
 		a = new char*[0];
 	}
 	else
 	{
 		a = new char*[alength+1];
	 	string ** sp;
 		sp = job->getAllowedPtr();
 		for(int s = 0; s < alength; s++)
 		{
 			string s2 = *(sp[s]);
 			a[s] = p.stringToChar(s2);
 		}
 		a[alength] = '\0';
 	}
 	char ** b;
 	int blength = 0;
 	while((job->getBlacklistedPtr()[blength]) != 0)
 		blength++;
 	if(blength = 1 && (*(job->getBlacklistedPtr()[0])).length() == 0)
 	{
 		b = new char*[0]; 
 	}
 	else
 	{
 		b = new char*[blength+1];
 		string ** sp2;
 		sp2 = job->getBlacklistedPtr();
 		for(int s = 0; s < blength; s++)
 		{	
 			string s2 = *(sp2[s]);
 			b[s] = p.stringToChar(s2);
 		}
 		b[blength] = '\0';
 	}
  	// set job to running
  	currentJob = job;
  	job->setStatus(RUNNING);
	crawl(dirNameCS, startPageCS, a, b, job->getMaxPages());
}
void Crawler::crawl(char * jobName, char * start, char** a, char** b, double max = 1000)
{
	urlParser p;
	if(mkdir(jobName,0777)==-1)//creating a directory
	{
        	cout << "mkdir fail";
    }
	setStartUrl(start);
	parseRobots();
	double currentCount = 0;
	maxPageCount = max;
	int i = 0;
	while(a[i] != '\0')
	{
		char * temp = a[i];
		addAllowed(temp);
		i++;
	}
	i = 0;
	while(b[i] != '\0')
	{
		char * temp = b[i];
		addBlacklist(temp);
		i++;
	}
	string startUrlDownload = "";
	startUrlDownload.append(jobName);
	startUrlDownload.append("/startPage.html");
	char * startTitle = p.stringToChar(startUrlDownload);
	download(startUrl, startTitle);
	doneQueue.enqueue(startUrl);
	check(startTitle,startUrl);
	queue.dequeue();
	currentCount++;
	while(currentCount <= maxPageCount)
	{
		string currentTitle = "";
		currentTitle.append(jobName);
		currentTitle.append("/");
		currentTitle.append(convertDouble(currentCount));
		currentTitle.append(".html");
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
