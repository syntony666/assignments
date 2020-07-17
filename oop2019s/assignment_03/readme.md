# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 3

### Due: 11:59 p.m., 20 March 2019


**For this assignment, please put all your tests in test/ut_vector.h, all your functions in src/vector.h and set the output file to bin/ut_all**


### Purpose of this assignment:
Let students practice for the basic class member function use and test.

### Problems:


In last homework, you have written some functions for **Vector**. For this assignment, you need to move those functions into the **Vector** class, make them been the member functions, and test it!


Please implement and test the following member functions:

- at(int i) (20%)(return the **i**-th element in vector)
- isZero() (30%)(check if this vector is a zero vector)
- length() (30%)
- dim() (20%)

(For those functions, you have to write at least one test for each scenario, you can reuse your test in last homework )

we will provide the prototype of **Vector** class for this assignment

**src/vector.h**

	#ifndef VECTOR_H
	#define VECTOR_H
	#include <iostream>
	#include <cmath>
	class Vector {
	public:
	  Vector(double v[], int dim) {...}

	  int dim() {...}

	  bool isZero(){...}

	  double length(){...}

	  double at(int i) {...}

	private:
	  ...
	};

	#endif

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. **_TA project** will be used in this assignment
