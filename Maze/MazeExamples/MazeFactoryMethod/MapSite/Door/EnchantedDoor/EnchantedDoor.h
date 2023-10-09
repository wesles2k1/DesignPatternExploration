#pragma once

#include "../Door.h"

// Defines a Room to be put into a Map
class EnchantedDoor: public Door {
    public:
        EnchantedDoor(Room* door1, Room* door2): Door(door1, door2) {};

        virtual MapSite* Enter();
};