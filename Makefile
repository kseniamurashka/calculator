.PHONY: all clean run runtest

GTEST_INCLUDE = googletest/googletest/include
GTEST_LIB_PATH = googletest/build/lib
GTEST_LFLAGS = -lgtest -lpthread -lgtest_main

all: calc test leak_test

calc: main.o Calculator.o
	g++ main.o Calculator.o -o calc

main.o: main.cpp 
	g++ -c main.cpp

Calculator.o: Calculator.cpp 
	g++ -c Calculator.cpp

test: test.cpp Calculator.cpp
	g++ test.cpp Calculator.cpp -o test -I$(GTEST_INCLUDE) -L$(GTEST_LIB_PATH) $(GTEST_LFLAGS)

leak_test: test.cpp Calculator.cpp
	g++ -g test.cpp Calculator.cpp -o leak_test -fsanitize=address -I$(GTEST_INCLUDE) -L$(GTEST_LIB_PATH) $(GTEST_LFLAGS)

runtest: test
	./test

run: calc
	./calc

clean:
	rm -rf *.o calc test leak_test
