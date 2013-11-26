#pragma once
#include "graph.h"
#include <list>
using namespace std;

class ListGraph : public Graph
{
private:
	list<int> *graph;
	int vertexNumber;

public:
	ListGraph(int n) : vertexNumber(n), graph(new list<int>(n)) {}
	
	~ListGraph(void) {
		delete graph;
	}

	int CountVertex() const {
		return vertexNumber;
	}

	void AddArc(int from, int to) {
		if (from<0 || from>=vertexNumber || to<0 || to>=vertexNumber)
			return;
		graph[from].push_back(to);
	}

	bool HasArc(int from, int to) const {
		if (from<0 || from>=vertexNumber || to<0 || to>=vertexNumber)
			return false;
		
		list<int>::iterator iter;
		for (iter = graph[from].begin(); iter!=graph[from].end(); ++iter)
		{
			if (*iter == to) return true; 
		}
		return false;
	}
};

