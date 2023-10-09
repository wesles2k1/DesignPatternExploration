#include <iostream>

#include "BombRoom.h"

MapSite* BombRoom::Enter() {
    std::cout << "Entering room! Ah, there's a bomb!!!" << std::endl;

    return this;
}