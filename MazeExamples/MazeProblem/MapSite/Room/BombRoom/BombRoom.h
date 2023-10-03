#pragma once

#include "../Room.h"

class BombRoom: public Room {
    public:
        BombRoom(int id): Room(id) {};

        virtual MapSite* Enter();
};