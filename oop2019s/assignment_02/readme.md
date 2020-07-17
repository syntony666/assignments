# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 2

### Due: 11:59 p.m., 13 March 2019


**For this assignment, please put all your tests in test/ut_vector.h, all your functions in src/dot.h and set the output file to bin/ut_all**


### Purpose of this assignment:
Let students practice for the basic function use and test.

### Problems:

In class, you have learned and written the simple class vector and function dot. For this assignment, you have to write some basic function for vector, and test it!

Please implement and test the method for the following functions:

- dot(10%)
- isZero (30%)
- length (30%)
- getDim (30%)  
(For those functions, you have to write at least one test for yourself. )

we will provide sample code for this assignment

**src/dot.h**

	#include <string>
	#include <cmath>
	int dot(int u[], int v[], int m, int n) {
	  if (m != n) {
	    throw std::string("Can't do");
	  }
	  int sum = 0;
	  for (int i = 0; i < n; i++)
	    sum += u[i] * v[i];
	  return sum;
	}
	//the rest of function should be written below

**src/vector.h**

	class Vector{
	public:
	    Vector(double v[], int dim){
	        _dim = dim;
	        _v = new double[dim];
	        for (int i = 0; i < dim; i++)
	            _v[i] = v[i];
	    }

	    double * _v;
	    int _dim;
	};

**test/ut_vector.h**

	#include "../src/vector.h"
	#include "../src/dot.h"
	#include <cmath>
	TEST(InnerProduct, Dot1) {
	  int u[]={1, 0, 2};
	  int v[]={1, 1, 3};

	  ASSERT_EQ(7, dot(u, v, 3, 3));
	}

	TEST(InnerProduct, Exception1) {
	  int u[]={1, 0, 2, 4};
	  int v[]={1, 1, 3};

	  ASSERT_ANY_THROW(dot(u, v, 4, 3));
	}

	TEST(VectorTest, GetDim1){
	    double data[3] = {2, 3, 4};
	    Vector vector(data, 3);

	    ASSERT_EQ(3, getDim(vector));
	}

	TEST(VectorTest, IsZero1){
	    double data[3] = {2.5, 3.4, 4.2};
	    Vector vector(data, 3);

	    ASSERT_FALSE(isZero(vector));
	}

	TEST(VectorTest, Length1){
	    double data[3] = {3, 4, 5};
	    Vector vector(data, 3);

	    ASSERT_NEAR(sqrt(50), length(vector), 0.001);
	}
	//and your test for each function

**test/ut_main.cpp**

	#include <gtest/gtest.h>
	#include "./ut_vector.h"

	int main(int argc, char **argv)
	{
	    testing ::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
	}

**makefile**

	.PHONY: directories clean

	all: directories bin/ut_all

	bin/ut_all: obj/ut_main.o
		g++ -std=c++11 -o bin/ut_all test/ut_main.cpp -lgtest -lpthread

	obj/ut_main.o: test/ut_main.cpp test/ut_vector.h
		g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

	directories:
		mkdir -p bin obj

	clean:
		rm -rf bin obj

	stat:
		wc src/* test/*

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
2. _TA project will be used in this assignment
