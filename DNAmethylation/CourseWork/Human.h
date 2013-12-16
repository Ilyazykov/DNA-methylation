#pragma once
#include <vector>
#include <exception>
#include <iostream>
#include "TriangleMatrix.h"
#include "linearRegression.h"
using namespace std;

class Human
{
	int numberMRA;

	vector<double> miRNAexpression; //TODOдолжна быть одного размера у всех
	bool isSick;
public:
	

	Human(const vector< vector<double> >& sarr, int i)
	{
		numberMRA = sarr.size();

		for (int q = 0; q < sarr.size();++q)
		{
			miRNAexpression.push_back(sarr[q][i]);
		}
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