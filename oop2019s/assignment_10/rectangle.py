from shape import Shape


class Rectangle(Shape):
    def __init__(self, width, height, centerPoint=[0, 0]):
        if width < 0 or height < 0:
            raise IndexError
        super().__init__(centerPoint)
        self.__width = width
        self.__height = height

    def area(self):
        return self.__width * self.__height

    def perimeter(self):
        return 2 * (self.__width + self.__height)

    def toSVG(self):
        return \
			'<polygon points=\"' + str(self.centerPoint[0] - self.__width / 2.0)+' '+\
			str(self.centerPoint[1] - self.__height/ 2.0)+' '+\
			str(self.centerPoint[0] + self.__width / 2.0)+' '+\
			str(self.centerPoint[1] - self.__height/ 2.0)+' '+\
			str(self.centerPoint[0] + self.__width / 2.0)+' '+\
			str(self.centerPoint[1] + self.__height/ 2.0)+' '+\
			str(self.centerPoint[0] - self.__width / 2.0)+' '+\
			str(self.centerPoint[1] + self.__height/ 2.0)+\
			' \" stroke-width=\"' + str(self.getStrokeWidth()) +\
			'\" stroke=\"' + self.getStrokeColor() + '\" fill=\"' + self.getFillColor() + '\"/>'
