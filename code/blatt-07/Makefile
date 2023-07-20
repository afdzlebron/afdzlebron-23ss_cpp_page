CXX = g++
CXXFLAGS=  --std=c++14 #-Wextra -Wall -pedantic
EXCLUDED = poly2.cpp
HEADERS = $(filter-out $(EXCLUDED), $(wildcard *.hpp))
OBJECTS = $(addsuffix .o, $(basename  $(filter-out $(EXCLUDED) %Test.cpp %Main.cpp, $(wildcard *.cpp))))
TESTLIBS = -lgtest -lgtest_main -lpthread
TEST_BINARIES = $(basename $(wildcard *[Tt]est.cpp))

all: clean compile

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

%Main: %Main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

compile: bddMain nqueensMain

%Test: %Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)  $(TESTLIBS)

test: $(TEST_BINARIES)
	echo "$(TESTS)"
	for test in `ls *Test` ; \
	do \
	./$$test || (echo "failed test $$test" && exit 255) \
	done

clean:
	rm -f *Main *Test *.o

format:
	clang-format -i *.cpp *.hpp
