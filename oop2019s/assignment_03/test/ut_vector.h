#include "../src/vector.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(ClassVector, Dim)
{
	double data[] = {11, 22, 33, 44};
	Vector v = Vector(data, 4);
	ASSERT_EQ(4, v.dim());
}

TEST(ClassVector, isZero_True)
{
	double data[] = {0, 0, 0, 0};
	Vector v = Vector(data, 4);
	ASSERT_TRUE(v.isZero());
}

TEST(ClassVector, isZero_False)
{
	double data[] = {3, -9, 8, 6};
	Vector v = Vector(data, 4);
	ASSERT_FALSE(v.isZero());
}

TEST(ClassVector, length)
{
	double data[] = {6, 9, 5, -7, 6};
	Vector v = Vector(data, 5);
	ASSERT_NEAR(sqrt(227), v.length(), 0.001);
}

TEST(ClassVector, at_Exist)
{
	double data[] = {9, 6, 7, 5, 6, 3, 2, 4, 6};
	Vector v = Vector(data, 9);
	ASSERT_NEAR(6, v.at(5), 0.001);
}

TEST(ClassVector, at_NotExist)
{
	double data[] = {9, 6, 7, 5, 6, 3, 2, 4, 6};
	Vector v = Vector(data, 9);
	ASSERT_ANY_THROW(v.at(20));
}

TEST(ClassVector, at_isNagetive)
{
	double data[] = {9, 6, 7, 5, 6, 3, 2, 4, 6};
	Vector v = Vector(data, 9);
	ASSERT_ANY_THROW(v.at(-9));
}