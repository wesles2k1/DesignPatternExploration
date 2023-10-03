#pragma once

#include "../MapSite.h"
#include "../Direction.h"

// Defines a Room to be put into a Map
class Room: public MapSite {
    public:
        Room(int newRoomID);

        MapSite* GetSide(Direction direction);
        void SetSide(Direction direction, MapSite* element);

        int GetID();

        virtual MapSite* Enter();

    protected:
        MapSite* sides[4];
        int roomID{-1};
};