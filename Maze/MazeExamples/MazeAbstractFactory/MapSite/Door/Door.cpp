#include <iostream>

#include "Door.h"

Door::Door(Room* newRoom1, Room* newRoom2) {
    room1 = newRoom1;
    room2 = newRoom2;
}

MapSite* Door::Enter() {
    std::cout << "Passing through door!" << std::endl;

    return this;
}

Room* Door::OtherSideFrom(Room* currentSide) {
    if(room1 == currentSide) {
        return room2;
    } else if(room2 == currentSide) {
        return room1;
    } else {
        return nullptr;
    }
}