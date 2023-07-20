CXX = g++
#CXX = clang++ # tends to give better error messages
CXXFLAGS=--std=c++14 
HEADERS = $(wildcard *.hpp)
OBJECTS = $(addsuffix .o, $(basename $(filter-out polyTest.cpp polyText.cpp, $(wildcard *.cpp))))

all: clean compile test run format

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS)

%Main: %Main.o %.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

compile: polyMain

polyMain: polyMain.o poly.o
	$(CXX) -o $@ $^ $(CXXFLAGS) -lgtest -lpthread

polyTest: polyTest.o poly.o
	$(CXX) -o $@ $^ $(CXXFLAGS) -lgtest -lpthread -lgtest_main
	./polyTest

test: polyTest
	./$<

run: polyMain
	./$<

clean:
	rm -f polyMain polyTest *.o *Main *.ppm 

format:
	clang-format -i *.cpp *.hpp


