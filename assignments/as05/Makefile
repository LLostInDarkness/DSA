appName = p5

CPP			= g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p5_main.cpp hash.o
	 $(CPP) $(FLAGS) $^ -o $@

hash.o: hashTable.cpp hashFuncs.h
	 $(CPP) $(FLAGS) -c $< -o $@

clean:
	 rm -f ./*.o $(appName)
