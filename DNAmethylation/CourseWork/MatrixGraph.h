#pragma once
#include "graph.h"
#include <vector>
using namespace std;

class MatrixGraph : public Graph
{
	vector<vector<double> > matrix;
	int vertexNumber;
public:
	MatrixGraph(int vertexNumber) 
	{
		this->vertexNumber = vertexNumber;

		matrix.resize(vertexNumber);
		for (int i = 0; i < vertexNumber; i++)
		{
			matrix[i].resize(vertexNumber);
		}
	}

	~MatrixGraph(void){}
	
	int CountVertex() const
	{
		return vertexNumber;
	}

	void AddArc(int from, int to, double value)
	{
		if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
			return;
		matrix[from][to] = value;
	}

	bool HasArc(int from, int to) const
	{
		if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
			return false;
		if (matrix[from][to] == 0) return false;
		return true;
	}
};

