#include <fstream>
#include <string>
#include <vector>
#include "SVreader.h"
#include "Human.h"
#include "linearRegression.h"
#include "normalDistribution.h"
#include "SortedListOfEdge.h"
#include "Edge.h"
using namespace std;

vector<Human> readCSV(string pathForMatrixHormone, string pathForCase, int numX, int numY)
{
	vector< vector<double> > sarr;
	vector<bool> canserArray;

	CSVreader readerForHormoneLevel;
	readerForHormoneLevel.readData(pathForMatrixHormone, ",", sarr, numY, numX);
	readerForHormoneLevel.delTitles(sarr);

	CSVreader readerForCanser;
	readerForCanser.readVector(pathForCase, ",", canserArray, numX);
	canserArray.erase(canserArray.begin());

	int numberOfMRA = sarr.size();
	int numberOfHuman = sarr[0].size();

	vector<Human> humans;

	for (int i = 0; i < numberOfHuman; ++i)
	{
		humans.emplace_back(Human(sarr,canserArray, i));
	}

	return humans;
}

int getNumberOfControl(vector<Human> humans)
{
	int res = 0;
	for (int i = 0; i < humans.size(); i++)
	{
		if (!humans[i].isSick()) res++;
	}

	return res;
}

void outGraphs(vector<SortedListOfEdge>& graphs, vector<Human> humans ) 
{
	string pathOut = "graphs.r";
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
		if (humans[human].isSick()) outGraph << "red"; 
		else outGraph << "green";
		outGraph << "\")" << endl;
		outGraph << "}" << endl;
	}
	outGraph << "dev.off()" << endl;

	outGraph.close();
}

vector<double> getEfficiencies( vector<SortedListOfEdge>& graphs ) 
{
	vector<double> res(graphs.size());

	for (int i = 0; i < graphs.size(); i++)
	{
		res[i] = graphs[i].getEfficiency();
	}

	return res;
}

vector<double> getMaxVertexes( vector<SortedListOfEdge>& graphs ) 
{
	vector<double> res(graphs.size());

	for (int i = 0; i < graphs.size(); i++)
	{
		res[i] = graphs[i].getMaxVertex();
	}

	return res;
}

vector<SortedListOfEdge> superMethod(vector<Human> humans)
{
	int numberOfHuman = humans.size();
	int numberOfMRA = humans[0].getSizeMiRNAexpression();
	int hulfOfHealphHumans = getNumberOfControl(humans) / 2;
	int maxLenghtOfGraph = 500;

	// Получение графов
	vector<SortedListOfEdge> graphs;
	for (int i = 0; i < numberOfHuman; ++i)
	{
		graphs.emplace_back(SortedListOfEdge(numberOfMRA, maxLenghtOfGraph));
	}

	for (int xi = 0; xi < numberOfMRA; xi++) 
	{
		if (xi % 10 == 0) cout << xi / 10 << endl;

		for (int yi = xi+1; yi < numberOfMRA; yi++) 
		{
			linearRegression *linReg = new linearRegression();

			vector<double> x(numberOfHuman);
			vector<double> y(numberOfHuman);

			for (int h = 0, healph = 0; healph < hulfOfHealphHumans; h++) 
			{
				if (!humans[h].isSick())
				{
					x.push_back(humans[h].getMiRNAexpression(xi));
					y.push_back(humans[h].getMiRNAexpression(yi));
					healph++;
				}
			}
			linReg->getLinearRegression(x, y);

			x.clear();
			y.clear();

			vector<double> errorsForLinearRegression(numberOfHuman);
			for (int h = 0; h < numberOfHuman; h++)
			{
				errorsForLinearRegression[h] = abs(linReg->getError(humans[h].getMiRNAexpression(xi), humans[h].getMiRNAexpression(yi)));
			}

			delete linReg;

			normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);

			for (int h = 0; h < numberOfHuman; h++)
			{
				Edge edge(xi, yi, nDistrib->getZScore(errorsForLinearRegression[h]));
				graphs[h].Push(edge);
			}

			errorsForLinearRegression.clear();
			delete nDistrib;
		}
	}	
	return graphs;
}

void main()
{
	setlocale(LC_ALL, "rus");

	// 1. сбор данных из таблицы
	int numX = 684; //TODO изменить колво людей (684 - максимум)
	int numY = 1000; //TODO изменить колво MRAn
	string pathGeneMeanMats = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\geneMeanMats.csv";
	string pathGeneVarMats = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\geneVarMats.csv";
	string pathPhenData = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\phenData.csv";

	vector<Human> humansMean = readCSV(pathGeneMeanMats, pathPhenData, numX, numY);
	vector<SortedListOfEdge> graphs = superMethod(humansMean);

	vector<double> efficiencies = getEfficiencies(graphs);
	vector<double> valuesOfMaxVertexes = getMaxVertexes(graphs);
	//outGraphs(graphs, humans);

	///
	string pathOut = "efficiencies.txt";
	ofstream outEfficiencies(pathOut.c_str());

	for (int i = 0; i < graphs.size(); i++)
	{
		outEfficiencies << efficiencies[i] << '\t'<< valuesOfMaxVertexes[i] << endl;
	}
	
	outEfficiencies.close();

	cout << "Готово!";
	cin.get();
}