#pragma once

#include "../MazeGame.h"

class BombMazeGame: public MazeGame {
    public:
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
};