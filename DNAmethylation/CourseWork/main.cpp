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
using namespace std;

void main()
{
	SortedListOfEdge list(4);

	Edge e1(1, 2, 1);
	Edge e2(2,3,2);
	Edge e3(3,4,3);
	Edge e4(4,5,4);
	Edge e5(5,6,5);

	list.Push(e3);
	list.Push(e1);
	list.Push(e5);
	list.Push(e2);
	list.Push(e4);

	cout << list.Pop().getWeight() << ' ';
	cout << list.Pop().getWeight() << ' ';
	cout << list.Pop().getWeight() << ' ';
	cout << list.Pop().getWeight() << ' ';
	cout << list.Pop().getWeight() << ' ';

	cin.get();

	//setlocale(LC_ALL, "rus");

	//// 0.
	//int numX = 2; //TODO изменить дл€ рабочего запуска
	//int numY = 3; //TODO изменить дл€ рабочего запуска

	//vector< vector<double> > sarr;
	//
	//string path = "C:\\Users\\user\\Google ƒиск\\Zykov\\data\\geneMeanMats.csv";

	//CSVreader reader;
	//reader.readData(path, ",", sarr, numY, numX);
	//reader.delTitles(sarr);

	//// 1. сбор данных из таблицы

	//int numberOfMRA = sarr.size();
	//int numberOfHuman = sarr[0].size();

	//vector<Human> humans;
	//
	//for (int i = 0; i < numberOfHuman; ++i)
	//{
	//	humans.emplace_back(Human(sarr, i));
	//}

	//for (int i = 0; i<sarr.size(); ++i)
	//{
	//	sarr[i].clear();
	//}
	//sarr.clear(); // sarr больше не нужен, он может уходить

	//// 2. линейна€ регресси€
	//int size = numberOfMRA;
	//vector<vector<linearRegression> > linearRegressionDNA(numberOfMRA, numberOfMRA);

	//vector<double> x(numberOfHuman);
	//vector<double> y(numberOfHuman);
	//for (int xi = 0; xi < numberOfMRA; xi++) {
	//	for (int yi = 0; yi < numberOfMRA; yi++) 
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

	//	////////////////////////////////////////////работает
	//// 3. вычисление матрицы ошибок дл€ каждого человека
	//vector<Human>::iterator human;
	//for (human = humans.begin(); human != humans.end(); ++human) 
	//{
	//	for (int i = 0; i < size; i++) {
	//		for (int j = 0; j < size; j++) {
	//			human->setErrors(linearRegressionDNA, i, j);
	//		}
	//	}
	//}

	//// 4. получение графа дл€ каждого человека
	//vector<MatrixGraph> graphsOfHuman(numberOfHuman);
	//for (int i = 0; i < numberOfHuman; i++)
	//{
	//	graphsOfHuman[i].create(size);
	//}

	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) 
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

	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) 
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