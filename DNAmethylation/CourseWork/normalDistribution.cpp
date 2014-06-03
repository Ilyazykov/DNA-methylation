#include "normalDistribution.h"

normalDistribution::normalDistribution()
{

}

normalDistribution::normalDistribution( vector<double> x, double expectation )
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

double normalDistribution::getZScore( double e )
{
	return e/standartDeviation;
}

normalDistribution::~normalDistribution( void )
{

}
