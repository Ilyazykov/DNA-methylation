#include <iostream>
#include <fstream>
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
#include "SortedListOfEdge.h"
#include "Edge.h"
#include "TriangleMatrix.h"
using namespace std;

vector<Human> step1(string path, int numX, int numY)
{
	vector< vector<double> > sarr;

	CSVreader reader;
	reader.readData(path, ",", sarr, numY, numX);
	reader.delTitles(sarr);

	int numberOfMRA = sarr.size();
	int numberOfHuman = sarr[0].size();

	vector<Human> humans;

	for (int i = 0; i < numberOfHuman; ++i)
	{
		humans.emplace_back(Human(sarr, i));
	}

	return humans;
}

void main()
{
	setlocale(LC_ALL, "rus");

	// 1. сбор данных из таблицы
	int numX = 2; //TODO изменить для рабочего запуска
	int numY = 3; //TODO изменить для рабочего запуска

	string path = "C:\\Users\\user\\Google Диск\\Zykov\\data\\geneMeanMats.csv";

	vector<Human> humans = step1(path, numX, numY);

	int numberOfHuman = humans.size();
	int numberOfMRA = humans[0].getSizeMiRNAexpression();
	
	// 2. Получение матрицы ошибок для каждого человека
	for (int xi = 0; xi < numberOfMRA; xi++) {
		for (int yi = xi+1; yi < numberOfMRA; yi++) 
		{
			linearRegression linReg;

			vector<double> x(numberOfHuman);
			vector<double> y(numberOfHuman);
			for (int h = 0; h < numberOfHuman; h++) {
				x.push_back(humans[h].getMiRNAexpression(xi));
				y.push_back(humans[h].getMiRNAexpression(yi));
			}
			linReg.getLinearRegression(x, y);
				
			for (int h = 0; h < numberOfHuman; h++) {
				humans[h].setError(linReg, xi, yi);
			}
		}
	}

	//// 4. получение графа для каждого человека
	//vector<MatrixGraph> graphsOfHuman(numberOfHuman);
	//for (int i = 0; i < numberOfHuman; i++)
	//{
	//	graphsOfHuman[i].create(numberOfMRA);
	//}

	//for (int i = 0; i < numberOfMRA; i++) {
	//	for (int j = 0; j < numberOfMRA; j++) 
	//	{
	//		vector<double> errorsForLinearRegression(numberOfHuman);
	//		for (int h = 0; h < numberOfHuman; h++)
	//		{
	//			errorsForLinearRegression[h] = humans[h].getError(i, j);
	//		}
	//		normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);

	//		for (int h = 0; h < numberOfHuman; h++)
	//		{
	//			graphsOfHuman[h].AddArc(i, j, abs(  nDistrib->getZScore(humans[h].getError(i, j))  ));
	//		}
	//	}
	//}

	//// Вывод
	//string pathOut = "out.txt";
	//ofstream outGraph(pathOut.c_str());

	//for (int i = 0; i < numberOfMRA; i++) {
	//	for (int j = 0; j < numberOfMRA; j++) 
	//	{
	//		outGraph << graphsOfHuman[1].getEdge(i,j) << "  ";
	//	}
	//	outGraph << endl;
	//}
	//outGraph.close();
	

	cout << "Готово!";
	cin.get();
}