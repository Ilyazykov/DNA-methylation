#pragma once
#include <vector>
#include <exception>
using namespace std;

template <class T>
class TriangleMatrix
{
	vector< vector<T> > mat;
public:
	TriangleMatrix(int size = 2)
	{
		mat.resize(size - 1);

		for (int i = 0; i < mat.size(); i++)
		{
			int s = mat.size() - i;
			mat[i].resize(s);
		}
	}

	void resize(int size)
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

		int yy = mat.size() - y;
		mat[x][yy] = elem;
	}

	T& operator() (int x, int y)
	{
		if (x==y) throw new exception("x==y");

		if (x > y) {
			swap(x, y);
		}

		int yy = mat.size() - y;
		return mat[x][yy];
	}

	T& get(int x, int y)
	{
		if (x==y) throw new exception("x==y");

		if (x>y) swap(x, y);

		int yy = mat.size() - y;
		return mat[x][yy];
	}

	~TriangleMatrix()
	{

	}

};