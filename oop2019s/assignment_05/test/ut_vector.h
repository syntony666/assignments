#include <gtest/gtest.h>
#include "../src/vector.h"
#include "../src/dot.h"
#include <cmath>

#define EPS 0.001

TEST(Input, inputRight)
{
	string s = "(3,9.3,5)";
	ASSERT_NO_THROW(checkString(s));
}

TEST(Input, organizeString)
{
	string s = "(3 ,9 ,5)";
	ASSERT_EQ("3 9 5", organizeString(s));
}

TEST(Input, inputExpection1)
{
	string s = "3,9,5)";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputExpection2)
{
	string s = "(3,9,5";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputExpection3)
{
	string s = "(,,3,9,5,)";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputExpection4)
{
	string s = "(3,9,5,)";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputExpection5)
{
	string s = "(3,9,5]";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputExpection6)
{
	string s = "[3,9,5)";
	ASSERT_ANY_THROW(organizeString(s));
}

TEST(Input, inputAndDimExpection)
{
	string s = "(3,9,5)";
	ASSERT_ANY_THROW(createVectorFromStringOfNumbers(s, 2));
}

TEST(Input, toVector)
{
	string s = "(3,9.6,5)";
	Vector v = createVectorFromStringOfNumbers(s, 3);
	ASSERT_NEAR(3, v.dim(), EPS);
	ASSERT_NEAR(3, v.at(1), EPS);
	ASSERT_NEAR(9.6, v.at(2), EPS);
	ASSERT_NEAR(5, v.at(3), EPS);
}

TEST(Calculate, dot)
{
	double data1[] = {1, 6, 3};
	double data2[] = {9, 7, 5};
	Vector x(data1, 3);
	Vector y(data2, 3);
	ASSERT_NEAR(66, dot(x, y), EPS);
}

TEST(Output, toString)
{
	double data[] = {1, 6, 3};
	Vector x(data, 3);
	ASSERT_EQ("(1, 6, 3)", toString(x));
}

TEST(Output, sumOutput)
{
	string v1 = "(2,1,3)";
	string v2 = "(3,2,1)";
	Vector u = createVectorFromStringOfNumbers(v1, 3);
	Vector v = createVectorFromStringOfNumbers(v2, 3);
	ASSERT_EQ("Sum of these two Vectors: (5, 3, 4)", sumAnswer(u, v));
}

TEST(Output, substractOutput)
{
	string v1 = "(2,1,3)";
	string v2 = "(3,2,1)";
	Vector u = createVectorFromStringOfNumbers(v1, 3);
	Vector v = createVectorFromStringOfNumbers(v2, 3);
	ASSERT_EQ("Difference between these two Vecotrs : (-1, -1, 2)", substractAnswer(u, v));
}

TEST(Output, dotOutput)
{
	string v1 = "(2,1,3)";
	string v2 = "(3,2,1)";
	Vector u = createVectorFromStringOfNumbers(v1, 3);
	Vector v = createVectorFromStringOfNumbers(v2, 3);
	ASSERT_EQ("Inner product of these two Vectors: 11", dotAnswer(u, v, 3));
}