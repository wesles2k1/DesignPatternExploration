#include <iostream>
#include <vector>

#include "NYPizzaIngredientFactory.h"

Dough NYPizzaIngredientFactory::CreateDough() {
    //std::cout << "TEsting tetings" << std::endl;
    return ThinCrustDough();
}

Sauce NYPizzaIngredientFactory::CreateSauce() {
    return MarinaraSauce();
}

Cheese NYPizzaIngredientFactory::CreateCheese() {
    return ReggianoCheese();
}

std::vector<Veggies> NYPizzaIngredientFactory::CreateVeggies() {
    std::vector<Veggies> veggies{Garlic(), Onion(), Mushroom(), RedPepper()};
    return veggies;
}

Pepperoni NYPizzaIngredientFactory::CreatePepperoni() {
    return SlicedPepperoni();
}

Clams NYPizzaIngredientFactory::CreateClam() {
    return FreshClams();
}