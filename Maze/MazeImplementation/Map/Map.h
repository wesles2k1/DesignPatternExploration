#pragma once

#include <vector>

#include "MapElement/Room/Room.h"
#include "MapElement/Door/Door.h"
#include "MapElement/Wall/Wall.h"
#include "MapElement/Direction.h"

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