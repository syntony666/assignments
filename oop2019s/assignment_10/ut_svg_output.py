import unittest
from rectangle import *
from circle import *
from line import *
from shape import *


class TestSvgOutput(unittest.TestCase):
    def test_make_svg_output(self):
        shapes = [Circle(15, [125, 120]), Rectangle(80, 20, [50, 20]), Line([40, 90], [90, 75])]
        for shape in shapes:
            shape.setFillColor("plum")
            shape.setStroke(2, "darkviolet")

        file = open("shape.svg", "w")
        file.write(makeSvgOutput(500, 500, shapes))
        file.close()
