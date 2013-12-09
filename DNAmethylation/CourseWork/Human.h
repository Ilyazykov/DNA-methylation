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
	vector<vector<double> > errors;
public:
	

	Human(const vector< vector<double> >& sarr, int i)
	{
		numberMRA = sarr.size();

		for (int q = 0; q < sarr.size();++q)
		{
			miRNAexpression.push_back(sarr[q][i]);
		}

		errors.resize(numberMRA);
		for (int q = 0; q < numberMRA; q++) {
			errors[q].resize(numberMRA);
		}
	}

	double getError(int i, int j)
	{
		return errors[i][j];
	}

	void setErrors(const vector<vector<linearRegression> > & linReg, int xi, int yi)
	{
		errors.resize(numberMRA);
		for (int i = 0; i<numberMRA; i++)
		{
			errors[i].resize(numberMRA);
		}

		for (int i = 0; i < numberMRA; i++) {
			for (int j = 0; j < numberMRA; j++) {
				errors[i][j] = linReg[i][j].getError(miRNAexpression[xi], miRNAexpression[yi]);
			}
		}
	}

	double getMiRNAexpression(int number)
	{
		return miRNAexpression[number];
	}

	void getHumanFromCSV()
	{
		cout << "\nHere *.csv file must be read"; //TODO
		throw exception("Здесь должно происходить считывание из *.csv"); //TODO
	}

	int getSizeMiRNAexpression()
	{
		return numberMRA;
	}

	~Human(void)
	{

	}
};