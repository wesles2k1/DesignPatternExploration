// The Abstract Product

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Ingredients/PizzaIngredientFactory.h"

enum class PizzaType {
    CHEESE,
    VEGGIE,
    CLAM,
    PEPPERONI,

    DEFAULT
};

class Pizza {
    public:
        Pizza(PizzaIngredientFactory *newIngredientFactory);

        virtual void Prepare() = 0;
        void Bake();
        void Cut();
        void Box();
        void SetName(std::string newName);
        std::string GetName();
        std::string ToString();
    
    protected:
        std::string name{""};
        Dough dough;
        Sauce sauce;
        std::vector<Veggies> veggies;
        Cheese cheese;
        Pepperoni pepperoni;
        Clams clam;

        PizzaIngredientFactory* ingredientFactory;
};

class CheesePizza : public Pizza {
    public:
        CheesePizza(PizzaIngredientFactory *newIngredientFactory);
        void Prepare() override;
};
class VeggiePizza : public Pizza {
    public:
        VeggiePizza(PizzaIngredientFactory *newIngredientFactory);
        void Prepare() override;
};
class ClamPizza : public Pizza {
    public:
        ClamPizza(PizzaIngredientFactory *newIngredientFactory);
        void Prepare() override;
};
class PepperoniPizza : public Pizza {
    public:
        PepperoniPizza(PizzaIngredientFactory *newIngredientFactory);
        void Prepare() override;
};