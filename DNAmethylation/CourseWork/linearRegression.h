#pragma once
#include <vector>
#include <exception>
using namespace std;

class linearRegression
{
	//y = beta * x + alpha
	double alpha;
	double beta;
public:
	linearRegression(vector<double> x, vector<double> y)
	{
		if (x.size() != y.size()) throw exception("Size of vectors is different");

		int n = x.size();

		double sumOfY = 0;
		double sumOfX = 0;
		double sumOfXY = 0;
		double sumOfXsq = 0;

		for (int i=0;i<n;i++)
		{
			sumOfY += y[i];
			sumOfX += x[i];
			sumOfXY += x[i] * y[i];
			sumOfXsq += x[i] * x[i];
		}

		beta = (n*sumOfXY - sumOfX*sumOfY)/(n*sumOfXsq - sumOfX*sumOfX);
		alpha = (sumOfY - beta*sumOfX)/(double)n;
	}

	double getError(double x, double y)
	{
		return y - beta*x - alpha;
	}

	double getValue(double x)
	{
		return beta*x + alpha;
	}

	~linearRegression(void) {}
};

