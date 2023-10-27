#include "LockMapFactory.h"

// Factory Methods

Door* LockMapFactory::MakeDoor(Room* door1, Room* door2) const {
    return new LockDoor(door1, door2);
}

Wall* LockMapFactory::MakeWall() const {
    return new LockWall();
}