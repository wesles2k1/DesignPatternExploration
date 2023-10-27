#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Room/BombRoom/BombRoom.h"
#include "../../MapElement/Wall/BombWall/BombWall.h"

class BombMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;

    // Allow for Singleton behavior
    protected:
        BombMapFactory() {};
    friend class Singleton;
};