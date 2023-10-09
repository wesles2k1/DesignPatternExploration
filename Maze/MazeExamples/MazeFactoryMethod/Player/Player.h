#pragma once

#include "../Map/Map.h"

class Player {
    public:
        Player(Room* startingRoom);

        void LookAround();
        void Move(Direction direction);

    private:
        Room* currentRoom{nullptr};
};