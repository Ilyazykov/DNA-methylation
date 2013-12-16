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

vector<Human> readCSV(string path, int numX, int numY)
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

void outGraph(SortedListOfEdge& graph ) 
{
	string pathOut = "out.txt";
	ofstream outGraph(pathOut.c_str());

	int size = graph.getLenght();

	for (int i=0; i < size; i++)
	{
		Edge e = graph.Pop();

		outGraph << e.getVertexOne() << '\t';
		outGraph << e.getVertexTwo() << '\t';
		outGraph << e.getWeight() << endl;
	}

	outGraph.close();
}

void main()
{
	setlocale(LC_ALL, "rus");

	// 1. сбор данных из таблицы
	int numX = 4; //TODO изменить для рабочего запуска
	int numY = 6; //TODO изменить для рабочего запуска
	string path = "C:\\Users\\user\\Google Диск\\Zykov\\data\\geneMeanMats.csv";

	vector<Human> humans = readCSV(path, numX, numY);

	int numberOfHuman = humans.size();
	int numberOfMRA = humans[0].getSizeMiRNAexpression();
	
	// 2. Получение графов
	for (int xi = 0; xi < numberOfMRA; xi++) {
		for (int yi = xi+1; yi < numberOfMRA; yi++) 
		{
			linearRegression *linReg = new linearRegression();

			vector<double> x(numberOfHuman);
			vector<double> y(numberOfHuman);

			for (int h = 0; h < numberOfHuman; h++) {
				x.push_back(humans[h].getMiRNAexpression(xi));
				y.push_back(humans[h].getMiRNAexpression(yi));
			}
			linReg->getLinearRegression(x, y);

			x.clear();
			y.clear();
			
			vector<double> errorsForLinearRegression(numberOfHuman);
			for (int h = 0; h < numberOfHuman; h++)
			{
				errorsForLinearRegression[h] = linReg->getError(humans[h].getMiRNAexpression(xi), humans[h].getMiRNAexpression(yi));
			}

			delete linReg;

			SortedListOfEdge graph;

			 normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);
			for (int h = 0; h < numberOfHuman; h++)
			{
				Edge edge(xi, yi, nDistrib->getZScore(errorsForLinearRegression[h]));
				graph.Push(edge);
			}
			errorsForLinearRegression.clear();
			delete nDistrib;

			outGraph(graph);
		}
	}	

	cout << "Готово!";
	cin.get();
}