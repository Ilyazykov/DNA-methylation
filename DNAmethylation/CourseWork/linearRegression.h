#pragma once
#include <vector>
#include <exception>
#include <cmath>
#include "ILinearRegression.h"
using namespace std;

class linearRegression : ILinearRegression
{
	//a1*x+a2*y=b
	//a1^2 + a2^2 = 1
	double a1, a2;
	double b;

public:
	linearRegression()
	{
	}

	virtual void getLinearRegression(vector<double> x, vector<double> y)
	{
		if (x.size() != y.size()) throw exception("Size of vectors is different");

		int n = x.size();

		double sumOfY = 0;
		double sumOfX = 0;
		double sumOfXY = 0;
		double sumOfXsq = 0;
		double sumOfYsq = 0;

		for (int i=0;i<n;i++)
		{
			sumOfY += y[i];
			sumOfX += x[i];
			sumOfXY += x[i] * y[i];
			sumOfXsq += x[i] * x[i];
			sumOfYsq += y[i] * y[i];
		}
		
		double fi = atan( 2*(n*sumOfXY-sumOfX*sumOfY) / ((n*sumOfYsq-pow(sumOfY,2))-(n*sumOfXsq-pow(sumOfX,2))) )  /  2;
		a1 = sin(fi);
		a2 = cos(fi);
		b = (a1*sumOfX+ a2*sumOfY) / (double)n;
	}

	linearRegression(vector<double> x, vector<double> y)
	{
		getLinearRegression(x, y);
	}

	virtual double getError(double x, double y) const
	{
		return abs(a1*x+a2*y - b);
	}
	~linearRegression(void) {}
};

