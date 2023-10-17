#pragma once

#include "../BombRoom.h"

class AtomicBombRoom: public BombRoom {
    public:
        AtomicBombRoom(int id): BombRoom(id) {};

        virtual MapSite* Enter();
};