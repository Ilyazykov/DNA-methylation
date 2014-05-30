#pragma once
#include <iostream>
#include <map>
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
	int numberOfNodes;

public:
	SortedListOfEdge(int numberOfNodes, int maxLenght)
	{
		begin = NULL;
		lenght = 0;
		this->numberOfNodes = numberOfNodes;
		this->maxLenght = maxLenght;
	}

	SortedListOfEdge(const SortedListOfEdge& secondList)
	{
		lenght = secondList.lenght;
		maxLenght = secondList.maxLenght;
		numberOfNodes = secondList.numberOfNodes;

		if (secondList.begin == NULL)
		{
			begin = NULL;
			return;
		}

		begin = new myList(secondList.begin->edge, NULL);

		myList *SecondNext = secondList.begin->next;
		myList *curr = begin;

		while (SecondNext != NULL)
		{
			myList *list = new myList(SecondNext->edge, NULL);

			curr->next = list;
			curr = curr->next;
			
			SecondNext = SecondNext->next;
		}
	}

	int getMaxVertex()
	{
		map<int, int> vertexes;

		myList *next = begin;
		while (next != NULL)
		{
			vertexes[next->edge.getVertexOne()]++;
			vertexes[next->edge.getVertexTwo()]++;

			next = next->next;
		}

		int max = 0;
		map<int,int>::iterator iter;
		for (iter=vertexes.begin(); iter!=vertexes.end(); ++iter)
		{
			if ((*iter).second > max)
			{
				max = (*iter).second;
			}
		}
		return max;
	}

	double getEfficiency()
	{
		double sum = 0;

		myList *next = begin;
		while (next != NULL)
		{
			sum += 1/(next->edge.getWeight());
			next = next->next;
		}

		double res = sum/(numberOfNodes*(numberOfNodes-1));
		return res;
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
		myList *next = begin;
		myList *prev = NULL;

		while (next != NULL)
		{
			if (next->edge.getWeight() > edge.getWeight()) break; 
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

