#include <iostream>
#include "Qlist.h"
using namespace std;

void Qnode::add(char * c)
{
	Qnode * n = this;
	Qnode * newQnode = new Qnode(c);
	while(n->next != 0) 
	{
		n = n->next;
	}
	n->next = newQnode;
}

void Qnode::pop()
{
	Qnode * temp = next;
	delete [] url;
	url = new char [strlen(next->url)+1];
	strcpy(url,next->url); 
	next = temp->next;
}
int Qnode::size()
{
	Qnode * n = this;
	int length = 0;
	while(n->next != 0)
	{
		length++;
		n = n->next;
	}
	length++;
	return length;
}

void Qnode::printQlist()
{
	Qnode * n = this;
	while(n->next != 0)
	{
		cout << n->url << endl;
		n = n->next;
	}
	cout << n->url << endl;
}

Qnode& Qnode::operator[](int i)
{
	Qnode * n = this;
	for(int s = 0; s < i; s++)
	{
		n = n->next;
	}
	return * n;
}
