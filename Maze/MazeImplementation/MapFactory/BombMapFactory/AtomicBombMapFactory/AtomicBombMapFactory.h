#pragma once

#include "../BombMapFactory.h"

#include "../../../MapSite/Room/BombRoom/AtomicBombRoom/AtomicBombRoom.h"

class AtomicBombMapFactory: public BombMapFactory {
    public:
        // Factory Methods
        virtual Room* MakeRoom(int id) const;

    // Allow for Singleton behavior
    protected:
        AtomicBombMapFactory() {};
    friend class Singleton;
};