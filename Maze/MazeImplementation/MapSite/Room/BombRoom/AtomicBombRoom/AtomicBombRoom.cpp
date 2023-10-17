#include <iostream>

#include "AtomicBombRoom.h"

MapSite* AtomicBombRoom::Enter() {
    std::cout << "Entering room! Oh, there's just a HUGE bomb in here. Pretty dangerous, but it's probably alright. Just don't make it angry." << std::endl;

    return this;
}