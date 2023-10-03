// This program is heavily based on the Factory Method section of the book Head First Design Patterns

#include <iostream>

#include "PizzaStore.h"
#include "Regions/NYPizzaStore.h"
#include "Regions/ChicagoPizzaStore.h"

using namespace std;

int main() {
    ChicagoPizzaStore pizzaStore;

    pizzaStore.OrderPizza(PizzaType::CLAM);

    return 0;
}