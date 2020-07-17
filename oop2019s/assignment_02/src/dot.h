#include <string>
#include <cmath>
#include "vector.h"
int dot(int u[], int v[], int m, int n)
{
    if (m != n)
    {
        throw std::string("Can't do");
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += u[i] * v[i];
    return sum;
}

bool isZero(Vector v)
{
    for (int i = 0; i < v._dim; i++)
    {
        if (v._v[i] != 0)
        {
            return false;
        }
    }
    return true;
}

double length(Vector v)
{
    double temp = 0;
    for (int i = 0; i < v._dim; i++)
    {
        temp += (v._v[i] * v._v[i]);
    }
    return sqrt(temp);
}
int getDim(Vector v)
{
    return v._dim;
}
