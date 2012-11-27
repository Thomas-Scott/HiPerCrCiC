//thomas leave my crap alone!! I like things in one file while I work, will split up later. <3

/* 
parser
download
allowed
blacklisted
crawl
*/

#include <iostream>
#include <urlmon.h>
#include <fstream>
#include "Qlist.h"

#pragma comment(lib, "urlmon.lib")
using namespace std;

class Crawler
{
public:
	char * startUrl;
	Qnode queue;
	Qnode doneQueue;
	Qnode content;
	Qnode blacklistedDomains;
	Qnode allowedDomains;
	double maxPageCount;
	// getting and setting functions
	double getPageCount();
	void setPageCount(double d);
	char* getStartUrl();
	void setStartUrl(char * c);
	void addBlacklist(char * c);
	void addAllowed(char * c);
	Qnode getBlacklisted();
	Qnode getAllowed();
	// crawling functions
	void download(char * c);
	void check(char * c);
	void crawl(char * start, Qnode blacklist, Qnode allowed, double max);
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
void Crawler::download(char * webAddress)
{
/*
	int length = 0;
	while(webAddress[length] != '\0')
	{
		length++;
	}
	char szFileName[length+1];
	for(int i = 0; i < (length + 1);i++)
	{
		szFileName[i] = webAddress[i];
	}
	HRESULT hr = URLDownloadToFile(NULL,webAddress,szFileName,0,NULL);
	if(hr != S_OK)
	{
		cout << "Operation failed with error code:" << hr << "\n";
	}
*/
}
void Crawler::addBlacklist(char * c)
{
	char * newBlacklisted;
	newBlacklisted = new char[(strlen(c))+1];
	strcpy(newBlacklisted, c);
	blacklistedDomains.add(newBlacklisted);
}
void Crawler::addAllowed(char * c)
{
	char * newAllowed;
	newAllowed = new char[(strlen(c))+1];
	strcpy(newAllowed,c);
	allowedDomains.add(newAllowed);
}
Qnode Crawler::getBlacklisted()
{
	return blacklistedDomains;
}
Qnode Crawler::getAllowed()
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
void Crawler::check(char * fileName)
{
	fstream f(fileName, fstream::in );
  	string content;
  	getline( f, content, '\0');
	f.close();
	string search = "<a ";
	int contentLocation = 0;
	while(true)
	{
		boolean duplicate = false;
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
				queue.add(url);
			}
		}
	}
}
void Crawler::crawl(char * start, Qnode blacklist, Qnode allowed, double max = 1000)
{
	setStartUrl(start);
	// set blacklist and allowed
	maxPageCount = max;
	download(startUrl);
	doneQueue.add(startUrl);
	queue.pop();
	double pageCount = 1;
	while(pageCount <= maxPageCount)
	{
		download(queue[0].url);
		check(queue[0].url);
		doneQueue.add(queue[0].url);
		queue.pop();
	}
}
int main()
{
	Crawler sharp;
	sharp.setStartUrl("google.com");
	sharp.check("tester.txt");
	sharp.queue.printQlist();
}
