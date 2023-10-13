#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include "../Player/Player.h"
#include "MapType.h"
#include "MapOption.h"

class MapFactory;

class MazeGame {
    public:
        Map* BuildMaze(MapType factory = MapType::Default);
        Map* BuildMaze(std::vector<MapOption> factories);

    private:
        // Returns a random MapFactory from the list based on corresponding odds
        MapFactory* RandomFactory(std::vector<MapOption>& factories) const;

        // Reformats given MapOptions, removing duplicate factories, impossible odds, and normalizing odds to (0.0, 1.0]
        void PrepMapOptions(std::vector<MapOption>& factories) const;

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