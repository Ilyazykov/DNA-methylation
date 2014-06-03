#pragma once
#include "ilinearregression.h"
class OrdinaryLeastSquares : public ILinearRegression
{
	//y = beta * x + alpha
	double alpha;
	double beta;
public:
	OrdinaryLeastSquares();

	virtual void getLinearRegression(vector<double> x, vector<double> y);

	OrdinaryLeastSquares(vector<double> x, vector<double> y);

	virtual double getError(double x, double y) const;

	~OrdinaryLeastSquares(void);
};
