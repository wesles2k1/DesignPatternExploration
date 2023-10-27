#include <iostream>

#include "EnchantedRoom.h"

MapSite* EnchantedRoom::Enter() {
    std::cout << "Entering room, there's a strange aura here!" << std::endl;

    return this;
}