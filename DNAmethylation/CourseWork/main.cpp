#include <fstream>
#include <string>
#include <vector>
#include "SVreader.h"
#include "Human.h"
#include "ILinearRegression.h"
#include "linearRegression.h"
#include "OrdinaryLeastSquares.h"
#include "normalDistribution.h"
#include "SortedListOfEdge.h"
#include "Edge.h"
#include "Graphs.h"
#include "MainMethod.h"
using namespace std;

void outEfficiencies(vector<double> efficiencies1, vector<double> efficiencies2, string pathOut)
{
	ofstream streamEfficiencies(pathOut.c_str());

	for (int i = 0; i < efficiencies1.size(); i++)
	{
		streamEfficiencies << efficiencies1[i] << '\t'<< efficiencies2[i] << endl;
	}

	streamEfficiencies.close();

	cout << "Готово!";
}

void outEfficiencies(vector<double> efficiencies1, vector<int> efficiencies2, string pathOut)
{
	ofstream streamEfficiencies(pathOut.c_str());

	for (int i = 0; i < efficiencies1.size(); i++)
	{
		streamEfficiencies << efficiencies1[i] << '\t'<< efficiencies2[i] << endl;
	}

	streamEfficiencies.close();

	cout << "Готово!";
}

void main()
{
	setlocale(LC_ALL, "rus");

	int numX = 684; //TODO изменить колво людей (684 - максимум)
	int numY = 1000; //TODO изменить колво MRAn
	string pathGeneMeanMats = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\geneMeanMats.csv";
	string pathGeneMeanMats1000 = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\2geneMeanMats.csv";
	string pathGeneVarMats = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\geneVarMats.csv";
	string pathPhenData = "C:\\Users\\Ilya\\Google Диск\\Zykov\\data\\phenData.csv";

	MainMethod *method = new MainMethod(pathGeneMeanMats, pathPhenData, numX, numY, 1000);
	Graphs *graphs = new Graphs(method->execute());
	vector<double> efficiencies = graphs->getEfficiencies();

	delete graphs;
	delete method;

	//vector<double> vertexMax = graphs->getMaxVertexes()
	//graphs->outGraphs(method->getSickVector(), "graphes.r");

	method = new MainMethod(pathGeneVarMats, pathPhenData, numX, numY, 1000);
	graphs = new Graphs(method->execute());
	vector<double> efficiencies1000 = graphs->getEfficiencies();

	delete graphs;
	delete method;

	outEfficiencies(efficiencies, efficiencies1000, "efficiencies.txt");

	cin.get();
}