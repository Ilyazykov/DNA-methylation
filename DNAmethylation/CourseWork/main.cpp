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

void outGraphs(vector<SortedListOfEdge>& graphs ) 
{
	string pathOut = "out.txt";
	ofstream outGraph(pathOut.c_str());

	int numberOfHumans = graphs.size();
	for (int human = 0; human < numberOfHumans; human++)
	{
		int numberOfEdge = graphs[human].getLenght();

		for (int i=0; i < numberOfEdge; i++)
		{
			Edge e = graphs[human].Pop();

			outGraph << e.getVertexOne() << '\t';
			outGraph << e.getVertexTwo() << '\t';
			outGraph << e.getWeight() << endl;
		}
		outGraph << endl << endl;
	}
	

	outGraph.close();
}

void main()
{
	setlocale(LC_ALL, "rus");

	// 1. ���� ������ �� �������
	int numX = 3; //TODO �������� ��� �������� �������
	int numY = 4; //TODO �������� ��� �������� �������
	string path = "C:\\Users\\user\\Google ����\\Zykov\\data\\geneMeanMats.csv";

	vector<Human> humans = readCSV(path, numX, numY);

	int numberOfHuman = humans.size();
	int numberOfMRA = humans[0].getSizeMiRNAexpression();
	
	//
	vector<SortedListOfEdge> graphs(numberOfHuman);
	// 2. ��������� zScore
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
				errorsForLinearRegression[h] = abs(linReg->getError(humans[h].getMiRNAexpression(xi), humans[h].getMiRNAexpression(yi)));
			}

			delete linReg;

			normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);

			for (int h = 0; h < numberOfHuman; h++)  //������� �������� ����
			{
				Edge edge = (xi, yi, nDistrib->getZScore(errorsForLinearRegression[h]));
				graphs[h].Push(edge);
			}

			errorsForLinearRegression.clear();
			delete nDistrib;
		}
	}	

	outGraphs(graphs);

	cout << "������!";
	cin.get();
}