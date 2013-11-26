#pragma once

class Graph
{
public:
	virtual ~Graph(void) {}
	virtual void AddArc(int from, int to) = 0;
	virtual bool HasArc(int from, int to) const = 0;
	virtual int CountVertex() const = 0;
};

