appName = p1

CPP			= g++

FLAGS	  = -std=c++20 -Wall -Wpedantic -Wextra -O

$(appName): main.cpp linkList.o stack.o
	$(CPP) $(FLAGS) $^ -o $@

stack.o: stackFuncs.cpp stack.h
	$(CPP) $(FLAGS) -c $< -o $@

linkList.o: linkedListFuncs.cpp linkedList.h
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f ./*.o $(appName)

