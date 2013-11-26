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
	normalDistribution(vector<double> x, double exception)
	{
		this->expectation = exception;

		double sum = 0;
		double sumsq = 0;
		for (int i = 0; i < x.size(); i++)
		{
			sum += x[i];
			sumsq += x[i]*x[i];
		}
		dispertion = (sumsq - sum*sum / x.size()) / (x.size() - 1);

		standartDeviation = sqrt(dispertion);
	}

	double getZScore(double e)
	{
		return e/standartDeviation;
	}

	~normalDistribution(void);
};

