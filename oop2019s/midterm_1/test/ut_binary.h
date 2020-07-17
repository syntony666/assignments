#include <gtest/gtest.h>
#include "../src/binary.h"
#include <cmath>

#define EPS 0.001

TEST(Binary, ConstructorEmptyArray)
{
	Binary bin = Binary();
	ASSERT_ANY_THROW(bin.checkEmpty());
}

TEST(Binary, ConstructorFromArray)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	ASSERT_EQ(4, bin.bit());
	ASSERT_EQ(1, bin.element(0));
	ASSERT_EQ(1, bin.element(1));
	ASSERT_EQ(0, bin.element(2));
	ASSERT_EQ(1, bin.element(3));
}

TEST(Binary, ConstructorFromBinary)
{
	int bits[4] = {1, 1, 0, 1};
	Binary temp(bits, 4);
	Binary bin(temp);
	ASSERT_EQ(4, bin.bit());
	ASSERT_EQ(1, bin.element(0));
	ASSERT_EQ(1, bin.element(1));
	ASSERT_EQ(0, bin.element(2));
	ASSERT_EQ(1, bin.element(3));
}

TEST(Binary, resize)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	bin.resize(8);
	ASSERT_EQ(8, bin.bit());
	ASSERT_EQ(0, bin.element(0));
	ASSERT_EQ(0, bin.element(1));
	ASSERT_EQ(0, bin.element(2));
	ASSERT_EQ(0, bin.element(3));
	ASSERT_EQ(1, bin.element(4));
	ASSERT_EQ(1, bin.element(5));
	ASSERT_EQ(0, bin.element(6));
	ASSERT_EQ(1, bin.element(7));
}

TEST(Binary, resize2)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	bin.resize(5);
	ASSERT_EQ(5, bin.bit());
	ASSERT_EQ(0, bin.element(0));
	ASSERT_EQ(1, bin.element(1));
	ASSERT_EQ(1, bin.element(2));
	ASSERT_EQ(0, bin.element(3));
	ASSERT_EQ(1, bin.element(4));
}

TEST(Binary, resizeException)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	ASSERT_ANY_THROW(bin.resize(2));
}

TEST(Binary, toInt)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	ASSERT_EQ(13, bin.toInt());
}

TEST(Binary, toIntException)
{
	Binary bin;
	ASSERT_ANY_THROW(bin.toInt());
}

TEST(Binary, toString)
{
	int bits[4] = {1, 1, 0, 1};
	Binary bin(bits, 4);
	ASSERT_EQ("1101", bin.toString());
}

TEST(Binary, toStringException)
{
	Binary bin;
	ASSERT_ANY_THROW(bin.toString());
}

TEST(Binary, setBit)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);
	bin.setBit(2, 1);
	ASSERT_EQ("111100", bin.toString());
}

TEST(Binary, setBitPosExpection)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);

	ASSERT_ANY_THROW(bin.setBit(7, 1));
}

TEST(Binary, setBitPosExpection2)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);

	ASSERT_ANY_THROW(bin.setBit(-1, 1));
}

TEST(Binary, setBitDataExpection)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);

	ASSERT_ANY_THROW(bin.setBit(2, -1));
}

TEST(Binary, operatorLeft)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);
	bin << 2;
	ASSERT_EQ("010000", bin.toString());
}

TEST(Binary, operatorRight)
{
	int bits[] = {1, 1, 0, 1, 0, 0};
	Binary bin(bits, 6);
	bin >> 2;
	ASSERT_EQ("001101", bin.toString());
}

TEST(Binary, OperatorAssignment)
{
	int bits[4] = {1, 1, 0, 1};
	Binary temp(bits, 4);
	Binary bin = temp;
	ASSERT_EQ(4, bin.bit());
	ASSERT_EQ(1, bin.element(0));
	ASSERT_EQ(1, bin.element(1));
	ASSERT_EQ(0, bin.element(2));
	ASSERT_EQ(1, bin.element(3));
}

TEST(Binary, OperatorAdd)
{
	int data1[] = {1, 1, 0, 1, 1};
	int data2[] = {1, 0, 0, 1};
	Binary bin1(data1, 5);
	Binary bin2(data2, 4);
	Binary bin = bin1 + bin2;
	ASSERT_EQ(6, bin.bit());
	ASSERT_EQ("100100", bin.toString());
}

TEST(Binary, OperatorSubstract)
{
	int data1[] = {1, 0, 0, 1, 0};
	int data2[] = {1, 1, 1, 0};
	Binary bin1(data1, 5);
	Binary bin2(data2, 4);
	Binary bin = bin1 - bin2;
	ASSERT_EQ(5, bin.bit());
	ASSERT_EQ("00100", bin.toString());
}