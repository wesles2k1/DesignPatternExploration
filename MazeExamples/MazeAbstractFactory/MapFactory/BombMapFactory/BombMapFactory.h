#pragma once

#include "../MapFactory.h"

class BombMapFactory: public MapFactory {
    public:
        BombMapFactory(): MapFactory() {};

        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
};