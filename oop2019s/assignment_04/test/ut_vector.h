#include <gtest/gtest.h>
#include "../src/vector.h"
#include <cmath>

#define EPS 0.001

TEST(Vector, Constructor)
{
	double data[] = {9, 6, 5};
	Vector v(data, 3);
	ASSERT_EQ(3, v.dim());
	ASSERT_NEAR(9, v.at(1), EPS);
	ASSERT_NEAR(6, v.at(2), EPS);
	ASSERT_NEAR(5, v.at(3), EPS);
}

TEST(Vector, AtException)
{
	double data[] = {9, 6, 5};
	Vector v(data, 3);
	ASSERT_ANY_THROW(v.at(4));
	ASSERT_ANY_THROW(v.at(0));
	ASSERT_ANY_THROW(v.at(-2));
}

TEST(Vector, length)
{
	double data[] = {3, 4, 5};
	Vector v(data, 3);
	ASSERT_NEAR(sqrt(50), v.length(), EPS);
}

TEST(Calculate, Subtract)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	u.subtract(v);
	ASSERT_NEAR(-6, u.at(1), EPS);
	ASSERT_NEAR(1, u.at(2), EPS);
	ASSERT_NEAR(0, u.at(3), EPS);
}

TEST(Calculate, SubtractExpection)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5, 9};
	Vector u(data1, 3);
	Vector v(data2, 4);
	ASSERT_ANY_THROW(u.subtract(v));
}

TEST(Calculate, Add)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	u.add(v);
	ASSERT_NEAR(12, u.at(1), EPS);
	ASSERT_NEAR(13, u.at(2), EPS);
	ASSERT_NEAR(10, u.at(3), EPS);
}

TEST(Calculate, AddExpection)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5, 9};
	Vector u(data1, 3);
	Vector v(data2, 4);
	ASSERT_ANY_THROW(u.add(v));
}

TEST(Operator, Assign_1)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	u = v;
	ASSERT_NEAR(9, u.at(1), EPS);
	ASSERT_NEAR(6, u.at(2), EPS);
	ASSERT_NEAR(5, u.at(3), EPS);
}

TEST(Operator, Assign_2)
{
	double data1[] = {3, 7, 5, 7};
	double data2[] = {9, 6, 5};
	Vector u(data1, 4);
	Vector v(data2, 3);
	u = v;
	ASSERT_NEAR(9, u.at(1), EPS);
	ASSERT_NEAR(6, u.at(2), EPS);
	ASSERT_NEAR(5, u.at(3), EPS);
}

TEST(Operator, Subtract)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	Vector w = u - v;
	ASSERT_NEAR(-6, w.at(1), EPS);
	ASSERT_NEAR(1, w.at(2), EPS);
	ASSERT_NEAR(0, w.at(3), EPS);
}

TEST(Operator, SubtractExpection)
{
	double data1[] = {3, 7, 5, 9};
	double data2[] = {9, 6, 5};
	Vector u(data1, 4);
	Vector v(data2, 3);
	ASSERT_ANY_THROW(u - v);
}

TEST(Operator, Add)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	Vector w = u + v;
	ASSERT_NEAR(12, w.at(1), EPS);
	ASSERT_NEAR(13, w.at(2), EPS);
	ASSERT_NEAR(10, w.at(3), EPS);
}

TEST(Operator, AddExpection)
{
	double data1[] = {3, 7, 5, 9};
	double data2[] = {9, 6, 5};
	Vector u(data1, 4);
	Vector v(data2, 3);
	ASSERT_ANY_THROW(u + v);
}

TEST(Calculate, Distance)
{
	double data1[] = {3, 7, 5};
	double data2[] = {9, 6, 5};
	Vector u(data1, 3);
	Vector v(data2, 3);
	ASSERT_NEAR(sqrt(37), distance(u, v), EPS);
}
TEST(Calaulate, TriangleArea)
{
	double data1[] = {5, 0};
	double data2[] = {10, 0};
	double data3[] = {9, 6};
	Vector u(data1, 2);
	Vector v(data2, 2);
	Vector w(data3, 2);
	ASSERT_NEAR(15, area(u, v, w), EPS);
}

TEST(Calaulate, QuadrilateralArea)
{
	double data1[] = {5, 0};
	double data2[] = {10, 0};
	double data4[] = {9, 6};
	double data3[] = {8, 6};
	Vector u(data1, 2);
	Vector v(data2, 2);
	Vector w(data3, 2);
	Vector x(data4, 2);
	Vector a[] = {u, v, w, x};
	ASSERT_NEAR(18, area(a, 4), EPS);
}

TEST(Calaulate, PentagonArea)
{
	double data1[] = {0, 0};
	double data2[] = {2, 0};
	double data3[] = {2, 2};
	double data4[] = {1, 3};
	double data5[] = {0, 2};
	Vector u(data1, 2);
	Vector v(data2, 2);
	Vector w(data3, 2);
	Vector x(data4, 2);
	Vector y(data5, 2);
	Vector a[] = {u, v, w, x, y};
	ASSERT_NEAR(5, area(a, 5), EPS);
}

TEST(Calaulate, TrianglePerimeter)
{
	double data1[] = {0, 0};
	double data2[] = {2, 0};
	double data3[] = {2, 2};
	Vector u(data1, 2);
	Vector v(data2, 2);
	Vector w(data3, 2);
	Vector a[] = {u, v, w};
	ASSERT_NEAR(4 + 2 * sqrt(2), perimeter(a, 3), EPS);
}

TEST(Calaulate, PentagonPerimeter)
{
	double data1[] = {0, 0};
	double data2[] = {2, 0};
	double data3[] = {2, 2};
	double data4[] = {1, 3};
	double data5[] = {0, 2};
	Vector u(data1, 2);
	Vector v(data2, 2);
	Vector w(data3, 2);
	Vector x(data4, 2);
	Vector y(data5, 2);
	Vector a[] = {u, v, w, x, y};
	ASSERT_NEAR(6 + 2 * sqrt(2), perimeter(a, 5), EPS);
}