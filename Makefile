CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++2a -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/dataframe.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/dataframe.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.DEFAULT_GOAL := tests
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*