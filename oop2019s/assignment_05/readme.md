# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 5

### Due: 11:59 p.m., 10 April 2019


**For this assignment, please put all your tests in test/ut_vector.h, all your functions in src/dot.h, write IO in src/user_main.cpp and set output file to bin/user_main**


### Purpose of this assignment:
Let students practice for the basic Input and Output.

### Problems:

In class, you have learned how to prase string to vector class; in this assignment, you need to write a console user interface for it, and TA will test your UI manually. However, your program have not capable to handle the invalid input form yet, so you need to improve it and test it!


Please implement and test the following functions:

- Vector createVectorFromStringOfNumbers(string s, int dim) (40%)
- IO                                               (60%)

(For createVectorFromStringOfNumbers, you have to write at least one test for each scenario(include Exception), you do not have to write test for your IO part)

**sample makefile**

	all: directories bin/ut_all bin/user_main

	bin/user_main: src/user_main.cpp src/dot.h src/vector.h
		g++ -std=c++11 -o bin/user_main src/user_main.cpp

	bin/ut_all: obj/ut_main.o
		g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

	obj/ut_main.o: test/ut_main.cpp test/ut_vector.h src/dot.h src/vector.h
		g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

	directories:
		mkdir -p bin obj

### sample input:

#### case1:

	Please enter two vectors you want to calculate:
	Dimension:2
	Vector 1:(1,2)
	Vector 2:(5,7)

#### case2:

	Please enter two vectors you want to calculate:
	Dimension:2
	Vector 1:(1,2
	Vector 2:(5,7)
	//wrong form

#### case3:

	Please enter two vectors you want to calculate:
	Dimension:3
	Vector 1:(1,2,3)
	Vector 2:(5,7)
	//Dimension mismatch

### sample output:

#### case1:

	Sum of these two Vectors: (6, 9)
	Difference between these two Vecotrs : (-4, -5)
	Inner product of these two Vectors: 19

#### case2:

	Invalid Input

#### case3:

	Invalid Input

### possible input form(including but not limited to):
	valid form:
	(1,2)
	(1,2,3)
	(1.1,2.2)

	invalid form:
	(1,2
	1,2)
	(,1,2)
	(1,2,)
	(1,2]
	[1,2)

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. **_TA project** will be used in this assignment
