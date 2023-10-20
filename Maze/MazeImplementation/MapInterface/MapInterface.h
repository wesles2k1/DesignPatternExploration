#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include "../Player/Player.h"
#include "MapType.h"
#include "MapOption.h"
#include "../MapFactory/MapFactory.h"

enum class GenerationMethod {
    TwoRooms,
    Procedural,
    BinaryTree,
    Kruskal
};

class MapInterface {
    public:
        MapInterface();

        Map* GetMap();

        void SetGenerationMethod(GenerationMethod newGenerationMethod);

        // Called by client to construct the maze
        Map* BuildMaze(MapType mapType = MapType::Default);
        Map* BuildMaze(std::vector<MapType> mapTypes);
        Map* BuildMaze(std::vector<MapOption> mapTypes);

    private:
        Map* map{nullptr};
        GenerationMethod generationMethod{GenerationMethod::TwoRooms};

        // Returns a random MapFactory from the list based on corresponding odds
        MapFactory* RandomFactory(std::vector<MapOption>& mapTypes) const;

        // Reformats given MapOptions, removing duplicate factories, impossible odds, and normalizing odds to (0.0, 1.0]
        void PrepMapOptions(std::vector<MapOption>& mapTypes) const;

        // Various methods for building the maze

        // Two rooms horizontally connected by a single door
        Map* BuildMazeTwoRooms(std::vector<MapOption> mapTypes);
        // Builds a maze by adding rooms to doors that have been randomly added to rooms
        Map* BuildMazeProcedural(std::vector<MapOption> mapTypes);
        // Builds a maze with the Binary Tree algorithm
        Map* BuildMazeTree(std::vector<MapOption> mapTypes);
        // Builds a maze using Kruskal's algorithm; Makes a rectangularly filled maze
        Map* BuildMazeKruskal(std::vector<MapOption> mapTypes);

    // ============================================================= //
    // The following is to be removed upon Unreal Engine integration //
    // ============================================================= //

    public:
        void RunGame();

    private:
        Player* player{nullptr};
        bool running{false};

        // Factory Method
        Player* MakePlayer(Room* startingRoom = nullptr) const;

        // User interaction
        void PromptAction();
        void PromptMove();
};