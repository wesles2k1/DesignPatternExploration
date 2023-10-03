.PHONY: all memcheck clean

CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++17

OBJS =  main

all: ${OBJS}

memcheck: clean main
	valgrind --leak-check=summary main

main: Pizza.o PizzaStore.o Regions/NYPizzaStore.o Regions/ChicagoPizzaStore.o Ingredients/NYPizzaIngredientFactory.o Ingredients/ChicagoPizzaIngredientFactory.o
Pizza.o: Pizza.h
PizzaStore.o: PizzaStore.h Pizza.h
NYPizzaStore.o: Regions/NYPizzaStore.h Pizza.h Ingredients/NYPizzaIngredientFactory.h Ingredients/PizzaIngredientFactory.h
ChicagoPizzaStore.o: Regions/ChicagoPizzaStore.h Pizza.h Ingredients/ChicagoPizzaIngredientFactory.h Ingredients/PizzaIngredientFactory.h
NYPizzaIngredientFactory.o: Ingredients/NYPizzaIngredientFactory.h
ChicagoPizzaIngredientFactory.o: Ingredients/ChicagoPizzaIngredientFactory.h

clean:
	rm -f ${OBJS} *.o
	
clear:
	make clean
	clear
	clear
	make main