#include "MapInterface.h"

// ------ //
// Public //
// ------ //

MapInterface::MapInterface() {
    player = MakePlayer();
}

Map* MapInterface::GetMap() {
    return map;
}

void MapInterface::RunGame() {
    running = true;

    while(running) {
        PromptAction();
    }
}

void MapInterface::PromptGenerationMethod() {
    if(generationMethod == GenerationMethod::NULL_ENUM) {
        std::cout << "Please enter a generation method:" << std::endl;
        std::string inputString;
        while(generationMethod == GenerationMethod::NULL_ENUM) {
            getline(std::cin, inputString);
            generationMethod.StringToGenerationMethod(inputString);
            if(generationMethod == GenerationMethod::NULL_ENUM) {
                std::cout << "Unknown generation method. Please try again." << std::endl;
            } else {
                std::cout << "Generation method: " << static_cast<std::string>(generationMethod) << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void MapInterface::PromptMapType() {
    if(mapType == MapType::NULL_ENUM) {
        std::cout << "Please enter a map type:" << std::endl;
        std::string inputString;
        while(mapType == MapType::NULL_ENUM) {
            getline(std::cin, inputString);
            mapType.StringToMapType(inputString);
            if(mapType == MapType::NULL_ENUM) {
                std::cout << "Unknown map type. Please try again." << std::endl;
            } else {
                std::cout << "Map type: " << static_cast<std::string>(mapType) << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void MapInterface::SetGenerationMethod(GenerationMethod newGenerationMethod) {
    generationMethod = newGenerationMethod;
}

Map* MapInterface::BuildMaze(MapType givenMapType) {
    BuildMaze( { {givenMapType, 1.0f} } );

    return GetMap();
}

Map* MapInterface::BuildMaze(std::vector<MapType> givenMapTypes) {
    // Reformat givenMapTypes
    std::vector<MapOption> mapOptions;
    for(size_t i{0}; i < givenMapTypes.size(); i++) {
        mapOptions.push_back( {givenMapTypes[i], 1.0f} );
    }
    
    BuildMaze(mapOptions);

    return GetMap();
}

// Final version of BuildMaze (other BuildMazes call this)
Map* MapInterface::BuildMaze(std::vector<MapOption> givenMapTypes) {

    // Set the pool of MapTypes
    MapGenerator::SetMapTypes(givenMapTypes);

    // Build the maze (This is where the GenerationEnum should be used!)
    switch(generationMethod) {
        case GenerationMethod::TwoRooms:
            map = MapGenerator::BuildMazeTwoRooms();
            break;
        case GenerationMethod::Procedural:
            map = MapGenerator::BuildMazeProcedural();
            break;
        case GenerationMethod::BinaryTree:
            map = MapGenerator::BuildMazeTree();
            break;
        case GenerationMethod::Kruskal:
            map = MapGenerator::BuildMazeKruskal();
            break;
        default:
            map = MapGenerator::BuildMazeTwoRooms();
    }

    // Set the player (start at first room)
    player->SetRoom(map->GetRoom(0));

    return GetMap();
}

// ------- //
// Private //
// ------- //

Player* MapInterface::MakePlayer(Room* startingRoom) const {
    return new Player(startingRoom);
}

void MapInterface::PromptAction() {
    std::string action{};

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[MOVE] [LOOK] [QUIT]" << std::endl;
    std::cin >> action;
    std::cout << std::endl;

    std::transform(action.begin(), action.end(), action.begin(), [](unsigned char c){return std::tolower(c);});
    if(action == "move") {
        PromptMove();
        std::cout << std::endl;
    } else if(action == "look") {
        player->LookAround();
        std::cout << std::endl;
    } else if(action == "quit") {
        running = false;
    } else {
        std::cout << "Action not recognized. Please try again" << std::endl;
        std::cout << std::endl;
    }
}

void MapInterface::PromptMove() {
    std::string direction{};

    std::cout << "What direction would you like to move?" << std::endl;
    std::cout << "[NORTH] [EAST] [SOUTH] [WEST]" << std::endl;
    std::cin >> direction;
    std::cout << std::endl;

    std::transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c){return std::tolower(c);});
    if(direction == "north") {
        player->Move(Direction::North);
    } else if(direction == "east") {
        player->Move(Direction::East);
    } else if(direction == "south") {
        player->Move(Direction::South);
    } else if(direction == "west") {
        player->Move(Direction::West);
    } else {
        std::cout << "Direction not recognized. Please try again." << std::endl;
    }
}