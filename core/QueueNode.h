// linked lists as queue substitute for vectors 
#ifndef _QUEUENODE_
#define _QUEUENODE_

#include <iostream>
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
