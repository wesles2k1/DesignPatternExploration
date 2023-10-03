#include "Map.h"

Map::Map() {
    
}

void Map::AddRoom(Room* newRoom) {
    roomStorage.push_back(newRoom);
}

Room* Map::GetRoom(int id) const {
    return roomStorage[id];
}