// The Abstract Product

#include <iostream>

#include "Pizza.h"

void Pizza::Prepare() {
    std::cout << "Preparing the " << pizzaName << "..." << std::endl;
}

void Pizza::Bake() {
    std::cout << "Baking the " << pizzaName << "..." << std::endl;
}

void Pizza::Cut() {
    std::cout << "Cutting the " << pizzaName << "..." << std::endl;
}

void Pizza::Box() {
    std::cout << "Boxing the " << pizzaName << "..." << std::endl;
}