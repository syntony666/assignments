#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "shape.h"

class Circle : public Shape
{
  private:
	double _r;

  public:
	Circle() : _r(0) {}
	Circle(double r) : _r(r) {}

	double perimeter() const
	{
		return 2 * _r * M_PI;
	}

	double area() const
	{
		return pow(_r, 2) * M_PI;
	}
};

#endif