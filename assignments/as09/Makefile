appName = p9

CPP			= g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p9_main.cpp
	 $(CPP) $(FLAGS) $^ -o $@

clean:
	 rm -f ./*.o $(appName)