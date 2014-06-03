#pragma once
#include "Human.h"
#include "SVreader.h"
#include "SortedListOfEdge.h"
#include "normalDistribution.h"
#include "linearRegression.h"
#include "OrdinaryLeastSquares.h"
#include <vector>
#include <iostream>
using namespace std;

class MainMethod
{
	vector<Human> humans;
	int numberOfHuman;
	int numberOfMRA;
	int hulfOfHealphHumans;
	int maxLenghtOfGraph;

	int numX; //684 - max
	int numY;

	vector<Human> readCSV(string pathForMatrixHormone, string pathForCase, int numX, int numY)
	{
		vector< vector<double> > sarr;
		vector<bool> canserArray;

		CSVreader readerForHormoneLevel;
		readerForHormoneLevel.readData(pathForMatrixHormone, ",", sarr, numY, numX);
		readerForHormoneLevel.delTitles(sarr);

		CSVreader readerForCanser;
		readerForCanser.readVector(pathForCase, ",", canserArray, numX);
		canserArray.erase(canserArray.begin());

		int numberOfMRA = sarr.size();
		int numberOfHuman = sarr[0].size();

		vector<Human> humans;

		for (int i = 0; i < numberOfHuman; ++i)
		{
			humans.emplace_back(Human(sarr,canserArray, i));
		}

		return humans;
	}

	int getNumberOfControl()
	{
		int res = 0;
		for (int i = 0; i < humans.size(); i++)
		{
			if (!humans[i].isSick()) res++;
		}

		return res;
	}

	void indicateProgress(int xi, int maxXi)
	{
		if (xi % 10 == 0) cout << xi / 10 << endl;
	}
	
public:
	MainMethod(string pathToData, string pathToDataBool, int numHumans = 684, int numMRA = 1000, int maxLenghtOfGraph = 500)
	{
		numX = numHumans;
		numY = numMRA;

		this->humans = readCSV(pathToData, pathToDataBool, numX, numY);

		numberOfHuman = humans.size();
		numberOfMRA = humans[0].getSizeMiRNAexpression();
		hulfOfHealphHumans = getNumberOfControl() / 2;

		this->maxLenghtOfGraph = maxLenghtOfGraph;
	}

	~MainMethod(void)
	{

	}

	vector<SortedListOfEdge> execute()
	{
		vector<SortedListOfEdge> graphs;
		for (int i = 0; i < numberOfHuman; ++i)
		{
			graphs.emplace_back(SortedListOfEdge(numberOfMRA, maxLenghtOfGraph));
		}

		for (int xi = 0; xi < numberOfMRA; xi++) 
		{
			indicateProgress(xi, 10);

			for (int yi = xi+1; yi < numberOfMRA; yi++) 
			{
				
				vector<double> x(hulfOfHealphHumans); //TODO change number for healph
				vector<double> y(hulfOfHealphHumans); //TODO change number for healph

				ILinearRegression *linReg = new OrdinaryLeastSquares(); //TODO change method
				for (int h = 0, healph = 0; healph < hulfOfHealphHumans;h++)
				{
					if (!humans[h].isSick())
					{
						x.push_back(humans[h].getMiRNAexpression(xi));
						y.push_back(humans[h].getMiRNAexpression(yi));
						healph++;
					}
				}
				linReg->getLinearRegression(x, y);

				x.clear();
				y.clear();

				vector<double> errors(numberOfHuman);
				vector<double> errorsForLinearRegression(hulfOfHealphHumans);
				
				for (int h = 0, healph = 0; h < numberOfHuman; h++)
				{
					errors[h] = abs(linReg->getError(humans[h].getMiRNAexpression(xi), humans[h].getMiRNAexpression(yi)));
					if (healph<hulfOfHealphHumans)
					{
						if (!humans[h].isSick())
						{
							errorsForLinearRegression[healph] = errors[h];
							healph++;
						}
					}
				}

				delete linReg;

				normalDistribution *nDistrib = new normalDistribution(errorsForLinearRegression, 0.0);
				errorsForLinearRegression.clear();

				for (int h = 0; h < numberOfHuman; h++)
				{
					Edge edge(xi, yi, nDistrib->getZScore(errors[h]));
					graphs[h].Push(edge);
				}

				errors.clear();
				delete nDistrib;
			}
		}	
		return graphs;
	}

	vector<bool> getSickVector()
	{
		vector<bool> res(humans.size());
		for (int h = 0; h < humans.size(); h++)
		{
			res.push_back(humans[h].isSick());
		}
	}
};

