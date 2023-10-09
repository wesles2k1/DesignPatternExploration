#pragma once

#include "../Wall.h"

class BombWall: public Wall {
    public:
        BombWall(): Wall() {};

        virtual MapSite* Enter();
};