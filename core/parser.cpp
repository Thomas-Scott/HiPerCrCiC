#include <iostream>
#include "Qlist.h"
using namespace std;

class urlParser
{
	public:
	bool isSecure(char * c);
	bool hasHTTP(char * c);
	bool hasWWW(char * c);
	// passed whatever is in an anchor tag and file it's in
	char* cleanUrl(char * anchorLink, char * sourcePage);
	// passing an already clean link to parse the domain out of it
	char* getDomain(char * link);
};
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
	temp = c; 
	temp[4] = '\0';
	if(strcmp(temp, "http") == 0)
		return true;
	else
		return false;
}
bool urlParser::hasWWW(char * c)
{
	char * temp;
	cout << c << endl;
	temp = new char[3];
	temp = c;
	cout << c << endl;
	cout << c[4] << endl;
	if(hasHTTP(c))
		temp+=7;
	if(isSecure(c))
		temp+=1;
	if(hasHTTP(c))
		cout << "Has http" << endl;
	if(isSecure(c))
		cout << "is secure" << endl;
	temp[3] = '\0';
	if(strcmp(temp,"www") == 0)
		return true;
	else
		return false;
}
int main()
{
	urlParser parser;
	char * test = "https://www.google.com/";
	if(parser.hasWWW(test))
	{
		cout << "true" << endl;	
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}
