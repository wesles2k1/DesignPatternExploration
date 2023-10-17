#include <iostream>

#include "LockDoor.h"

MapSite* LockDoor::Enter() {
    std::cout << "This door has a big ol' lock on it." << std::endl;

    return this;
}