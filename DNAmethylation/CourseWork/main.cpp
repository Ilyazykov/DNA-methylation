#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include "Human.h"
#include "linearRegression.h"
using namespace std;

int getNumberOfHumanFromCSV()
{
	throw exception(); //TODO
	return 5;
}

void main()
{
	// 1. ���� ������ �� �������
	int numberOfHuman = getNumberOfHumanFromCSV();//TODO
	vector<Human> humans(numberOfHuman);
	
	for (int i = 0; i < numberOfHuman; i++)
	{
		humans[i].getHumanFromCSV(); //TODO
	}

	// 2. �������� ���������
	int size = humans[0].getSizeMiRNAexpression();
	vector<vector<linearRegression> > linearRegressionDNA(size, size);

	vector<double> x(size);
	vector<double> y(size);
	for (int xi = 0; xi < size; xi++) {
		x.clear();
		for (int yi = 0; yi < size; yi++) {
			y.clear();
			for (int h = 0; h < size; h++) {
				x.push_back(humans[h].getMiRNAexpression(xi));
				y.push_back(humans[h].getMiRNAexpression(yi));
			}
			linearRegressionDNA[xi][yi].getLinearRegression(x, y);
		}
	}
	
	// 3. ���������� ������� ������ ��� ������� ��������
	vector<Human>::iterator human;
	for (human = humans.begin(); human != humans.end(); ++human) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				human->getErrors(linearRegressionDNA, i, j);
			}
		}
	}

	// 4. ���������� ������� Z ��� ������� ��������
	vector<Human>::iterator human;
	for (human = humans.begin(); human != humans.end(); ++human) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				//TODO
			}
		}
	}


	cin.get();
}