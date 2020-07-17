# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 4

### Due: 11:59 p.m., 3 April 2019


**For this assignment, please put all your tests in test/ut_vector.h, all your functions in src/vector.h and set the output file to bin/ut_all**


### Purpose of this assignment:
Let students practice for the operator overload, Copy assignment and area.

### Problems:

In class, you have learned how to use operator overload, copy assignment and calculate area. For this assignment, you need to add "perimeter" method to get the perimeter of polygon, and than test all methods!


Please implement and test the following member functions:

- operator - (Vector v)                     (25 points)
- operator + (Vector v)                     (25 points)
- operator = (Vector v)                     (10 points)
- subtract(Vector v)                        (10 points)
- add(Vector v)                             (25 points)
- distance(Vector u, Vector v)              (10 points)
- double area(Vector u, Vector v, Vector w) (10 points)
- double area(Vector a[], int sides)        (10 points)
- double perimeter(Vector a[], int sides)   (25 points)

Total points: **150**  
(For those functions, you have to write at least one test for each scenario(include Exception))

we will provide the prototype of **Vector** class for this assignment

**src/vector.h**

	#ifndef VECTOR_H
	#define VECTOR_H
	#include<iostream>
	#include<cmath>
	class Vector {
	public:
	  Vector(double v[], int dim) {...}

	  Vector(Vector const & v){...}

	  // destructor
	  ~Vector() {...}

	  // constant member function
	  int dim() const{...}

	  double & at(int i) const{...}

	  void subtract(Vector const & v){...}

	  void add(Vector const & v){...}

	  Vector & operator = (Vector const & u){...}

	  Vector operator - (Vector const & v) const{...}

	  Vector operator + (Vector const & v) const{...}

	  double length() const {...}

	private:
	  int _dim;
	  double * _v;
	  void copy(int dim, double v[]){...}
	};

	double distance(Vector const & u, Vector const & v){...}

	double area(Vector const & u, Vector const & v, Vector const & w) {...}

	double area(Vector a[], int sides){...}

	double perimeter(Vector a[], int sides){...}

	#endif

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. **_TA project** will be used in this assignment
