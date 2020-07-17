#ifndef DOT_H
#define DOT_H
#include <iostream>
#include <cctype>
#include <sstream>
#include "vector.h"
using namespace std;

//StringToVector

void strip(string &s, string target, string st)
{
	int t = s.find_first_of(target);
	while (t != string::npos)
	{
		s.replace(t, 1, st);
		t = s.find_first_of(target);
	}
}

void checkString(string s)
{
	if (s.compare(0, 1, "(") != 0)
		throw 0;
	if (s.compare(s.size() - 1, 1, ")") != 0)
		throw 0;
	for (int i = 1; i < s.size() - 1; i++)
	{
		if (s[i] != ',' && (!isdigit(s[i])) && s[i] != '.')
			throw 0;
		if (s[i] == ',')
			if ((!isdigit(s[i - 1])) || (!isdigit(s[i + 1])))
				throw 0;
	}
}

string organizeString(string &s)
{
	strip(s, " ", "");

	checkString(s);

	strip(s, "(", "");
	strip(s, ")", "");
	strip(s, ",", " ");
	return s;
}

Vector createVectorFromStringOfNumbers(string s, int dim)
{
	organizeString(s);
	stringstream ss(s);
	double data[dim];
	int i = 0;
	while (ss >> data[i])
		i++;
	if (i != dim)
		throw 0;

	return Vector(data, i);
}

//VectorToString

string toString(Vector v)
{
	stringstream ss;
	ss << "(";
	for (int i = 1; i < v.dim(); i++)
	{
		ss << v.at(i) << ","
		   << " ";
	}
	ss << v.at(v.dim()) << ")";
	return ss.str();
}

//CalculateSubstract

string substractAnswer(Vector u, Vector v)
{
	stringstream ss;
	ss << "Difference between these two Vecotrs : " << toString(u - v);
	return ss.str();
}

//CalculateSum

string sumAnswer(Vector u, Vector v)
{
	stringstream ss;
	ss << "Sum of these two Vectors: " << toString(u + v);
	return ss.str();
}

//CalculateDot

double dot(Vector u, Vector v)
{
	int dim = u.dim();
	int temp = 0;
	for (size_t i = 1; i <= dim; i++)
	{
		temp += u.at(i) * v.at(i);
	}
	return temp;
}

string dotAnswer(Vector u, Vector v, int dim)
{
	stringstream ss;
	ss << "Inner product of these two Vectors: " << dot(u, v);
	return ss.str();
}

#endif