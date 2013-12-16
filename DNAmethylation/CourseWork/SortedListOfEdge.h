#pragma once
#include <iostream>
#include "Edge.h"
using namespace std;

class myList
{
public:
	Edge edge;
	myList *next;

	myList();
};

class SortedListOfEdge
{
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

	void Push(Edge edge)
	{
		if (lenght+1 != maxLenght) lenght++;
		//TODO в начало наибольшие, чтобы их удалять

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
			if (lenght+1 == maxLenght) return;
			myList *list = new myList();
			list->edge = edge;
			begin = list;
			list->next = next;
		}
		else
		{
			myList *list = new myList();
			list->edge = edge;
			list->next = next;
			prev->next = list;
		}

		if (lenght+1 != maxLenght) lenght++;
		else {
			myList *temp = begin;
			begin = begin->next;
			delete temp;
		}
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

