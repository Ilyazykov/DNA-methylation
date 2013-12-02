#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include "Human.h"
#include "linearRegression.h"
#include "normalDistribution.h"
#include "Graph.h"
#include "MatrixGraph.h"
using namespace std;

int getNumberOfHumanFromCSV()
{
	throw exception(); //TODO
	return 5;
}

int getNumberOfMRA()
{
	throw exception(); //TODO
	return 6;
}

void main()
{
	// 1. сбор данных из таблицы
	int numberOfHuman = getNumberOfHumanFromCSV();//TODO
	vector<Human> humans(numberOfHuman);
	
	for (int i = 0; i < numberOfHuman; i++)
	{
		humans[i].getHumanFromCSV(); //TODO
	}

	// 2. линейная регрессия
	int size = humans[0].getSizeMiRNAexpression();
	vector<vector<linearRegression> > linearRegressionDNA(size, size);

	vector<double> x(size);
	vector<double> y(size);
	for (int xi = 0; xi < size; xi++) {
		x.clear();
		for (int yi = 0; yi < size; yi++) 
		{
			y.clear();
			for (int h = 0; h < size; h++) {
				x.push_back(humans[h].getMiRNAexpression(xi));
				y.push_back(humans[h].getMiRNAexpression(yi));
			}
			linearRegressionDNA[xi][yi].getLinearRegression(x, y);
		}
	}
	
	// 3. вычисление матрицы ошибок для каждого человека
	vector<Human>::iterator human;
	for (human = humans.begin(); human != humans.end(); ++human) 
	{
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				human->setErrors(linearRegressionDNA, i, j);
			}
		}
	}

	// 4. получение графа для каждого человека
	vector<MatrixGraph> graphsOfHuman(numberOfHuman);
	for (int i = 0; i < numberOfHuman; i++)
	{
		graphsOfHuman[i].create(size);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) 
		{
			vector<double> errorsForLinearRegression(numberOfHuman);
			for (int h = 0; h < numberOfHuman; h++)
			{
				errorsForLinearRegression[h] = humans[h].getError(i, j);
			}
			normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);

			for (int h = 0; h < numberOfHuman; h++)
			{
				graphsOfHuman[h].AddArc(i, j, nDistrib->getZScore(humans[h].getError(i, j)));
			}
		}
	}

	cin.get();
}