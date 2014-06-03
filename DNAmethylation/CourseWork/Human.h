#pragma once
#include <vector>
#include <exception>
#include <iostream>
#include "linearRegression.h"
using namespace std;

class Human
{
	int numberMRA;

	vector<double> miRNAexpression;
	bool sick;
public:
	
	Human(const vector< vector<double> >& sarr, const vector<bool> canser, int i);

	bool isSick();

	double getMiRNAexpression(int number);

	int getSizeMiRNAexpression();

	~Human(void);
};