.PHONY: all memcheck clean

CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++17

OBJS =  main

all: ${OBJS}

memcheck: clean main
	valgrind --leak-check=summary main

main: PizzaStore.o Regions/NYPizzaStore.o Regions/ChicagoPizzaStore.o Pizza.o
PizzaStore.o: PizzaStore.h Pizza.h PizzaType.h
NYPizzaStore.o: Regions/NYPizzaStore.h Pizza.h PizzaType.h
ChicagoPizzaStore.o: Regions/ChicagoPizzaStore.h Pizza.h PizzaType.h
Pizza.o: Pizza.h

clean:
	rm -f ${OBJS} *.o *.gcov *.gcno *.gcda

clear:
	make clean
	clear
	clear
	make main