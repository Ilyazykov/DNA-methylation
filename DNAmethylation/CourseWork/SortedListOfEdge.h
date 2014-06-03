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

		myList(Edge e, myList *n = NULL);
	};

	myList *begin;
	int lenght;
	int maxLenght;
	int numberOfNodes;

public:
	SortedListOfEdge(int numberOfNodes, int maxLenght);

	SortedListOfEdge(const SortedListOfEdge& secondList);

	int getMaxVertex() const;

	double getEfficiency() const;

	Edge Pop();

	void Push(Edge edge);

	int getLenght();

	~SortedListOfEdge();
};

