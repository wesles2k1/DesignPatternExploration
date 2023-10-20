#pragma once

#include "../Map/Map.h"

class Player {
    public:
        Player(Room* startingRoom = nullptr);

        void SetRoom(Room* room);

        void LookAround();
        void Move(Direction direction);

    private:
        Room* currentRoom{nullptr};
};