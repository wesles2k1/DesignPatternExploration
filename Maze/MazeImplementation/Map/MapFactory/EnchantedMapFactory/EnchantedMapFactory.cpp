#include "EnchantedMapFactory.h"

// Factory Methods

Room* EnchantedMapFactory::MakeRoom(int id) const {
    return new EnchantedRoom(id);
}

Door* EnchantedMapFactory::MakeDoor(Room* door1, Room* door2) const {
    return new EnchantedDoor(door1, door2);
}