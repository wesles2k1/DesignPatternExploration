#pragma once

#include <vector>

#include "../Map/Map.h"
#include "../MapParameters/MapOption.h"

// Static class that builds a maze based on set MapTypes
class MapGenerator final {
    public:
        static void SetMapTypes(std::vector<MapOption> givenMapTypes);
        static std::vector<MapOption> GetMapTypes();

        // Two rooms horizontally connected by a single door
        static Map* BuildMazeTwoRooms();
        // Builds a maze by adding rooms to doors that have been randomly added to rooms
        static Map* BuildMazeProcedural();
        // Builds a maze with the Binary Tree algorithm
        static Map* BuildMazeTree();
        // Builds a maze using Kruskal's algorithm; Makes a rectangularly filled maze
        static Map* BuildMazeKruskal();
        
    private:
        // Private deleted constructor to prevent instantiation of this class
        MapGenerator() = delete;
        
        // A work around to have a private static non-constant variable with a default value
        // This is treated similarly to a variable, just wrapped within a function
        static std::vector<MapOption>& MapTypes();

        // Map Factory Method
        static Map* MakeMap();

        static Room* BuildRoom(int id, /*Direction direction, */std::vector<MapOption> mapTypes);

        // Returns a random MapFactory from the list based on corresponding odds
        static MapFactory* RandomFactory(std::vector<MapOption>& mapTypes);

        // Reformats given MapOptions, removing duplicate factories, impossible odds, and normalizing odds to (0.0, 1.0]
        static void PrepMapOptions(std::vector<MapOption>& mapTypes);
};