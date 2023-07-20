CXX = g++
CXXFLAGS = -std=c++14

SRC := $(wildcard *.cpp)

OBJ := $(SRC:.cpp=.o)

.PHONY: all clean compile test checkstyle

all: clean compile image test checkstyle

compile: imageMain complex complexTest

imageMain: imageMain.o image.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lpthread

complex: complexMain.o complex.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lpthread

complexTest: complexTest.o complex.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lgtest -lpthread -lgtest_main

image: imageMain
	./$<

test: complexTest
	./$<

format:
	clang-format -i $(SRC)

checkstyle:
	python3 ../cpplint.py $(SRC)

clean:
	rm -f imageMain complex complexMain complexTest $(OBJ) *.s *.ppm
