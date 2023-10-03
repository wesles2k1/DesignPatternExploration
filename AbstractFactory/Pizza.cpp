// The Abstract Product

#include <iostream>
#include <string>

#include "Pizza.h"
#include "Ingredients/NYPizzaIngredientFactory.h"

Pizza::Pizza(PizzaIngredientFactory *newIngredientFactory) {
    ingredientFactory = newIngredientFactory;
}

void Pizza::Bake() {
    std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::Cut() {
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::Box() {
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

void Pizza::SetName(std::string newName) {
    name = newName;
}

std::string Pizza::GetName() {
    return name;
}

std::string Pizza::ToString() {
    return name;
}

// Concrete Classes

CheesePizza::CheesePizza(PizzaIngredientFactory *newIngredientFactory) : Pizza(newIngredientFactory) {}

void CheesePizza::Prepare() {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->CreateDough();
    sauce = ingredientFactory->CreateSauce();
    cheese = ingredientFactory->CreateCheese();
}

VeggiePizza::VeggiePizza(PizzaIngredientFactory *newIngredientFactory) : Pizza(newIngredientFactory) {}

void VeggiePizza::Prepare() {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->CreateDough();
    sauce = ingredientFactory->CreateSauce();
    cheese = ingredientFactory->CreateCheese();
    veggies = ingredientFactory->CreateVeggies();
}

ClamPizza::ClamPizza(PizzaIngredientFactory *newIngredientFactory) : Pizza(newIngredientFactory) {}

void ClamPizza::Prepare() {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->CreateDough();
    sauce = ingredientFactory->CreateSauce();
    cheese = ingredientFactory->CreateCheese();
    clam = ingredientFactory->CreateClam();
}

PepperoniPizza::PepperoniPizza(PizzaIngredientFactory *newIngredientFactory) : Pizza(newIngredientFactory) {}

void PepperoniPizza::Prepare() {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->CreateDough();
    sauce = ingredientFactory->CreateSauce();
    cheese = ingredientFactory->CreateCheese();
    pepperoni = ingredientFactory->CreatePepperoni();
}
