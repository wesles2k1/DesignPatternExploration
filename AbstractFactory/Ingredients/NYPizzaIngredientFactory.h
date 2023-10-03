#pragma once

#include <vector>

#include "PizzaIngredientFactory.h"

#include "IngredientInclude.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
    Dough CreateDough() override;
    Sauce CreateSauce() override;
    Cheese CreateCheese() override;
    std::vector<Veggies> CreateVeggies() override;
    Pepperoni CreatePepperoni() override;
    Clams CreateClam() override;
};