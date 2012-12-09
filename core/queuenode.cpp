/*
Crawler with allowed and restricted domains and url cleaning
Linked list class for queues
Maggie Wanek 2012
*/
#include <iostream>
#include <string>
#include <string.h>
#include "QueueNode.h"
using namespace std;

void QueueNode::enqueue(char * c)
{
	QueueNode * n = this;
	QueueNode * newQueueNode = new QueueNode(c);
	while(n->next != 0) 
	{
		n = n->next;
	}
	n->next = newQueueNode;
}

void QueueNode::dequeue()
{
	QueueNode * temp = next;
	delete [] url;
	if(next != 0)
		if(next->url != 0)
		{
			url = new char [strlen(next->url)+1];
			strcpy(url,next->url); 
			next = temp->next;
			return;
		}
	url = 0;
	next = 0;
}
int QueueNode::size()
{
	QueueNode * n = this;
	int length = 0;
	if(url == 0)
		return 0;
	while(n->next != 0)
	{
		if(url != 0)
			length++;
		n = n->next;
	}
	length++;
	return length;
}

void QueueNode::printQueue()
{
	QueueNode * n = this;
	while(n->next != 0)
	{
		cout << n->url << endl;
		n = n->next;
	}
	cout << n->url << endl;
}

QueueNode& QueueNode::operator[](int i)
{
	QueueNode * n = this;
	for(int s = 0; s < i; s++)
	{
		n = n->next;
	}
	return * n;
}
