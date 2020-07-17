from term import *


class Polynomial:
    def __init__(self, terms):
        if isinstance(terms, (list,)):
            self.__terms = {x.exponent(): x for x in terms}
        else:
            self.__terms = {terms.exponent(): terms}

    def getCoefficientByDegree(self, degree):
        try:
            return self.__terms.get(degree).coefficient()
        except:
            return 0

    def addTerm(self, term):
        self.__terms[term.exponent()] = term

    def degreeOfPolynomial(self):
        return max(self.__terms.keys())

    def multiplyByTerm(self, term):
        self.__terms = {x + term.exponent(): self.__terms[x] * term
                        for x in self.__terms.keys()}
        return self

    def __add__(self, polynomial):
        temp = {**self.__terms, **polynomial.__terms}
        temp = {x: Term(self.getCoefficientByDegree(x) + polynomial.getCoefficientByDegree(x), x)
                for x in list(temp.keys())}
        return Polynomial(list(temp.values()))

    def __sub__(self, polynomial):
        temp = {**self.__terms, **polynomial.__terms}
        temp = {x: Term(self.getCoefficientByDegree(x) - polynomial.getCoefficientByDegree(x), x)
                for x in list(temp.keys())}
        return Polynomial(list(temp.values()))
