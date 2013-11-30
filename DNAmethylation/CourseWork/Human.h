#pragma once
#include <vector>
#include <exception>
#include <iostream>
#include "linearRegression.h"
using namespace std;

class Human
{
	static int numberMRA;

	vector<double> miRNAexpression; //TODOдолжна быть одного размера у всех
	bool isSick;
	vector<vector<double> > errors;

public:
	void getErrors(const vector<vector<linearRegression> > & linReg, int xi, int yi)
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

	Human(void)
	{

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

	static int getSizeMiRNAexpression()
	{
		return numberMRA;
	}

	~Human(void)
	{

	}
};