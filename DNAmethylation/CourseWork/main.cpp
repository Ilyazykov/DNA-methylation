#include <iostream>
#include <list>
#include <vector>
using namespace std;

void main()
{
	cout << "Hello, world!";

	vector<vector<double> > a(3, 3);
	a[0][0] = 1;
	a[2][2] = 1;

	cout << a[1][0];

	cin.get();
}