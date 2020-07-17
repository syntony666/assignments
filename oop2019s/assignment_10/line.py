import math
from shape import Shape


class Line(Shape):
    def __init__(self, vector, centerPoint=[0, 0]):
        if len(vector) != 2:
            raise IndexError
        super().__init__(centerPoint)
        self.__vector = vector

    def area(self):
        return 0

    def perimeter(self):
        return math.sqrt(self.__vector[0]**2 + self.__vector[1]**2)

    def toSVG(self):
        return \
			'<line x1=\"' + str(self.centerPoint[0]-self.__vector[0]/2.0) + \
			'\" y1=\"' + str(self.centerPoint[1]-self.__vector[1]/2.0) +\
			'\" x2=\"' + str(self.centerPoint[0]+self.__vector[0]/2.0) +\
			'\" y2=\"' + str(self.centerPoint[1]+self.__vector[1]/2.0) +\
			'\" stroke-width=\"' + str(self.getStrokeWidth()) +\
			'\" stroke=\"' + self.getStrokeColor() + '\" fill=\"' + self.getFillColor() + '\"/>'
# vector: 同時代表著方向和長度
# perimeter: 線段長度
