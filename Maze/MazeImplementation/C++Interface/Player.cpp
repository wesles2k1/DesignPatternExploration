#include <iostream>

#include "Player.h"

Player::Player(Room* startingRoom) {
    currentRoom = startingRoom;
}

void Player::SetRoom(Room* room) {
    currentRoom = room;
}

void Player::LookAround() {
    std::cout << "You are in room " << currentRoom->GetID() << std::endl;
}

void Player::Move(Direction direction) {
    MapSite* destination{nullptr};

    destination = currentRoom->GetSide(direction)->Enter();

    if(dynamic_cast<Room*>(destination) != nullptr) {
        currentRoom = dynamic_cast<Room*>(destination);
    } else if(dynamic_cast<Door*>(destination) != nullptr) {
        currentRoom = dynamic_cast<Room*>(dynamic_cast<Door*>(destination)->OtherSideFrom(currentRoom)->Enter());
    } else if(dynamic_cast<Wall*>(destination) != nullptr) {
        std::cout << "Ouch!" << std::endl;
    } else {
        std::cout << "I don't feel like moving." << std::endl;
    }
}