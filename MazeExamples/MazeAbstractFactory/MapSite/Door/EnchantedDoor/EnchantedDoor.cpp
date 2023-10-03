#include <iostream>

#include "EnchantedDoor.h"

MapSite* EnchantedDoor::Enter() {
    std::cout << "Passing through door! You feel magical!" << std::endl;

    return this;
}