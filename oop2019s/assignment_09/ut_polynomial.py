import unittest

from polynomial import *


class polynomialTest(unittest.TestCase):
    def test_constructor(self):
        p = Polynomial(Term(3, 5))
        self.assertAlmostEqual(p.getCoefficientByDegree(5), 3)
        self.assertAlmostEqual(p.getCoefficientByDegree(1), 0)

    def test_construct_few_term(self):
        p = Polynomial([Term(3, 5), Term(4, 3), Term(7, 4)])
        self.assertAlmostEqual(p.getCoefficientByDegree(3), 4)
        self.assertAlmostEqual(p.getCoefficientByDegree(4), 7)
        self.assertAlmostEqual(p.getCoefficientByDegree(5), 3)

    def test_add_term(self):
        p = Polynomial(Term(3, 5))
        p.addTerm(Term(4, 9))
        self.assertAlmostEqual(p.getCoefficientByDegree(5), 3)
        self.assertAlmostEqual(p.getCoefficientByDegree(9), 4)

    def test_get_degree(self):
        p = Polynomial(Term(3, 5))
        p.addTerm(Term(4, 9))
        self.assertAlmostEqual(p.degreeOfPolynomial(), 9)


class calculatePolynomialTest(unittest.TestCase):
    def setUp(self):
        self.t = Term(3, 2)
        self.p = Polynomial([Term(3, 5), Term(6, 4)])
        self.q = Polynomial([Term(9, 4), Term(7, 3), Term(7, 2)])

    def test_multiply(self):
        self.p.multiplyByTerm(self.t)
        self.assertAlmostEqual(self.p.getCoefficientByDegree(7), 9)
        self.assertAlmostEqual(self.p.getCoefficientByDegree(6), 18)
        self.assertAlmostEqual(self.p.degreeOfPolynomial(), 7)

    def test_add(self):
        r = self.p + self.q
        self.assertAlmostEqual(r.getCoefficientByDegree(2), 7)
        self.assertAlmostEqual(r.getCoefficientByDegree(3), 7)
        self.assertAlmostEqual(r.getCoefficientByDegree(4), 15)
        self.assertAlmostEqual(r.getCoefficientByDegree(5), 3)
        self.assertAlmostEqual(r.degreeOfPolynomial(), 5)

    def test_substract(self):
        r = self.p - self.q
        self.assertAlmostEqual(r.getCoefficientByDegree(2), -7)
        self.assertAlmostEqual(r.getCoefficientByDegree(3), -7)
        self.assertAlmostEqual(r.getCoefficientByDegree(4), -3)
        self.assertAlmostEqual(r.getCoefficientByDegree(5), 3)
        self.assertAlmostEqual(r.degreeOfPolynomial(), 5)
