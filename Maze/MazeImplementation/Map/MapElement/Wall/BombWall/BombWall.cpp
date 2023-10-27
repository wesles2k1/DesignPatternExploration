#include <iostream>

#include "BombWall.h"

MapSite* BombWall::Enter() {
    std::cout << "Ran into bomb wall! You exploded!" << std::endl;
    std::cout << "Walk it off." << std::endl;

    return this;
}