#pragma once

#include <vector>

#include "../MapSite/Room/Room.h"
#include "../MapSite/Door/Door.h"
#include "../MapSite/Wall/Wall.h"
#include "../MapSite/Direction.h"

// Defines a Map
class Map {
    public:
        Map();

        void AddRoom(Room* newRoom);
        Room* GetRoom(int id) const;

    protected:
        std::vector<Room*> roomStorage;
};