#include "Human.h"

Human::Human( const vector< vector<double> >& sarr, const vector<bool> canser, int i )
{
	numberMRA = sarr.size();

	for (int q = 0; q < sarr.size();++q)
	{
		miRNAexpression.push_back(sarr[q][i]);
	}

	sick = canser[i];
}

bool Human::isSick()
{
	return sick;
}

double Human::getMiRNAexpression( int number )
{
	return miRNAexpression[number];
}

int Human::getSizeMiRNAexpression()
{
	return numberMRA;
}

Human::~Human( void )
{

}
