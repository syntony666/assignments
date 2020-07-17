#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
class Vector
{
  public:
	//default constructor
	Vector() : _dim(-1), _v(nullptr) {}

	Vector(double v[], int dim) : _dim(dim), _v(nullptr)
	{
		copy(v);
	}

	//copy constructor
	Vector(Vector const &v) : _dim(v._dim), _v(nullptr)
	{
		copy(v._v);
	}

	// destructor
	~Vector()
	{
		if (_v != nullptr)
			delete[] _v;
	}

	// constant member function
	int dim() const
	{
		return _dim;
	}

	double &at(int i) const
	{
		if (i > _dim)
			throw std::string("Overflow");
		if (i <= 0)
			throw std::string("Not Negative");
		return _v[i - 1];
	}

	void subtract(Vector const &v)
	{
		if (_dim != v._dim)
			throw std::string("Different Dimension");
		for (int i = 0; i < _dim; i++)
			_v[i] -= v._v[i];
	}

	void add(Vector const &v)
	{
		if (_dim != v._dim)
			throw std::string("Different Dimension");
		for (int i = 0; i < _dim; i++)
			_v[i] += v._v[i];
	}

	Vector &operator=(Vector const &u)
	{
		_dim = u._dim;
		copy(u._v);
		return *this;
	}

	Vector operator-(Vector const &v) const
	{
		Vector u(*this);
		u.subtract(v);
		return u;
	}

	Vector operator+(Vector const &v) const
	{
		Vector u(*this);
		u.add(v);
		return u;
	}

	double length() const
	{
		double temp = 0;
		for (int i = 0; i < _dim; i++)
			temp += pow(_v[i], 2);
		return sqrt(temp);
	}

  private:
	int _dim;
	double *_v;
	void copy(double v[])
	{
		_v = new double[_dim];
		for (int i = 0; i < _dim; i++)
			_v[i] = v[i];
	}
};

double distance(Vector const &u, Vector const &v)
{
	Vector w = u - v;
	return w.length();
}

double area(Vector const &u, Vector const &v, Vector const &w)
{
	double a = distance(u, v);
	double b = distance(u, w);
	double c = distance(v, w);
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(Vector a[], int sides)
{
	double temp = 0;
	for (int i = 2; i < sides; i++)
		temp += area(a[0], a[i - 1], a[i]);
	return temp;
}

double perimeter(Vector a[], int sides)
{
	double temp;
	for (int i = 1; i < sides; i++)
		temp += distance(a[i - 1], a[i]);
	temp += distance(a[0], a[sides - 1]);
	return temp;
}

#endif
