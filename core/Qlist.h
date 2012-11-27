// linked lists as queue substitute for vectors 
#ifndef _QNODE_
#define _QNODE_

#include <iostream>
using namespace std;

class Qnode
{
	public:
	char * url;
	Qnode * next;
	void add(char * c);
	void pop();
	void printQlist();
	int size();
	Qnode& operator[](int i);
	Qnode()
	{
		url = 0;
		next = 0;
	}
	Qnode(char * c)
	{
		url = new char[(strlen(c))+1];
		strcpy(url, c);
		next = 0;
	}
};

#endif
