#pragma once

#include "../MapFactory.h"

class EnchantedMapFactory: public MapFactory {
    public:
        EnchantedMapFactory(): MapFactory() {};

        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
};