appName = p8

CPP			= g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p8_main.cpp
	 $(CPP) $(FLAGS) $^ -o $@

clean:
	 rm -f ./*.o $(appName)