#pragma once

#include <vector>

#include "MapFactory/MapFactory.h"
#include "MapElement/MapElementInclude.h"

// Defines a Map
class Map {
    public:
        Map();

        void AddRoom(Room* newRoom);
        Room* GetRoom(int id) const;

    protected:
        std::vector<Room*> roomStorage;
        int nextRoomID{1};
};