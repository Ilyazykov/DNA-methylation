#pragma once
#include <vector>
#include <exception>
#include <iostream>
#include "linearRegression.h"
using namespace std;

class Human
{
	int numberMRA;

	vector<double> miRNAexpression; //TODOдолжна быть одного размера у всех
	bool isSick;
public:
	
	Human(const vector< vector<double> >& sarr, const vector<bool> canser, int i)
	{
		numberMRA = sarr.size();

		for (int q = 0; q < sarr.size();++q)
		{
			miRNAexpression.push_back(sarr[q][i]);
		}

		isSick = canser[i];
	}

	double getMiRNAexpression(int number)
	{
		return miRNAexpression[number];
	}

	int getSizeMiRNAexpression()
	{
		return numberMRA;
	}

	~Human(void)
	{

	}
};