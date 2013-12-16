#pragma once
class Edge
{
	int vertexOne;
	int vertexTwo;
	double weight;
public:
	Edge(int vertexOne, int vertexTwo, double weight)
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

	double getWeight()
	{
		return weight;
	}
};

