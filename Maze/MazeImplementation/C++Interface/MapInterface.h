#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include "Player.h"
#include "../MapGenerator/MapGenerator.h"
#include "../MapParameters/GenerationMethod.h"
#include "../MapParameters/MapOption.h"

// Interaction in a terminal environment
class MapInterface {
    public:
        MapInterface();

        Map* GetMap();

        // Interacts with the user
        void RunGame();
        void PromptGenerationMethod();
        void PromptMapType();

        // Sets the generation method to be used
        void SetGenerationMethod(GenerationMethod newGenerationMethod);

        // Called by client to construct the maze
        Map* BuildMaze(MapType givenMapType = MapType::Default);
        Map* BuildMaze(std::vector<MapType> givenMapTypes);
        Map* BuildMaze(std::vector<MapOption> givenMapTypes);

    private:
        Map* map{nullptr};
        Player* player{nullptr};
        bool running{false};

        GenerationMethod generationMethod{GenerationMethod::NULL_ENUM};
        MapType mapType{MapType::NULL_ENUM};

        // Factory Method
        Player* MakePlayer(Room* startingRoom = nullptr) const;
        
        // Interacts with the user
        void PromptAction();
        void PromptMove();
};