#include <iostream>

#include "MapFactory.h"

// ------ //
// Public //
// ------ //

// Returns instance of this class, creating one if necessary
/*
template <typename T>
T* MapFactory::GetInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new MapFactory();
    }
    return uniqueInstance;
}
*/

// Factory Methods

Map* MapFactory::MakeMap() const {
    return new Map();
}

Room* MapFactory::MakeRoom(int id) const {
    return new Room(id);
}

Wall* MapFactory::MakeWall() const {
    return new Wall();
}

Door* MapFactory::MakeDoor(Room* room1, Room* room2) const {
    return new Door(room1, room2);
}

Player* MapFactory::MakePlayer(Room* startingRoom) const {
    return new Player(startingRoom);
}

// --------- //
// Protected //
// --------- //

// Constructor
MapFactory::MapFactory() {
    
}