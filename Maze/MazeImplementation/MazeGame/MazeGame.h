#pragma once

#include "../MapFactory/MapFactory.h"

class MapFactory;

class MazeGame {
    public:
        Map* CreateMaze(MapFactory& factory);
        void RunGame();

    protected:
        Player* player{nullptr};
        bool running{false};

        void PromptAction();
        void PromptMove();
};