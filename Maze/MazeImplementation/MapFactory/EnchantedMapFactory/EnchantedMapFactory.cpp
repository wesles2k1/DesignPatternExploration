#include "EnchantedMapFactory.h"

#include "../../MapSite/Room/EnchantedRoom/EnchantedRoom.h"
#include "../../MapSite/Door/EnchantedDoor/EnchantedDoor.h"

// Factory Methods

Room* EnchantedMapFactory::MakeRoom(int id) const {
    return new EnchantedRoom(id);
}

Door* EnchantedMapFactory::MakeDoor(Room* door1, Room* door2) const {
    return new EnchantedDoor(door1, door2);
}

// ------- //
// Private //
// ------- //

// Initialize instance to nullptr
// EnchantedMapFactory* EnchantedMapFactory::uniqueInstance = nullptr;