#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include "../Player/Player.h"
#include "MapType.h"
#include "FactoryOption.h"

class MapFactory;

class MazeGame {
    public:
        Map* BuildMaze(MapType factory = MapType::Default);
        Map* BuildMaze(std::vector<FactoryOption> factories);

    private:
        // Returns a random MapFactory from the list based on corresponding odds
        MapFactory* RandomFactory(std::vector<FactoryOption>& factories) const;

        // Reformats given FactoryOptions, removing duplicate factories, impossible odds, and normalizing odds to (0.0, 1.0]
        void PrepFactoryOptions(std::vector<FactoryOption>& factories) const;

    // The following is to be removed upon Unreal Engine integration.

    public:
        void RunGame();

        // Factory Method
        //Player* MakePlayer(Room* startingRoom) const;

    private:
        Player* player{nullptr};
        bool running{false};

        void PromptAction();
        void PromptMove();
};