# OOP with C++ (and more)
#### Spring, 2019
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 9

### Due: 11:59 p.m., 9 June 2019

### Problems:

The following are examples of a polynomial of a single variable (一元多項式):


    x² − 4x + 7   //polynomial 1
    0             //polynomial 2


The first polynomial has three terms(項): x², − 4x and 7; The second polynomial has one term 0. As can be seen, each term is represented by a pair of numbers: the coefficient (係數) of the variable and the exponent (冪次) of the variable . For example, the term x² is represented by the term [1, 2] because it has coefficient 1 and exponent 2. Similarly, − 4x, and 7 are represented by [-4,1] and [7,0], respectively; and the polynomial 0 has one term represented by [0,0].

Please write **unit tests** in "**ut_term.py**" and "**ut_polynomial.py**", and implement two classes, the class "**Term**" in "**term.py**" file and the class "**Polynomial**" in "**polynomial.py**" file, according to the following requirements.

**Prototypes of classes and functions:**

    class Term:
        def __init__(self, coefficient, exponent):
        def coefficient(self):
        def exponent(self):
        def isZero(self):         //check if it is zero(if the coefficient is 0, **isZero** will return **True**)
        def __mul__(self, term):
        def __eq__(self, term):
    };

    =============================================================================================

    class Polynomial:
        def __init__(self, terms):
        def getCoefficientByDegree(self, degree):
        def addTerm(self, term):
        def degreeOfPolynomial(self):
        def multiplyByTerm(self, term):
        def __add__(self, polynomial):    
        def __sub__(self, polynomial):



**Note:**
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. **\_TA project** will be used in this assignment.
3. You need to use **ut_main.py** to manage your test file.
