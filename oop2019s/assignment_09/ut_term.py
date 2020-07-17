import unittest

from term import *


class termTest(unittest.TestCase):
    def test_constructor(self):
        self.term = Term(3, 5)
        self.assertAlmostEqual(self.term.coefficient(), 3.0)
        self.assertAlmostEqual(self.term.exponent(), 5.0)

    def test_isZero(self):
        self.term = Term(3, 5)
        self.term2 = Term(0, 5)
        self.assertFalse(self.term.isZero())
        self.assertTrue(self.term2.isZero())


class calculateTermTest(unittest.TestCase):
    def setUp(self):
        self.t = Term(2, 4)
        self.u = Term(9, 5)

    def test_multiply(self):
        self.tt = self.t * self.u
        self.assertAlmostEqual(self.tt.coefficient(), 18)
        self.assertAlmostEqual(self.tt.exponent(), 20)

    def test_equal(self):
        self.t = self.u
        self.assertAlmostEqual(self.t.coefficient(), 9)
        self.assertAlmostEqual(self.t.exponent(), 5)
