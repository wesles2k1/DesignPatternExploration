// Abstract Creator Class (defines abstract factory method)

#include <iostream>

#include "PizzaStore.h"

#include "Pizza.h"

Pizza* PizzaStore::OrderPizza(PizzaType type) {
    Pizza* pizza;

    pizza = CreatePizza(type);
    pizza->Prepare();
    pizza->Bake();
    pizza->Cut();
    pizza->Box();

    return pizza;
}