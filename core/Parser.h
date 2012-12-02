/*
Crawler with allowed and restricted domains and url cleaning
Parser Class for url cleaning and domain parsing
Maggie Wanek 2012
*/
#ifndef _URLPARSER_
#define _URLPARSER_

#include <iostream>
#include "QueueNode.h"
#include <string>
using namespace std;

class urlParser
{
	public:
	bool isSecure(char * c);
	bool hasHTTP(char * c);
	bool hasWWW(char * c);
	bool isFile(char * c);
	char* stringToChar(string s);
	bool isDirectoryFile(char * c);
	// passed whatever is in an anchor tag and file it's in
	bool lastCharIsSet(string s);
	char* cleanUrl(char * anchorLink, char * sourcePage);
	// passing an already clean link to parse the domain out of it
	char* getDomain(char * link);
};

#endif
