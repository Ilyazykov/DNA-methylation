#pragma once
#include "graph.h"
#include <vector>
#include <limits>
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
	
	vector<vector<double> > getShortcuts() const //Floyd–Warshall
	{
		vector<vector<double> > dist(matrix);
		
		for (int k = 0; k < vertexNumber; k++) {
			for (int i = 0; i < vertexNumber; i++) {
				for (int j = 0; j < vertexNumber; j++) {
					if (dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		return dist;
	}

	double getTopologicalMetrix()
	{
		vector<vector<double> > dist = getShortcuts();

		double sum = 0.0;

		for (int i = 0; i < vertexNumber; i++) {
			for (int j = 0; j < vertexNumber; j++) {
				if (dist[i][j] < numeric_limits<double>::infinity() ) {
					sum += dist[i][j];
				}
			}
		}
		return sum;
	}
};

