import unittest
from article import *
from wordcloud import *


class FilterTest(unittest.TestCase):
    def test_filter(self):
        a = Article('example1.txt')
        test = a.filter()
        b = ['c++', 'c++', 'introducing', 'll']
        self.assertEqual(test, b)


class WordTest(unittest.TestCase):
    def test_stop_word(self):
        a = Article('example1.txt')
        self.assertFalse(a.isStopWord('hi'))
        self.assertTrue(a.isStopWord('will'))

    def test_result(self):
        a = Article('example1.txt')
        d = a.getFrequencyResult()
        self.assertEqual(d['c++'], 2)


class SvgTest(unittest.TestCase):
    def test_svg(self):
        a = Article('example1.txt')
        b = WordCloud(a)
        test = '<svg xmlns = "http://www.w3.org/2000/svg" width = "10000" height = "10000" viewBox = "0 0 10000 10000" ><text x="0" y ="26" font-size="26" fill="black">c++</text><text x="0" y ="45" font-size="19" fill="black">introducing</text><text x="0" y ="64" font-size="19" fill="black">ll</text></svg>'
        self.assertEqual(b.toSVG(), test)
