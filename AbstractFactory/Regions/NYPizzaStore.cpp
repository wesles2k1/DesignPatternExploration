// Concrete Creator

#include "NYPizzaStore.h"

#include "../Pizza.h"
#include "../Ingredients/PizzaIngredientFactory.h"
#include "../Ingredients/NYPizzaIngredientFactory.h"

// The Factory Method
Pizza* NYPizzaStore::CreatePizza(PizzaType type) {
    Pizza* pizza{nullptr};
    NYPizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();
    switch (type) {
        case PizzaType::CHEESE:
            pizza = new CheesePizza(ingredientFactory);
            pizza->SetName("New York Style Cheese Pizza");
            break;
        case PizzaType::VEGGIE:
            pizza = new VeggiePizza(ingredientFactory);
            pizza->SetName("New York Style Veggie Pizza");
            break;
        case PizzaType::CLAM:
            pizza = new ClamPizza(ingredientFactory);
            pizza->SetName("New York Style Clam Pizza");
            break;
        case PizzaType::PEPPERONI:
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->SetName("New York Style Pepperoni Pizza");
            break;
        case PizzaType::DEFAULT:
            break;
    }

    return pizza;
}