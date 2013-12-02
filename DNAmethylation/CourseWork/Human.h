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

	vector<vector<double> > zScoreMatrix;

public:
	

	Human()
	{
		//miRNAexpression.resize(numberMRA);

		//errors.resize(numberMRA);
		//for (int i = 0; i < numberMRA; i++) {
		//	errors[i].resize(numberMRA);
		//}

		//zScoreMatrix.resize(numberMRA);
		//for (int i = 0; i < numberMRA; i++) {
		//	zScoreMatrix[i].resize(numberMRA);
		//}
	}

	Human(int numberMRA)
	{
		miRNAexpression.resize(numberMRA);

		errors.resize(numberMRA);
		for (int i = 0; i < numberMRA; i++) {
			errors[i].resize(numberMRA);
		}

		zScoreMatrix.resize(numberMRA);
		for (int i = 0; i < numberMRA; i++) {
			zScoreMatrix[i].resize(numberMRA);
		}
	}

	void setZScore(double value, int i, int j)
	{
		zScoreMatrix[i][j] = value;
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