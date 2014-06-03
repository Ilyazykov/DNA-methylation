#include "SVreader.h"


CSVreader::CSVreader(void)
{
}


CSVreader::~CSVreader(void)
{
}

void CSVreader::splitString( const string &fullstr, vector<string> &elements, const string &delimeter )
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

double CSVreader::stringToDouble( const string &str )
{
	istringstream stm;
	double val = 0;

	stm.str(str);
	stm >> val;

	return val;
}

void CSVreader::delTitles( vector< vector<double> > &sarr )
{
	sarr.erase(sarr.begin());
	for ( size_t i=0; i<sarr.size(); i++ ) 
	{
		sarr[i].erase(sarr[i].begin());
	}
}

void CSVreader::readData( const string &filename, const string &csvdelimiter, vector< vector<double> > &sarr, int numY, int numX )
{
	numY++; numX;
	ifstream fin(filename.c_str());

	string s;
	vector<string> selements;
	vector<double> delements;

	int x = 0;
	while ( !fin.eof() ) 
	{
		getline(fin, s);

		if ( !s.empty() ) 
		{
			splitString(s, selements, csvdelimiter);

			for ( int i=0; i<selements.size(); i++ ) 
			{
				delements.push_back(stringToDouble(selements[i]));

				if (i>=numX) break;
			}

			sarr.push_back(delements);
			selements.clear();
			delements.clear();
		}

		x++;
		if (x>=numY) break;
	}

	fin.close();
}

void CSVreader::readVector( const string &filename, const string &csvdelimiter, vector<bool> &sarr, int numY )
{
	numY++;
	ifstream fin(filename.c_str());

	string s;
	vector<string> selements;
	//vector<double> delements;

	int x = 0;
	while ( !fin.eof() ) 
	{
		getline(fin, s);

		if ( !s.empty() ) 
		{
			splitString(s, selements, csvdelimiter);

			sarr.push_back(stringToBool(selements[1]));
			selements.clear();
			//delements.clear();
		}

		x++;
		if (x>=numY) break;
	}

	fin.close();
}

bool CSVreader::stringToBool( const string &str )
{
	if (str == "TRUE") return true;
	else return false;
}
