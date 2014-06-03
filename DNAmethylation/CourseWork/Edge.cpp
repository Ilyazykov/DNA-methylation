#include "Edge.h"

Edge::Edge( int vertexOne /*= -1*/, int vertexTwo /*= -1*/, double weight /*= -1*/ )
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

Edge::Edge( const Edge& e )
{
	this->vertexOne = e.vertexOne;
	this->vertexTwo = e.vertexTwo;
	this->weight = e.weight;
}

double Edge::getWeight()
{
	return weight;
}

double Edge::getVertexOne()
{
	return vertexOne;
}

double Edge::getVertexTwo()
{
	return vertexTwo;
}
