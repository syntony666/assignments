#include "../src/vector.h"
#include "../src/dot.h"
#include <gtest/gtest.h>
#include <cmath>
TEST(InnerProduct, Dot1)
{
    int u[3] = {1, 0, 2};
    int v[3] = {1, 1, 3};

    ASSERT_EQ(7, dot(u, v, 3, 3));
}

TEST(InnerProduct, Dot2)
{
    int u[4] = {0, 0, 0, 207878};
    int v[4] = {948787, 14654, 3, 0};

    ASSERT_EQ(0, dot(u, v, 4, 4));
}

TEST(InnerProduct, Exception1)
{
    int u[] = {1, 0, 2, 9};
    int v[] = {1, 1, 3};

    ASSERT_ANY_THROW(dot(u, v, 4, 3));
}

TEST(InnerProduct, Exception2)
{
    int u[] = {1, 0, 2, 4, 7154, 46546, 85333};
    int v[] = {1};

    ASSERT_ANY_THROW(dot(u, v, 7, 1));
}

TEST(VectorTest, GetDim1)
{
    double data[3] = {2, 3, 4};
    Vector vector(data, 3);

    ASSERT_EQ(3, getDim(vector));
}

TEST(VectorTest, GetDim2)
{
    double data[20] = {2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 3};
    Vector vector(data, 20);

    ASSERT_EQ(20, getDim(vector));
}

TEST(VectorTest, IsZero1)
{
    double data[3] = {2.5, 3.4, 4.2};
    Vector vector(data, 3);

    ASSERT_FALSE(isZero(vector));
}

TEST(isZero, ZeroVector)
{
    double data[3] = {0, 0, 0};
    Vector vector(data, 3);

    ASSERT_TRUE(isZero(vector));
}

TEST(VectorTest, IsZero3)
{
    double data[3] = {4894, 0, 68524};
    Vector vector(data, 3);

    ASSERT_FALSE(isZero(vector));
}

TEST(VectorTest, Length1)
{
    double data[3] = {3, 4, 5};
    Vector vector(data, 3);

    ASSERT_NEAR(sqrt(50), length(vector), 0.001);
}

TEST(VectorTest, Length2)
{
    double data[3] = {1, 1, 3};
    Vector vector(data, 3);

    ASSERT_NEAR(sqrt(11), length(vector), 0.001);
}
