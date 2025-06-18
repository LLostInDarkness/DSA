appName = p7

CPP			= g++

FLAGS		= -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): p7_main.cpp bst_Funcs.o
	$(CPP) $(FLAGS) $^ -o $@

bst_Funcs.o: bst.cpp bst_Funcs.h
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f ./*.o $(appName)