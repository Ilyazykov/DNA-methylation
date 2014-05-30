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

	cout << "������!";
}

void main()
{
	setlocale(LC_ALL, "rus");

	int numX = 300; //TODO �������� ����� ����� (684 - ��������)
	int numY = 1000; //TODO �������� ����� MRAn
	string pathGeneMeanMats = "C:\\Users\\Ilya\\Google ����\\Zykov\\data\\geneMeanMats.csv";
	string pathGeneVarMats = "C:\\Users\\Ilya\\Google ����\\Zykov\\data\\geneVarMats.csv";
	string pathPhenData = "C:\\Users\\Ilya\\Google ����\\Zykov\\data\\phenData.csv";

	MainMethod *method = new MainMethod(pathGeneMeanMats, pathPhenData, numX, numY, 500);
	
	Graphs *graphs = new Graphs(method->execute());
	vector<double> efficiencies = graphs->getEfficiencies();

	//vector<double> vertexMax = graphs->getMaxVertexes()
	//graphs->outGraphs(method->getSickVector(), "graphes.r");

	delete graphs;
	delete method;

	method = new MainMethod(pathGeneVarMats, pathPhenData, numX, numY, 500);
 	graphs = new Graphs(method->execute());
	vector<double> efficienciesVar = graphs->getEfficiencies();

	delete graphs;
	delete method;

	outEfficiencies(efficiencies, efficienciesVar, "efficiencies.txt");

	cin.get();
}