#pragma once
#include "SortedListOfEdge.h"
#include "Human.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Graphs
{
	vector<SortedListOfEdge> graphs;
public:
	Graphs(vector<SortedListOfEdge> graphs);

	~Graphs(void);

	void outGraphs(vector<bool> isSick, string pathOut );

	vector<double> getEfficiencies() const;

	vector<double> getMaxVertexes() const;
};

