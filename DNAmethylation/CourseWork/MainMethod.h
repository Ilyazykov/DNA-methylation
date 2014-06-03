#pragma once
#include "Human.h"
#include "SVreader.h"
#include "SortedListOfEdge.h"
#include "normalDistribution.h"
#include "linearRegression.h"
#include "OrdinaryLeastSquares.h"
#include <vector>
#include <iostream>
using namespace std;

class MainMethod
{
	vector<Human> humans;
	int numberOfHuman;
	int numberOfMRA;
	int hulfOfHealphHumans;
	int maxLenghtOfGraph;

	int numX; //684 - max
	int numY;

	vector<Human> readCSV(string pathForMatrixHormone, string pathForCase, int numX, int numY);

	int getNumberOfControl();

	void indicateProgress(int xi, int maxXi);
	
public:
	MainMethod(string pathToData, string pathToDataBool, int numHumans = 684, int numMRA = 1000, int maxLenghtOfGraph = 500);

	~MainMethod(void);

	vector<SortedListOfEdge> execute();

	vector<bool> getSickVector();
};

