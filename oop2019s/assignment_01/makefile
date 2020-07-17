.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: test/*
	g++ -std=c++11 -o bin/ut_all test/ut_string.cpp -lgtest -lpthread

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
