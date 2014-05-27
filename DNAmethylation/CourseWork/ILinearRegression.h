#pragma once

#include <vector>
using namespace std;

class ILinearRegression
{
public:
	virtual void getLinearRegression(vector<double> x, vector<double> y) = 0;
	virtual double getError(double x, double y) const = 0;
};