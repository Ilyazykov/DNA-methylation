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

	void splitString(const string &fullstr, vector<string> &elements, const string &delimeter)
	{
		string::size_type lastpos =
			fullstr.find_first_not_of(delimeter, 0);
		string::size_type pos =
			fullstr.find_first_of(delimeter, lastpos);

		while ( (string::npos != pos) || (string::npos != lastpos) ) {

			elements.push_back(fullstr.substr(lastpos, pos-lastpos));

			lastpos = fullstr.find_first_not_of(delimeter, pos);
			pos = fullstr.find_first_of(delimeter, lastpos);
		}
	}

	double stringToDouble(const string &str) {

		istringstream stm;
		double val = 0;

		stm.str(str);
		stm >> val;

		return val;
	}

	void readData(const string &filename,
		const string &csvdelimiter,
		vector< vector<double> > &sarr,
		int numX, int numY) 
	{
		ifstream fin(filename.c_str());
		
		string s;
		vector<string> selements;
		vector<double> delements;

		int x = 0; //temp
		while ( !fin.eof() ) 
		{
			getline(fin, s);

			if ( !s.empty() ) 
			{
				splitString(s, selements, csvdelimiter);

				for ( size_t i=0; i<selements.size(); i++ ) 
				{
					delements.push_back(stringToDouble(selements[i]));

					if (i>=numY) break; //temp
				}

				sarr.push_back(delements);
				selements.clear();
				delements.clear();
			}

			x++;//temp
			if (x>=numX) break;//temp
		}

		fin.close();
	}
};

