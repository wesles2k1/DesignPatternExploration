#include "EnchantedMazeGame.h"

#include "../../MapSite/Room/EnchantedRoom/EnchantedRoom.h"
#include "../../MapSite/Door/EnchantedDoor/EnchantedDoor.h"

Room* EnchantedMazeGame::MakeRoom(int id) const {
    return new EnchantedRoom(id);
}

Door* EnchantedMazeGame::MakeDoor(Room* door1, Room* door2) const {
    return new EnchantedDoor(door1, door2);
}