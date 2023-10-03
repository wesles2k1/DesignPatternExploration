// Concrete Creator

#include "ChicagoPizzaStore.h"
#include "../Pizza.h"
#include "../PizzaType.h"

// The Factory Method
Pizza ChicagoPizzaStore::CreatePizza(PizzaType type) {
    Pizza* pizza;
    switch (type) {
        case PizzaType::CHEESE:
            pizza = new ChicagoCheesePizza();
            break;
        case PizzaType::VEGGIE:
            pizza = new ChicagoVeggiePizza();
            break;
        case PizzaType::CLAM:
            pizza = new ChicagoClamPizza();
            break;
        case PizzaType::PEPPERONI:
            pizza = new ChicagoPepperoniPizza();
            break;
        case PizzaType::DEFAULT:
        default:
            pizza = new ChicagoCheesePizza();
    }

    return *pizza;
}