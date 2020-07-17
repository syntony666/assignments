import re


class Article():
    def __init__(self, file_name):
        f = open(file_name, 'r')
        self.__doc = f.read().lower()
        f.close()

    def isStopWord(self, word):
        f = open('stop_words.txt', 'r')
        sw = f.read()
        f.close()
        sw = re.split(r'[ \,\n]+', sw)
        for x in sw:
            if x == word:
                return True
        return False

    def getFrequencyResult(self):
        doc = self.filter()
        result = {}
        for x in doc:
            if x in result:
                result[x] += 1
            else:
                result[x] = 1
        return result

    def filter(self):
        self.__doc = re.split(r'[^A-Za-z0-9+_]+', self.__doc)
        self.__doc = [x for x in self.__doc if not self.isStopWord(x)]
        self.__doc.sort()
        return self.__doc
