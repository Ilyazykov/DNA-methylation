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
	normalDistribution()
	{

	}

	normalDistribution(vector<double> x, double expectation)
	{
		this->expectation = expectation;

		double n = (double)x.size();
		double sum = 0;
		double sumsq = 0;
		for (int i = 0; i < n; i++)
		{
			sum += x[i];
			sumsq += x[i]*x[i];
		}
		dispertion = (sumsq * n - sum*sum) / ((n - 1)*n);

		standartDeviation = sqrt(dispertion);
	}

	double getZScore(double e)
	{
		return e/standartDeviation;
	}

	~normalDistribution(void)
	{

	}
};

