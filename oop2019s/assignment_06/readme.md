# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 6

### Due: 11:59 p.m., 3 May 2019


**For this assignment, please put all your tests in test/ut_polygon.h, all your functions in src/dot.h**


### Purpose of this assignment:
Sort the vector in correct order and calculate polygon's area.

### Problems:

In class we have a half complete function centroid, you need to complete it, and use it to calculate polygon's area.


Please implement and test the following functions:

- Vector centroid(Vector vec[],int sides)             (50%)
- double convexPolygonArea(Vector vec[],int sides)     (50%)

(For those function, you have to write at least one test for each scenario(include Exception))

(You need to use the bubbleSort function written in the course instead of std::sort.)

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. **_TA project** will be used in this assignment
