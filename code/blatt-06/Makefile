CXX = g++
CXXFLAGS=--std=c++14 -Og -g  -fsanitize=undefined
HEADERS = $(filter-out $(EXCLUDED), $(wildcard *.hpp))
OBJECTS = $(addsuffix .o, $(basename  $(filter-out $(EXCLUDED) %Test.cpp %Main.cpp, $(wildcard *.cpp))))
TESTLIBS = -lgtest -lpthread -lgtest_main 

all: clean compile

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

%Main: %Main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# imageMain: $(OBJECTS) 
# 	$(CXX) -o $@ $^ $(CXXFLAGS) -lgtest -lpthread

compile: imageMain

%Test: %Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(TESTLIBS)

test: complexTest polyTest imageTest $(OBJECTS)
	./complexTest
	./polyTest
	./imageTest

clean:
	rm -f complexTest polyTest *.o *Main *Test *.ppm

format:
	clang-format -i *.cpp

