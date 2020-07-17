#include <gtest/gtest.h>
#include "../src/dot.h"
#include <cmath>

#define EPS 0.001

TEST(VectorTest, Centroid)
{
	double a[] = {0, 0};
	double b[] = {2, 0};
	double c[] = {2, 2};
	double d[] = {1, 3};
	double e[] = {0, 2};
	Vector u(a, 2);
	Vector v(b, 2);
	Vector x(c, 2);
	Vector y(d, 2);
	Vector z(e, 2);
	Vector arr[] = {u, v, x, y, z};
	Vector cent = centroid(arr, 5);
	ASSERT_NEAR(1, cent.at(1), EPS);
	ASSERT_NEAR(7.0 / 5.0, cent.at(2), EPS);
	ASSERT_EQ(2, cent.dim());
}

TEST(VectorTest, InnerProduct)
{
	double a[] = {1, 0, 2};
	double b[] = {1, 1, 3};
	Vector x(a, 3);
	Vector y(b, 3);
	ASSERT_NEAR(1, x.at(1), EPS);
	ASSERT_NEAR(0, x.at(2), EPS);
	ASSERT_NEAR(2, x.at(3), EPS);
	ASSERT_EQ(3, x.dim());
	ASSERT_EQ(7, dot(x, y));
}

TEST(VectorTest, InnerProductException)
{
	double a[] = {1, 0, 2};
	double b[] = {1, 1, 3, 4};
	Vector x(a, 3);
	Vector y(b, 4);
	ASSERT_ANY_THROW(dot(x, y));
}

TEST(VectorTest, CrossProduct)
{
	double a[] = {1, 2};
	double b[] = {1, 3};
	Vector x(a, 2);
	Vector y(b, 2);
	ASSERT_NEAR(1, cross(x, y), EPS);
}

TEST(VectorTest, CrossProductException)
{
	double a[] = {1, 0, 2};
	double b[] = {1, 1, 3};
	Vector x(a, 3);
	Vector y(b, 3);
	ASSERT_ANY_THROW(cross(x, y));
}

TEST(VectorTest, angle)
{
	double a[] = {1, 0};
	double b[] = {1, 1};
	Vector x(a, 2);
	Vector y(b, 2);
	ASSERT_NEAR(M_PI / 4, angle(x, y), EPS);
}

TEST(VectorTest, angle2)
{
	double a[] = {1, 0};
	double b[] = {1, 1};
	Vector x(a, 2);
	Vector y(b, 2);
	ASSERT_NEAR(7 * M_PI / 4, angle(y, x), EPS);
}

TEST(VectorTest, angle3)
{
	double a[] = {1, 0};
	double b[] = {-1, -1};
	Vector x(a, 2);
	Vector y(b, 2);
	ASSERT_NEAR(5 * M_PI / 4, angle(x, y), EPS);
}

TEST(VectorTest, vectorBetweenCentroid)
{
	double a[] = {0, 0};
	double b[] = {2, 0};
	double c[] = {2, 2};
	double d[] = {1, 3};
	double e[] = {0, 2};
	Vector u(a, 2);
	Vector v(b, 2);
	Vector x(c, 2);
	Vector y(d, 2);
	Vector z(e, 2);
	Vector arr[] = {u, v, x, y, z};
	vectorBetweenCentroid(arr, centroid(arr, 5), 5);
	ASSERT_NEAR(0 - 1, arr[0].at(1), EPS);
	ASSERT_NEAR(0 - 7.0 / 5.0, arr[0].at(2), EPS);
	ASSERT_NEAR(2 - 1, arr[1].at(1), EPS);
	ASSERT_NEAR(0 - 7.0 / 5.0, arr[1].at(2), EPS);
	ASSERT_NEAR(2 - 1, arr[2].at(1), EPS);
	ASSERT_NEAR(2 - 7.0 / 5.0, arr[2].at(2), EPS);
	ASSERT_NEAR(1 - 1, arr[3].at(1), EPS);
	ASSERT_NEAR(3 - 7.0 / 5.0, arr[3].at(2), EPS);
	ASSERT_NEAR(0 - 1, arr[4].at(1), EPS);
	ASSERT_NEAR(2 - 7.0 / 5.0, arr[4].at(2), EPS);
	ASSERT_EQ(2, arr[0].dim());
}

TEST(VectorTest, bubbleSort)
{
	int arr[] = {3, 2, 5, 7, 0};
	bubbleSort(arr, arr + 5, [](int a, int b) { return a > b; });
	ASSERT_EQ(7, arr[0]);
	ASSERT_EQ(5, arr[1]);
	ASSERT_EQ(3, arr[2]);
	ASSERT_EQ(2, arr[3]);
	ASSERT_EQ(0, arr[4]);
}

TEST(VectorTest, vectorBubbleSort)
{
	double a[] = {0, 0};
	double b[] = {2, 0};
	double c[] = {2, 2};
	double d[] = {1, 3};
	double e[] = {0, 2};
	Vector u(a, 2);
	Vector v(b, 2);
	Vector x(c, 2);
	Vector y(d, 2);
	Vector z(e, 2);
	Vector arr[] = {u, z, v, x, y};
	vectorBetweenCentroid(arr, centroid(arr, 5), 5);
	bubbleSort(arr + 1, arr + 5, [arr](Vector u, Vector v) { return angle(*arr, u) < angle(*arr, v); });
	ASSERT_NEAR(0 - 1, arr[0].at(1), EPS);
	ASSERT_NEAR(0 - 7.0 / 5.0, arr[0].at(2), EPS);
	ASSERT_NEAR(2 - 1, arr[1].at(1), EPS);
	ASSERT_NEAR(0 - 7.0 / 5.0, arr[1].at(2), EPS);
	ASSERT_NEAR(2 - 1, arr[2].at(1), EPS);
	ASSERT_NEAR(2 - 7.0 / 5.0, arr[2].at(2), EPS);
	ASSERT_NEAR(1 - 1, arr[3].at(1), EPS);
	ASSERT_NEAR(3 - 7.0 / 5.0, arr[3].at(2), EPS);
	ASSERT_NEAR(0 - 1, arr[4].at(1), EPS);
	ASSERT_NEAR(2 - 7.0 / 5.0, arr[4].at(2), EPS);
	ASSERT_EQ(2, arr[0].dim());
}

TEST(VectorTest, convexPolygonArea)
{
	double a[] = {2, 4};
	double b[] = {7, 0};
	double c[] = {0, 2};
	double d[] = {6, 4};
	double e[] = {1, 0};
	double f[] = {8, 2};
	Vector u(a, 2);
	Vector v(b, 2);
	Vector w(c, 2);
	Vector x(d, 2);
	Vector y(e, 2);
	Vector z(f, 2);
	Vector arr[] = {u, v, w, x, y, z};
	ASSERT_NEAR(26, convexPolygonArea(arr, 6), EPS);
}