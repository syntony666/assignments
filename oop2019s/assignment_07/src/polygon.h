#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "vector.h"
#include "dot.h"

class Polygon : public Shape
{
  public:
	Polygon() : _sides(-1), _vec(nullptr) {}

	Polygon(Vector vec[], int sides) : _sides(sides), _vec(nullptr)
	{
		copy(vec);
	}

	~Polygon()
	{
		if (_vec != nullptr)
			delete[] _vec;
	}

	double perimeter() const
	{
		pointsInOrder(_vec, _sides);
		return ::perimeter(_vec, _sides);
	}
	double area() const
	{
		pointsInOrder(_vec, _sides);
		return ::area(_vec, _sides);
	}

  private:
	Vector *_vec;
	int _sides;
	void copy(Vector vec[])
	{
		_vec = new Vector[_sides];
		for (int i = 0; i < _sides; i++)
			_vec[i] = vec[i];
	}
};

#endif