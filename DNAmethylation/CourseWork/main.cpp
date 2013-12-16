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

//vector<Human> step1(string path, int numX, int numY)
//{
//	vector< vector<double> > sarr;
//
//	CSVreader reader;
//	reader.readData(path, ",", sarr, numY, numX);
//	reader.delTitles(sarr);
//
//	int numberOfMRA = sarr.size();
//	int numberOfHuman = sarr[0].size();
//
//	vector<Human> humans;
//	
//	for (int i = 0; i < numberOfHuman; ++i)
//	{
//		humans.emplace_back(Human(sarr, i));
//	}
//
//	return humans;
//}

void main()
{
	TriangleMatrix<int> m(4);

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			m.addElem(i+j, i, j);
		}
	}

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			cout << m.get(i, j) << ' ';
		}
		cout << endl;
	}

	cin.get();
	//setlocale(LC_ALL, "rus");

	//// 1. сбор данных из таблицы
	//int numX = 2; //TODO изменить дл€ рабочего запуска
	//int numY = 3; //TODO изменить дл€ рабочего запуска

	//string path = "C:\\Users\\user\\Google ƒиск\\Zykov\\data\\geneMeanMats.csv";

	//vector<Human> humans = step1(path, numX, numY);

	//int numberOfHuman = humans.size();
	//int numberOfMRA = humans[0].getSizeMiRNAexpression();
	//
	//// 2. линейна€ регресси€
	//vector<vector<linearRegression> > linearRegressionDNA(numberOfMRA, numberOfMRA);

	//vector<double> x(numberOfHuman);
	//vector<double> y(numberOfHuman);
	//for (int xi = 0; xi < numberOfMRA; xi++) {
	//	for (int yi = xi+1; yi <= numberOfMRA; yi++) 
	//	{
	//		x.clear();
	//		y.clear();
	//		for (int h = 0; h < numberOfHuman; h++) {
	//			x.push_back(humans[h].getMiRNAexpression(xi));
	//			y.push_back(humans[h].getMiRNAexpression(yi));
	//		}
	//		linearRegressionDNA[xi][yi].getLinearRegression(x, y);
	//	}
	//}

	//// 3. вычисление матрицы ошибок дл€ каждого человека
	//vector<Human>::iterator human;
	//for (human = humans.begin(); human != humans.end(); ++human) 
	//{
	//	for (int i = 0; i < numberOfMRA; i++) {
	//		for (int j = 0; j < numberOfMRA; j++) {
	//			human->setErrors(linearRegressionDNA, i, j);
	//		}
	//	}
	//}

	//// 4. получение графа дл€ каждого человека
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

	//// ¬ывод
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
	//

	//cout << "√отово!";
	//cin.get();
}