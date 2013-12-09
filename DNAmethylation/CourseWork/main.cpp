#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits>
#include "SVreader.h"
#include "Human.h"
#include "linearRegression.h"
#include "normalDistribution.h"
#include "Graph.h"
#include "MatrixGraph.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	// 0.
	int numX = 4; //TODO изменить для рабочего запуска
	int numY = 9; //TODO изменить для рабочего запуска

	vector< vector<double> > sarr;
	
	string path = "C:\\Users\\user\\Google Диск\\Zykov\\data\\geneMeanMats.csv";

	CSVreader reader;
	reader.readData(path, ",", sarr, numY, numX);
	reader.delTitles(sarr);

	// 1. сбор данных из таблицы

	int numberOfMRA = sarr.size();
	int numberOfHuman = sarr[0].size();

	vector<Human> humans;
	
	for (int i = 0; i < numberOfHuman; ++i)
	{
		humans.emplace_back(Human(sarr, i));
	}

	for (int i = 0; i<sarr.size(); ++i)
	{
		sarr[i].clear();
	}
	sarr.clear(); // sarr больше не нужен, он может уходить

	// 2. линейная регрессия
	int size = numberOfMRA;
	vector<vector<linearRegression> > linearRegressionDNA(numberOfMRA, numberOfMRA);

	vector<double> x(numberOfHuman);
	vector<double> y(numberOfHuman);
	for (int xi = 0; xi < numberOfMRA; xi++) {
		for (int yi = xi+1; yi < numberOfMRA; yi++) 
		{
			x.clear();
			y.clear();
			for (int h = 0; h < numberOfHuman; h++) {
				x.push_back(humans[h].getMiRNAexpression(xi));
				y.push_back(humans[h].getMiRNAexpression(yi));
			}
			linearRegressionDNA[xi][yi].getLinearRegression(x, y);
		}
	}

		////////////////////////////////////////////работает
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

	cout << "Готово!";
	cin.get();
}