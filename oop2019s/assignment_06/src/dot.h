#ifndef DOT_H
#define DOT_H
#include "vector.h"
#include "bubble_sort.h"
#include <cmath>

Vector centroid(Vector vec[], int sides)
{
	int dim = vec[0].dim();
	double data[dim];
	for (int i = 0; i < dim; i++)
		data[i] = 0;
	Vector center(data, dim);
	for (int i = 0; i < sides; i++)
		center = center + vec[i];
	for (int i = 1; i <= dim; i++)
		center.at(i) /= sides;
	return center;
}

double dot(Vector u, Vector v)
{
	if (u.dim() != v.dim())
		throw std::string("Can't do");
	double temp = 0;
	for (int i = 1; i <= u.dim(); i++)
		temp += u.at(i) * v.at(i);
	return temp;
}

double cross(Vector u, Vector v)
{
	if (u.dim() != 2 || v.dim() != 2)
		throw std::string("Can't do");
	return u.at(1) * v.at(2) - u.at(2) * v.at(1);
}

double angle(Vector u, Vector v)
{
	if (cross(u, v) >= 0)
		return acos(dot(u, v) / (u.length() * v.length()));
	else
		return 2 * M_PI - acos(dot(u, v) / (u.length() * v.length()));
}

void vectorBetweenCentroid(Vector vec[], Vector center, int sides)
{
	for (int i = 0; i < sides; i++)
		vec[i] = vec[i] - center;
}

double convexPolygonArea(Vector vec[], int sides)
{
	vectorBetweenCentroid(vec, centroid(vec, sides), sides);
	bubbleSort(vec + 1, vec + sides, [vec](Vector u, Vector v) { return angle(*vec, u) < angle(*vec, v); });
	return area(vec, sides);
}

#endif