#include "linearRegression.h"

linearRegression::linearRegression()
{

}

linearRegression::linearRegression( vector<double> x, vector<double> y )
{
	getLinearRegression(x, y);
}

void linearRegression::getLinearRegression( vector<double> x, vector<double> y )
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
	b = (a1*sumOfX+a2*sumOfY) / (double)n;
}

double linearRegression::getError( double x, double y ) const
{
	return a1*x+a2*y - b;
}

linearRegression::~linearRegression( void )
{

}
