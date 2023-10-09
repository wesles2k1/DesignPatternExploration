#pragma once

#include "../MapSite.h"

// Defines a Wall to be put into a Map
class Wall: public MapSite {
    public:
        Wall();

        virtual MapSite* Enter();
};