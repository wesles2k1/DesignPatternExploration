#pragma once

#include "../MapFactory.h"

class BombMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;

    protected:
        // The protected constructor of this class, allowing for children
        //BombMapFactory();
};