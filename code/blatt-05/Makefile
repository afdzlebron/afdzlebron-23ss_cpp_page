CXX = g++
CXXFLAGS=--std=c++14 
HEADERS = $(wildcard *.hpp)
OBJECTS = $(addsuffix .o, $(basename $(filter-out imageTest.cpp, $(wildcard *.cpp))))

all: clean compile test run format

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS)

compile: imageMain

imageMain: $(OBJECTS) 
	$(CXX) -o $@ $^ $(CXXFLAGS) -lgtest -lpthread

imageTest: imageTest.o image.o
	$(CXX) -o $@ $^ $(CXXFLAGS) -lgtest -lpthread -lgtest_main

test: imageTest
	./$<

run: imageMain
	./$<

clean:
	rm -f imageMain imageTest *.o *Main *.ppm 

format:
	clang-format -i *.cpp *.hpp
