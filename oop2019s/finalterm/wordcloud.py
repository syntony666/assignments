from article import *


class WordCloud():
    def __init__(self, article):
        self.frequency = article.getFrequencyResult()

    def toSVG(self):
        svg = '<svg xmlns = "http://www.w3.org/2000/svg" width = "10000" height = "10000" viewBox = "0 0 10000 10000" >'
        height = 0
        for x, y in self.frequency.items():
            font = 12 + (y * 7)
            height += font
            svg += '<text x="0" y ="' + \
                str(height)+'" font-size="'+str(font) + \
                '" fill="black">'+x+'</text>'
        return svg + '</svg>'
