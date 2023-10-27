#pragma once

#include <iostream>

#include "../Map.h"

class MapFactory {
    public:
        // Factory Methods
        virtual Map* MakeMap() const;
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
    
    // Allow for Singleton behavior
    protected:
        MapFactory() {};
    friend class Singleton;
};