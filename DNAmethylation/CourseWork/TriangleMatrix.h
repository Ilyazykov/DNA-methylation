#pragma once
#include <vector>
using namespace std;

template <class T>
class TriangleMatrix
{
	vector< vector<T> > mat;
public:
	TriangleMatrix(int size)
	{
		mat.resize(size - 1);

		for (int i = 0; i < mat.size(); i++)
		{
			int s = mat.size() - i;
			mat[i].resize(s);
		}
	}

	void addElem(T elem, int x, int y)
	{
		if (x==y) return;

		if (x > y) {
			swap(x, y);
		}

		mat[x][mat.size() - y] = elem;
	}

	T get(int x, int y)
	{
		if (x==y) return 0;

		if (x>y) swap(x, y);

		int yy = mat.size() - y;
		return mat[x][yy];
	}

	~TriangleMatrix()
	{

	}

};