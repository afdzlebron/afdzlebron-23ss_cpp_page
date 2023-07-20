CXXFLAGS += -std=c++14

all: clean compile test checkstyle

compile: PtnMain PtnTest

PtnMain: PtnMain.o Ptn.o PtnPrint.o
	g++ -o PtnMain PtnMain.o Ptn.o PtnPrint.o -lgtest -lpthread

PtnTest: PtnTest.o Ptn.o PtnPrint.o
	g++ -o PtnTest PtnTest.o Ptn.o PtnPrint.o -lgtest -lpthread

test: 
	./PtnTest

format:
	clang-format -i *.cpp

checkstyle: 
	python3 ../cpplint.py *.cpp	

clean: 
	rm -f PtnMain  PtnTest *.o *.s 




