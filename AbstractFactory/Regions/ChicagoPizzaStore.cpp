// Concrete Creator

#include "ChicagoPizzaStore.h"

#include "../Pizza.h"
#include "../Ingredients/PizzaIngredientFactory.h"
#include "../Ingredients/ChicagoPizzaIngredientFactory.h"

// The Factory Method
Pizza* ChicagoPizzaStore::CreatePizza(PizzaType type) {
    Pizza* pizza{nullptr};
    PizzaIngredientFactory* ingredientFactory{new ChicagoPizzaIngredientFactory()};
    switch (type) {
        case PizzaType::CHEESE:
            pizza = new CheesePizza(ingredientFactory);
            pizza->SetName("Chicago Style Cheese Pizza");
            break;
        case PizzaType::VEGGIE:
            pizza = new VeggiePizza(ingredientFactory);
            pizza->SetName("Chicago Style Veggie Pizza");
            break;
        case PizzaType::CLAM:
            pizza = new ClamPizza(ingredientFactory);
            pizza->SetName("Chicago Style Clam Pizza");
            break;
        case PizzaType::PEPPERONI:
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->SetName("Chicago Style Pepperoni Pizza");
            break;
        case PizzaType::DEFAULT:
            break;
    }

    return pizza;
}