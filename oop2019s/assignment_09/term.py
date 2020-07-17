class Term:
    def __init__(self, coefficient, exponent):
        self.__term = [coefficient, exponent]

    def coefficient(self):
        return self.__term[0]

    def exponent(self):
        return self.__term[1]

    def isZero(self):  # check if it is zero(if the coefficient is 0, **isZero ** will return **True**)
        return self.__term[0] == 0

    def __mul__(self, term):
        return Term(self.coefficient() * term.coefficient(),
                    self.exponent() * term.exponent())

    def __eq__(self, term):
        self.__term = [term.coefficient(), term.exponent()]
        return self
