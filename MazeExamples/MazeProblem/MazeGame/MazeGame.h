#pragma once

#include "../Player/Player.h"
#include "../Map/Map.h"

class MazeGame {
    public:
        Map* CreateMaze();
        void RunGame();

    protected:
        Player* player{nullptr};
        bool running{false};

        void PromptAction();
        void PromptMove();
};