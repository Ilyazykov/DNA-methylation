#pragma once
#include <vector>
#include <exception>
#include <cmath>
#include "ILinearRegression.h"
using namespace std;

class linearRegression : public ILinearRegression
{
	//a1*x+a2*y=b
	//a1^2 + a2^2 = 1
	double a1, a2;
	double b;

public:
	linearRegression();

	virtual void getLinearRegression(vector<double> x, vector<double> y);

	linearRegression(vector<double> x, vector<double> y);

	virtual double getError(double x, double y) const;
	~linearRegression(void);
};

