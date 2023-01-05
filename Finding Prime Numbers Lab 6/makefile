CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		nqueens nqueens2

nqueens:	nqueens.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

nqueens2:	nqueens2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f nqueens nqueens2

test:		test-8 test-10

test-8:	nqueens
	@echo Testing board size of 8 input/output...
	@diff --suppress-common-lines -y <(./nqueens 8) output

test-10: nqueens
	@echo Testing board size of 10 input/output...
	@diff --suppress-common-lines -y <(./nqueens2 10) output2
