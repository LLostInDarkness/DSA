appName = p3

CPP			= g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p3_main.cpp main.o
	 $(CPP) $(FLAGS) $^ -o $@

main.o: quicksortFuncs.cpp quicksort.h
	 $(CPP) $(FLAGS) -c $< -o $@

clean:
	 rm -f ./*.o $(appName)
