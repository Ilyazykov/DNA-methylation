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
	TriangleMatrix<double> errors;
public:
	

	Human(const vector< vector<double> >& sarr, int i)
	{
		numberMRA = sarr.size();

		for (int q = 0; q < sarr.size();++q)
		{
			miRNAexpression.push_back(sarr[q][i]);
		}

		errors.resize(numberMRA);
	}

	double getError(int x, int y)
	{
		return errors(x, y);
	}

	void setError(const linearRegression& linReg, int x, int y)
	{
		errors(x, y) = linReg.getError(miRNAexpression[x], miRNAexpression[y]);
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