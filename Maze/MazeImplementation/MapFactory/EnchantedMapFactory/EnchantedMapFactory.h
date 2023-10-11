#pragma once

#include "../MapFactory.h"

class EnchantedMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;

    protected:
        // The protected constructor of this class, allowing for children
        EnchantedMapFactory();
};