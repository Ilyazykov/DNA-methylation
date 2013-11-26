#pragma once
#include <vector>
using namespace std;

class Human
{
	vector<double> miRNAexpression;
	bool isSick;
public:
	Human(void);
	~Human(void);
};