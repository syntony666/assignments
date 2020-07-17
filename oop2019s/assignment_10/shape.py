from abc import ABC, abstractmethod


class Shape(ABC):
    def __init__(self, centerPoint):
        if len(centerPoint) != 2:
            raise IndexError
        self.centerPoint = centerPoint
        self.setFillColor("black")
        self.setStroke(0, "black")

    def setFillColor(self, fillColor):
        self.__fillColor = fillColor

    def setStroke(self, strokeWidth, strokeColor):
        self.__strokeWidth = strokeWidth
        self.__strokeColor = strokeColor

    def getFillColor(self):
        return self.__fillColor

    def getStrokeWidth(self):
        return self.__strokeWidth

    def getStrokeColor(self):
        return self.__strokeColor

    @abstractmethod
    def toSVG(self):
        pass

    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass


def makeSvgOutput(width, height, shapeList):
    temp = '<svg xmlns="http://www.w3.org/2000/svg" width="'+str(width)+'" height="'+str(height)+'" viewBox="0 0 '+str(width)+' '+str(height)+'">'
    for x in shapeList:
        temp = temp + x.toSVG()
    return temp + '</svg>'
