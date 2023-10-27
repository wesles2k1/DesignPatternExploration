#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Room/EnchantedRoom/EnchantedRoom.h"
#include "../../MapElement/Door/EnchantedDoor/EnchantedDoor.h"

class EnchantedMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;

    // Allow for Singleton behavior
    protected:
        EnchantedMapFactory() {};
    friend class Singleton;
};