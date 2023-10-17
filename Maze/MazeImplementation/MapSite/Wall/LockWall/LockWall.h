#pragma once

#include "../Wall.h"

class LockWall: public Wall {
    public:
        LockWall(): Wall() {};

        virtual MapSite* Enter();
};