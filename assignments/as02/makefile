appName   = p2

CPP	  = g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p2_main.cpp minHeapFuncs.o
	 $(CPP) $(FLAGS) $^ -o $@

minHeapFuncs.o: minHeapFuncs.cpp minHeap.h
	 $(CPP) $(FLAGS) -c $< -o $@

clean:
	 rm -f ./*.o $(appName)
