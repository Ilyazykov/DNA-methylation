#pragma once
class Edge
{
	int vertexOne;
	int vertexTwo;
	double weight;
public:
	Edge(int vertexOne = -1, int vertexTwo = -1, double weight = -1);

	Edge(const Edge& e);

	double getWeight();

	double getVertexOne();

	double getVertexTwo();

	~Edge() {}
};

