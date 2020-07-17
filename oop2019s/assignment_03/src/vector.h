#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
  public:
	Vector(double v[], int dim)
	{
		_dim = dim;
		_v = new double[dim];
		for (int i = 0; i < dim; i++)
			_v[i] = v[i];
	}
	int dim()
	{
		return _dim;
	}
	bool isZero()
	{
		for (int i = 0; i < _dim; i++)
		{
			if (_v[i] != 0)
				return false;
		}
		return true;
	}
	double length()
	{
		double temp = 0;
		for (int i = 0; i < _dim; i++)
		{
			temp += pow(_v[i], 2);
		}
		return sqrt(temp);
	}
	double at(int i)
	{
		i -= 1;
		if (i > _dim)
		{
			throw string("Can't Find!!!");
		}
		if (i < 0)
		{
			throw string("Dimension can't be negative!!!");
		}
		return _v[i];
	}

  private:
	double *_v;
	int _dim;
};

#endif