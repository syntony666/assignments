import unittest
from article import *
from wordcloud import *


class TestWordCloud(unittest.TestCase):

    def test_to_SVG(self):
        article = Article("example.txt")
        word_cloud = WordCloud(article)
        file = open("word_cloud.svg", "w")
        file.write(word_cloud.toSVG())
        file.close()
