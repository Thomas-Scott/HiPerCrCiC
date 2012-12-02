#include <iostream>
#include "QueueNode.h"
#include "Parser.h"
#include <string>
using namespace std;

bool urlParser::isSecure(char * c)
{
	if(c[4] == 's' && hasHTTP(c))
		return true;
	else
		return false;
}
bool urlParser::hasHTTP(char * c)
{
	char * temp;
	temp = new char[4];
	for(int i = 0; i < 4; i++)
		temp[i] = c[i]; 
	temp[4] = '\0';
	if(strcmp(temp, "http") == 0)
		return true;
	else
		return false;
}
bool urlParser::hasWWW(char * c)
{
	char * temp;
	temp = new char[3];
	int i = 0;
	if(hasHTTP(c))
		i+=7;
	if(isSecure(c))
		i+=1;
	int t = 0;
	while(t < 3)
	{
		temp[t] = c[i];
		i++;
		t++;
	}
	temp[3] = '\0';
	if(strcmp(temp,"www") == 0)
		return true;
	else
		return false;
}
bool urlParser::isDirectoryFile(char * c)
{
	if(c[0] == '/')
		return true;
	else
		return false;
	// test to see if first character is a / indicating a directory change and then a file
}
bool urlParser::isFile(char * c)
{
	// if it's got no slashes in it, and the characters after the last dot are valid page endings
}
char* urlParser::stringToChar(string s)
{
	char * result;
	result = new char[(s.size()+1)];
	for(int i = 0; i < s.size(); i++)
	{
		result[i] = s[i];
	}
	result[s.size()] = '\0';
	return result;
}
char* urlParser::cleanUrl(char * anchorLink, char * sourcePage)
{
	string cleanstring = "";
	char * cleanedURL;
	// if directoryFile add to end of source page url and return it
	if(isDirectoryFile(anchorLink))
	{
		cleanstring.append(sourcePage);
		if(*(cleanstring.end()-1) == '/')
			cleanstring.erase((cleanstring.size()-1),1);
		cleanstring.append(anchorLink);
		char * temp = stringToChar(cleanstring);
		cleanedURL = new char[strlen(temp) + 1];
		strcpy(cleanedURL,temp);
		return cleanedURL;
	}
	// if file add / and then link to end of source page and return it
	// if has http && www return it 
	if(hasHTTP(anchorLink) && hasWWW(anchorLink))
	{
		cleanedURL = new char[strlen(anchorLink)+1];
		strcpy(cleanedURL,anchorLink);
		return cleanedURL;
	}
	// if has http && not www, check if secure and add www and return it
	if(hasHTTP(anchorLink) && !hasWWW(anchorLink))
	{
		cleanstring.append(anchorLink);
		int position = 7;
		if(isSecure(anchorLink))
		{
			position++;
		}
		cleanstring.insert(position,"www.");
		cleanedURL = stringToChar(cleanstring);
		return cleanedURL;
	}
	// if has www and not http, add http and return it
	if(!hasHTTP(anchorLink) && hasWWW(anchorLink))
	{
		cleanstring.append(anchorLink);
		cleanstring.insert(0,"http://");
		cleanedURL = stringToChar(cleanstring);
		return cleanedURL;
	}
	cleanstring.append(anchorLink);
	// if does not have http or www, add both but not secure
	if(!hasHTTP(anchorLink) && !hasWWW(anchorLink) && cleanstring.find('/') == string::npos)
	{
		if(sourcePage[strlen(sourcePage)-1] != '/')
			cleanstring.insert(0,"/");
		cleanstring.insert(0,sourcePage);
		cleanedURL = stringToChar(cleanstring);
		return cleanedURL;
	}
	else
		return anchorLink;
}
char* urlParser::getDomain(char * link)
{
	// assumes an already clean url
	// get and return substring between start and first slash that's not in http://
	string domain = "";
	domain.append(link);
	int endpos = (int)domain.find('/',8);
	string domain2 = domain.substr(0,(endpos+1));
	char * result = stringToChar(domain2);
	return result;
}
