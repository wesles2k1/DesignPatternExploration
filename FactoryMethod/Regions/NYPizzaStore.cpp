// Concrete Creator

#include "NYPizzaStore.h"
#include "../Pizza.h"
#include "../PizzaType.h"

// The Factory Method
Pizza NYPizzaStore::CreatePizza(PizzaType type) {
    Pizza* pizza;
    switch (type) {
        case PizzaType::CHEESE:
            pizza = new NYCheesePizza();
            break;
        case PizzaType::VEGGIE:
            pizza = new NYVeggiePizza();
            break;
        case PizzaType::CLAM:
            pizza = new NYClamPizza();
            break;
        case PizzaType::PEPPERONI:
            pizza = new NYPepperoniPizza();
            break;
        case PizzaType::DEFAULT:
        default:
            pizza = new NYCheesePizza();
    }

    return *pizza;
}