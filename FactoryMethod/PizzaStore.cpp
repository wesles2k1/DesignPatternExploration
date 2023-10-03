// Abstract Creator Class (defines abstract factory method)

#include "PizzaStore.h"
#include "PizzaType.h"

Pizza PizzaStore::OrderPizza(PizzaType type) {
    Pizza pizza;

    pizza = CreatePizza(type);

    pizza.Prepare();
    pizza.Bake();
    pizza.Cut();
    pizza.Box();

    return pizza;
}