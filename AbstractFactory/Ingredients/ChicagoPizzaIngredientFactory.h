#pragma once

#include <vector>

#include "PizzaIngredientFactory.h"

#include "IngredientInclude.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
    Dough CreateDough();
    Sauce CreateSauce();
    Cheese CreateCheese();
    std::vector<Veggies> CreateVeggies();
    Pepperoni CreatePepperoni();
    Clams CreateClam();
};