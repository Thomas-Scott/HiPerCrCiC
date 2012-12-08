/*
Crawler with allowed and restricted domains and url cleaning
Linked list class for queues
Maggie Wanek 2012
*/
#ifndef _QUEUENODE_
#define _QUEUENODE_

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class QueueNode
{
	public:
	char * url;
	QueueNode * next;
	void enqueue(char * c);
	void dequeue();
	void printQueue();
	int size();
	QueueNode& operator[](int i);
	QueueNode()
	{
		url = 0;
		next = 0;
	}
	QueueNode(char * c)
	{
		url = new char[(strlen(c))+1];
		strcpy(url, c);
		next = 0;
	}
};

#endif
