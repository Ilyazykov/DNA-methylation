#pragma once
#include "ilinearregression.h"
class OrdinaryLeastSquares : public ILinearRegression
{
	//y = beta * x + alpha
	double alpha;
	double beta;
public:
	OrdinaryLeastSquares()
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

	OrdinaryLeastSquares(vector<double> x, vector<double> y)
	{
		getLinearRegression(x, y);
	}

	virtual double getError(double x, double y) const
	{
		return y - beta*x - alpha;
	}

	~OrdinaryLeastSquares(void) {}
};
