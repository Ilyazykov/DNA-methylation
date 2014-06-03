#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class CSVreader
{
public:
	CSVreader(void);
	~CSVreader(void);

	void splitString(const string &fullstr, vector<string> &elements, const string &delimeter);

	double stringToDouble(const string &str);

	void delTitles(vector< vector<double> > &sarr);

	void readData(const string &filename,
		const string &csvdelimiter,
		vector< vector<double> > &sarr,
		int numY, int numX);

	void readVector( const string &filename,
		const string &csvdelimiter,
		vector<bool> &sarr,
		int numY );

	bool stringToBool(const string &str);
};

