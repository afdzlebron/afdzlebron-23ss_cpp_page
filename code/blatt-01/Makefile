all: clean compile test checkstyle

compile: 
	# Program
	g++ -o main main.cpp
	# Test
	g++ -std=c++0x ptntest.cpp -lgtest -lgtest_main -o ptntest

test: 
	./ptntest

checkstyle: 
	python3 ../cpplint.py *.cpp	

format:
	clang-format -i *.cpp

clean: 
	rm -f main
	rm -f ptntest




