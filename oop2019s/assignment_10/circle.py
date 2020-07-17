import math
from shape import Shape


class Circle(Shape):
    def __init__(self, radius, centerPoint=[0, 0]):
        if radius < 0:
            raise IndexError
        super().__init__(centerPoint)
        self.__radius = radius

    def area(self):
        return math.pi * self.__radius**2

    def perimeter(self):
        return math.pi * self.__radius * 2

    def toSVG(self):
        return \
            '<circle cx=\"' + str(self.centerPoint[0]) + '\" cy=\"' + str(self.centerPoint[1]) + \
            '\" r=\"' + str(self.__radius) + '\" stroke-width=\"' + str(self.getStrokeWidth()) + \
            '\" stroke=\"' + self.getStrokeColor() + '" fill=\"' + self.getFillColor() + '\"/>'
