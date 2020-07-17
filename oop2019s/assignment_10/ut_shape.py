import unittest
import math
from rectangle import Rectangle
from circle import Circle
from line import Line
from shape import Shape, makeSvgOutput


class CircleCase(unittest.TestCase):
    def setUp(self):
        self.c1 = Circle(5, [3, 5])
        self.c2 = Circle(4)

    def test_construct_error(self):
        foo1, foo2, foo3 = -5, 3, [2, 8, 6]
        self.assertRaises(IndexError, Circle, foo1)
        self.assertRaises(IndexError, Circle, foo2, foo3)
        self.assertRaises(IndexError, Circle, foo1, foo3)

    def test_area(self):
        self.assertAlmostEqual(25*math.pi, self.c1.area())
        self.assertAlmostEqual(16*math.pi, self.c2.area())

    def test_perimeter(self):
        self.assertAlmostEqual(10*math.pi, self.c1.perimeter())
        self.assertAlmostEqual(8*math.pi, self.c2.perimeter())


class LineCase(unittest.TestCase):
    def setUp(self):
        self.v1 = Line([10, 2], [3, 5])
        self.v2 = Line([4, 3])

    def test_construct_error(self):
        foo1, foo2 = [1, 2, 3], [1, 2]
        self.assertRaises(IndexError, Line, foo1)
        self.assertRaises(IndexError, Line, foo2, foo1)
        self.assertRaises(IndexError, Line, foo1, foo2)

    def test_area(self):
        self.assertAlmostEqual(0, self.v1.area())
        self.assertAlmostEqual(0, self.v2.area())

    def test_perimeter(self):
        self.assertAlmostEqual(math.sqrt(104), self.v1.perimeter())
        self.assertAlmostEqual(5, self.v2.perimeter())


class RectangleCase(unittest.TestCase):
    def setUp(self):
        self.r1 = Rectangle(3, 4, [3, 5])
        self.r2 = Rectangle(5, 12)

    def test_construct_error(self):
        foo1, foo2, foo3, foo4 = -2, 7, [7, 1, 2], [1, 2]
        self.assertRaises(IndexError, Rectangle, foo1, foo2)
        self.assertRaises(IndexError, Rectangle, foo1, foo1)
        self.assertRaises(IndexError, Rectangle, foo2, foo1)
        self.assertRaises(IndexError, Rectangle, foo1, foo1, foo3)
        self.assertRaises(IndexError, Rectangle, foo1, foo1, foo4)

    def test_area(self):
        self.assertAlmostEqual(12, self.r1.area())
        self.assertAlmostEqual(60, self.r2.area())

    def test_perimeter(self):
        self.assertAlmostEqual(14, self.r1.perimeter())
        self.assertAlmostEqual(34, self.r2.perimeter())


class SvgTest(unittest.TestCase):
    def setUp(self):
        self.c1 = Circle(3)
        self.c2 = Circle(3, [6, 5])
        self.v1 = Line([9, 2])
        self.v2 = Line([1, 4], [5, 9])
        self.r1 = Rectangle(6, 3)
        self.r2 = Rectangle(6, 3, [2, 7])
        self.s1 = [self.c1, self.v1, self.r1]
        self.s2 = [self.c2, self.v2, self.r2]

    def test_svg_fill_stroke(self):
        self.c1.setFillColor("blue")
        self.c1.setStroke(3, "yellow")
        self.assertEqual(self.c1.getFillColor(), "blue")
        self.assertEqual(self.c1.getStrokeColor(), "yellow")
        self.assertEqual(self.c1.getStrokeWidth(), 3)

    def test_circle_svg_1(self):
        self.c1.setFillColor("red")
        self.c1.setStroke(3, "black")
        c1_svg = '<circle cx=\"0\" cy=\"0\" r=\"3\" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/>'
        self.assertEqual(self.c1.toSVG(), c1_svg)

    def test_circle_svg_2(self):
        self.c2.setFillColor("green")
        self.c2.setStroke(5, "blue")
        c2_svg = '<circle cx=\"6\" cy=\"5\" r=\"3\" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/>'
        self.assertEqual(self.c2.toSVG(), c2_svg)

    def test_line_svg_1(self):
        self.v1.setFillColor("red")
        self.v1.setStroke(3, "black")
        v1_svg = '<line x1=\"-4.5\" y1=\"-1.0\" x2=\"4.5\" y2=\"1.0\" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/>'
        self.assertEqual(self.v1.toSVG(), v1_svg)

    def test_line_svg_2(self):
        self.v2.setFillColor("green")
        self.v2.setStroke(5, "blue")
        v2_svg = '<line x1=\"4.5\" y1=\"7.0\" x2=\"5.5\" y2=\"11.0\" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/>'
        self.assertEqual(self.v2.toSVG(), v2_svg)

    def test_rectangle_svg_1(self):
        self.r1.setFillColor("red")
        self.r1.setStroke(3, "black")
        r1_svg = '<polygon points=\"-3.0 -1.5 3.0 -1.5 3.0 1.5 -3.0 1.5 \" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/>'
        self.assertEqual(self.r1.toSVG(), r1_svg)

    def test_rectangle_svg_2(self):
        self.r2.setFillColor("green")
        self.r2.setStroke(5, "blue")
        r2_svg = '<polygon points=\"-1.0 5.5 5.0 5.5 5.0 8.5 -1.0 8.5 \" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/>'
        self.assertEqual(self.r2.toSVG(), r2_svg)

    def test_shapes_svg_1(self):
        for x in self.s1:
            x.setFillColor("red")
            x.setStroke(3, "black")
        s1_svg = '<svg xmlns="http://www.w3.org/2000/svg" width="250" height="500" viewBox="0 0 250 500"><circle cx=\"0\" cy=\"0\" r=\"3\" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/><line x1=\"-4.5\" y1=\"-1.0\" x2=\"4.5\" y2=\"1.0\" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/><polygon points=\"-3.0 -1.5 3.0 -1.5 3.0 1.5 -3.0 1.5 \" stroke-width=\"3\" stroke=\"black\" fill=\"red\"/></svg>'
        self.assertEqual(makeSvgOutput(250, 500, self.s1), s1_svg)

    def test_shapes_svg_2(self):
        for x in self.s2:
            x.setFillColor("green")
            x.setStroke(5, "blue")
        s2_svg = '<svg xmlns="http://www.w3.org/2000/svg" width="92" height="1450" viewBox="0 0 92 1450"><circle cx=\"6\" cy=\"5\" r=\"3\" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/><line x1=\"4.5\" y1=\"7.0\" x2=\"5.5\" y2=\"11.0\" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/><polygon points=\"-1.0 5.5 5.0 5.5 5.0 8.5 -1.0 8.5 \" stroke-width=\"5\" stroke=\"blue\" fill=\"green\"/></svg>'
        self.assertEqual(makeSvgOutput(92, 1450, self.s2), s2_svg)
