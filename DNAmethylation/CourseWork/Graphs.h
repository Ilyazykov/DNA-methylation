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
	Graphs(vector<SortedListOfEdge> graphs)
	{
		this->graphs = graphs;
	}

	~Graphs(void)
	{
	}

	void outGraphs(vector<bool> isSick, string pathOut ) 
	{
		ofstream outGraph(pathOut.c_str());

		outGraph << "library(igraph, lib.loc=\"C:/Users/Ilya/Documents/RLibrary\")" << endl;
		outGraph << "setwd(\"C:/Users/user/Desktop\")" << endl;

		outGraph << "pdf(\"graphs.pdf\")" << endl;

		int numberOfHumans = graphs.size();
		for (int human = 0; human < numberOfHumans; human++)
		{
			outGraph << endl << endl;
			outGraph << "graphs <- list()" << endl;
			outGraph << "graphs[[1]] <- graph.formula( ";

			int numberOfEdge = graphs[human].getLenght();
			for (int i=0; i < numberOfEdge; i++)
			{
				Edge e = graphs[human].Pop();

				if (i!=0) outGraph << ", ";
				outGraph << e.getVertexOne() << "-";
				outGraph << e.getVertexTwo();
			}
			outGraph << ")" << endl;
			outGraph << "graphs[[1]] <- simplify(graphs[[1]])" << endl;
			outGraph << endl;
			outGraph << "lay <- lapply(graphs, layout.fruchterman.reingold, niter=3000)" << endl;
			outGraph << endl;
			outGraph << "par(mai=c(0,0,0,0))" << endl;
			outGraph << "layout(matrix(1:1, nr=1, byrow=TRUE))" << endl;
			outGraph << "for (i in seq(along=graphs)) {" << endl;
			outGraph << "  plot(graphs[[i]], layout=lay[[i]]," << endl;
			outGraph << "       vertex.label=NA, vertex.size=3, edge.color=\"black\"," << endl;
			outGraph << "       vertex.color=\"";
			if (isSick[human]) outGraph << "red"; 
			else outGraph << "green";
			outGraph << "\")" << endl;
			outGraph << "}" << endl;
		}
		outGraph << "dev.off()" << endl;

		outGraph.close();
	}

	vector<double> getEfficiencies() 
	{
		vector<double> res(graphs.size());

		for (int i = 0; i < graphs.size(); i++)
		{
			res[i] = graphs[i].getEfficiency();
		}

		return res;
	}

	vector<double> getMaxVertexes() 
	{
		vector<double> res(graphs.size());

		for (int i = 0; i < graphs.size(); i++)
		{
			res[i] = graphs[i].getMaxVertex();
		}

		return res;
	}
};

