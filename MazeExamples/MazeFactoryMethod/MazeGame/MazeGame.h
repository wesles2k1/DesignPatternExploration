#pragma once

#include "../Player/Player.h"
#include "../Map/Map.h"

class MazeGame {
    public:
        Map* CreateMaze();
        void RunGame();

        // Factory Methods
        virtual Map* MakeMap() const;
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
        virtual Player* MakePlayer(Room* startingRoom) const;

    protected:
        Player* player{nullptr};
        bool running{false};

        void PromptAction();
        void PromptMove();
};