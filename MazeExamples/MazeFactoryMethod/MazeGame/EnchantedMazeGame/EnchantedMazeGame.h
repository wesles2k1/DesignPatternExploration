#pragma once

#include "../MazeGame.h"

class EnchantedMazeGame: public MazeGame {
    public:
        virtual Room* MakeRoom(int id) const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
};