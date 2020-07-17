# OOP with C++ (and more)

#### Spring, 2019

#### Prof Y C Cheng

#### Dept of Computer Science and Information Engineering

#### Taipei Tech

## Assignment 7

### Due: 11:59 p.m., 10 May 2019

**For this assignment, please put all your tests in test/ut_polygon.h, your functions in src/bubble_sort.h, src/circle.h
, src/dot.h, src/polygon.h, src/shape.h, src/vector.h
**

### Purpose of this assignment:

Mixup every thing that teached in class.

### Problems:

In class, you have learned how inheritance works in C++. In this assignment, you need to let class `Polygon` and class `Circle` inheritance class `Shape` and write some functions.

Please implement and test the following functions:

-   virtual double Shape::perimeter() const = 0;
-   double Circle::perimeter() const;
-   double Polygon::perimeter() const;
-   std::vector&lt;Shape \*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)

(For those function, you have to write at least one test for each scenario(include Exception))

(Some functions from class or previous homework will be used, we suppose those functions will work correctly.)

**sample test**

    #include "../src/vector.h"
    #include "../src/dot.h"
    #include "../src/bubble_sort.h"
    #include "../src/polygon.h"
    #include "../src/circle.h"
    #include "../src/shape.h"
    #include <cmath>

    double const epsilon = 0.0001;

    TEST(ShapeTest, Polygon){
      double a[]={0, 0};
      double c[]={2, 2};
      double d[]={1, 3};
      double e[]={0, 2};
      double b[]={2, 0};
      double f[]={3, 1};
      Vector u(a, 2);
      Vector v(b, 2);
      Vector w(c, 2);
      Vector x(d, 2);
      Vector y(e, 2);
      Vector z(f, 2);
      Vector arr[] = {u, v, w, x, y, z};
      Polygon * poly = new Polygon(arr, 6);
      ASSERT_NEAR(6, poly->area(), epsilon);
      ASSERT_NEAR(4 + 4 * sqrt(2), poly->perimeter(), epsilon);

    }

    TEST(ShapeTest, Circle){
      Circle * c = new Circle(6);
      ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
      ASSERT_NEAR(12 * M_PI, c->perimeter(), epsilon);
    }

    TEST(ShapeTest, Shape){
      Shape * c = new Circle(6);
      ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
      double a[]={0, 0};
      double b[]={0, 2};
      double d[]={2, 0};
      Vector u(a, 2);
      Vector v(b, 2);
      Vector w(d, 2);
      Vector arr[] = {u, v, w};
      Polygon * poly = new Polygon(arr, 3);
      ASSERT_NEAR(2, poly->area(), epsilon);
    }

    TEST(FindTest, FindAll) {
      double a[]={0, 0};
      double b[]={2, 0};
      double c[]={3, 1};
      double d[]={2, 2};
      double e[]={1, 3};
      double f[]={0, 2};
      Vector u(a, 2);
      Vector v(b, 2);
      Vector w(c, 2);
      Vector x(d, 2);
      Vector y(e, 2);
      Vector z(f, 2);
      Vector arr1[] = {u, v, w};//1
      Vector arr2[] = {u, v, w, x};//3
      Vector arr3[] = {u, v, w, x, y};//5
      Vector arr4[] = {u, v, w, x, y, z};//6
      std::vector<Shape *> vec;
      vec.push_back(new Polygon(arr1, 3));
      vec.push_back(new Circle(1.5));
      vec.push_back(new Polygon(arr2, 4));
      vec.push_back(new Circle(0.5));
      vec.push_back(new Polygon(arr3, 5));
      vec.push_back(new Circle(1));
      vec.push_back(new Polygon(arr4, 6));
      std::vector<Shape *> result = findAll(vec.begin(), vec.end(), [](Shape *s){
          return s->area() > 2 && s->area() < 5.5;
          });
          ASSERT_EQ(3, result.size());
      ASSERT_NEAR(3, result[0]->area(), epsilon);
      ASSERT_NEAR(5, result[1]->area(), epsilon);
      ASSERT_NEAR(M_PI, result[2]->area(), epsilon);
    }

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. **\_TA project** will be used in this assignment
