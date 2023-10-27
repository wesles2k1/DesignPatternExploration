#include <iostream>

#include "Room.h"

Room::Room(int newRoomID) {
    roomID = newRoomID;
}

MapSite* Room::GetSide(Direction direction) {
    MapSite* returnElement{nullptr};

    switch (direction) {
        case Direction::North:
            returnElement = sides[0];
            break;
        case Direction::East:
            returnElement = sides[1];
            break;
        case Direction::South:
            returnElement = sides[2];
            break;
        case Direction::West:
            returnElement = sides[3];
            break;
        case Direction::Default:
        default:
            returnElement = nullptr;
    }

    return returnElement;
}

void Room::SetSide(Direction direction, MapSite* element) {
    switch (direction) {
        case Direction::North:
            sides[0] = element;
            break;
        case Direction::East:
            sides[1] = element;
            break;
        case Direction::South:
            sides[2] = element;
            break;
        case Direction::West:
            sides[3] = element;
            break;
        case Direction::Default:
            break;
    }
}

void Room::RemoveSide(Direction direction) {
    switch (direction) {
        case Direction::North:
            delete sides[0];
            sides[0] = nullptr;
            break;
        case Direction::East:
            delete sides[1];
            sides[1] = nullptr;
            break;
        case Direction::South:
            delete sides[2];
            sides[2] = nullptr;
            break;
        case Direction::West:
            delete sides[3];
            sides[3] = nullptr;
            break;
        case Direction::Default:
            break;
    }
}

int Room::GetID() {
    return roomID;
}

MapSite* Room::Enter() {
    std::cout << "Entering room!" << std::endl;

    return this;
}