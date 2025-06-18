appName = p6

CPP			= g++

FLAGS		= -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p6_main.cpp disjoint.o maze.o
	$(CPP) $(FLAGS) $^ -o $@

disjoint.o: disjointSet.cpp disjointSetFuncs.h
	$(CPP) $(FLAGS) -c $< -o $@

maze.o: maze.cpp mazeFuncs.h
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f ./*.o $(appName)