#pragma once
class Edge
{
	int vertexOne;
	int vertexTwo;
	double weight;
public:
	Edge(int vertexOne = -1, int vertexTwo = -1, double weight = -1)
	{
		if (vertexOne > vertexTwo) 
		{
			this->vertexOne = vertexTwo;
			this->vertexTwo = vertexOne;
		}
		else
		{
			this->vertexOne = vertexOne;
			this->vertexTwo = vertexTwo;
		}
		this->weight = weight;
	}

	Edge(const Edge& e)
	{
		this->vertexOne = e.vertexOne;
		this->vertexTwo = e.vertexTwo;
		this->weight = e.weight;
	}

	double getWeight()
	{
		return weight;
	}

	double getVertexOne()
	{
		return vertexOne;
	}

	double getVertexTwo()
	{
		return vertexTwo;
	}

	~Edge() {}
};

