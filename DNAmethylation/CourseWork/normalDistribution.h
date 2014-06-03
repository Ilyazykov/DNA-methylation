#pragma once
#include <vector>
#include <cmath>
using namespace std;

class normalDistribution
{
	//f(x) = (1/sigma * (2*pi)) * exp(-(x-nu)^2 / (2 * sigma^2))
	double expectation;
	double dispertion;
	double standartDeviation;
public:
	normalDistribution();

	normalDistribution(vector<double> x, double expectation);

	double getZScore(double e);

	~normalDistribution(void);
};

