#pragma once

#include "../Door.h"

// Defines a Room to be put into a Map
class LockDoor: public Door {
    public:
        LockDoor(Room* door1, Room* door2): Door(door1, door2) {};

        virtual MapSite* Enter();
};