#include <iostream>

#include <vector>

#include "ChicagoPizzaIngredientFactory.h"

Dough ChicagoPizzaIngredientFactory::CreateDough() {
    return ThickCrustDough();
}

Sauce ChicagoPizzaIngredientFactory::CreateSauce() {
    return PlumTomatoSauce();
}

Cheese ChicagoPizzaIngredientFactory::CreateCheese() {
    return MozzarellaCheese();
}

std::vector<Veggies> ChicagoPizzaIngredientFactory::CreateVeggies() {
    std::vector<Veggies> veggies{BlackOlives(), Spinach(), EggPlant()};
    return veggies;
}

Pepperoni ChicagoPizzaIngredientFactory::CreatePepperoni() {
    return SlicedPepperoni();
}

Clams ChicagoPizzaIngredientFactory::CreateClam() {
    return FrozenClams();
}