#pragma once
#include <iostream>
#include "Edge.h"
using namespace std;

class SortedListOfEdge
{
private:
	struct myList {
		Edge edge;
		myList *next;

		myList(Edge e, myList *n = NULL)
		{
			edge = e;
			next = n;
		}
	};

	myList *begin;
	int lenght;
	int maxLenght;
public:
	SortedListOfEdge(int maxLenght = 500)
	{
		begin = NULL;
		lenght = 0;
		this->maxLenght = maxLenght;
	}

	Edge Pop()
	{
		if (begin == NULL) return Edge(-1,-1,-1);

		myList *temp = begin;

		Edge res = temp->edge;
		begin = begin->next;
		delete temp;

		lenght--;

		return res;
	}

	void Push(Edge edge)
	{
		//	//TODO в начало наибольшие, чтобы их удалять

		myList *next = begin;
		myList *prev = NULL;

		while (next != NULL)
		{
			if (next->edge.getWeight() < edge.getWeight()) break;
			prev = next;
			next = next->next;
		}

		if (prev==NULL) 
		{
			if (lenght == maxLenght) return;
			myList *list = new myList(edge, next);
			begin = list;
		}
		else
		{
			myList *list = new myList(edge, next);
			prev->next = list;
		}

		if (lenght != maxLenght) lenght++;
		else {
			myList *temp = begin;
			begin = begin->next;
			delete temp;
		}
	}

	int getLenght()
	{
		return lenght;
	}

	~SortedListOfEdge()
	{
		myList *iter = begin;

		while (iter != NULL)
		{
			myList *temp = iter;
			iter = iter->next;

			delete temp;
		}
	}
};

