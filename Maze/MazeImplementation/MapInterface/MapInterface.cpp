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

void MapInterface::SetGenerationMethod(GenerationMethod newGenerationMethod) {
    generationMethod = newGenerationMethod;
}

Map* MapInterface::BuildMaze(MapType factory) {
    BuildMaze( { {factory, 1.0f} } );

    return GetMap();
}

Map* MapInterface::BuildMaze(std::vector<MapType> mapTypes) {
    // Reformat mapTypes
    std::vector<MapOption> mapOptions;
    for(size_t i{0}; i < mapTypes.size(); i++) {
        mapOptions.push_back( {mapTypes[i], 1.0f} );
    }
    
    BuildMazeTwoRooms(mapOptions);

    return GetMap();
}

// Final version of BuildMaze (other BuildMaze's call this)
Map* MapInterface::BuildMaze(std::vector<MapOption> mapTypes) {
    
    // Prepare the MapOptions for being used
    PrepMapOptions(mapTypes);

    // Prime the seed
    srand(static_cast<unsigned int>(time(0)));

    // Build the maze (This is where the GenerationEnum should be used!)
    switch(generationMethod) {
        case GenerationMethod::TwoRooms:
            map = BuildMazeTwoRooms(mapTypes);
            break;
        case GenerationMethod::Procedural:
            map = BuildMazeProcedural(mapTypes);
            break;
        case GenerationMethod::BinaryTree:
            map = BuildMazeTree(mapTypes);
            break;
        case GenerationMethod::Kruskal:
            map = BuildMazeKruskal(mapTypes);
            break;
        default:
            map = BuildMazeTwoRooms(mapTypes);
    }

    // Set the player (start at first room)
    player->SetRoom(map->GetRoom(0));

    return GetMap();
}

// ------- //
// Private //
// ------- //

MapFactory* MapInterface::RandomFactory(std::vector<MapOption>& factories) const {
    MapFactory* selectedFactory{nullptr};

    // Generate a random number with the range of (0.0, 1.0]
    float roll = (static_cast<float>(rand()) / RAND_MAX);

    // Use the number to select a factory
    auto iter{factories.begin()};
    while(selectedFactory == nullptr && iter != factories.end()) {
        roll -= iter->odds;
        if(roll <= 0.0) {
            selectedFactory = iter->factory.ToMapFactory();
            // Use to see what factory was the result
            //std::cout << iter->factory << std::endl;
        }
        iter++;
    }

    return selectedFactory;
}

void MapInterface::PrepMapOptions(std::vector<MapOption>& factories) const {

    std::vector<MapOption> tempFactories;

    // Composite duplicate entries
    for(auto iter: factories) {
        bool isDuplicate{false};
        size_t index{0};
        // Check for duplicate factories
        for(auto iterOther = tempFactories.begin(); iterOther != tempFactories.end(); ++iterOther) {
            if(iter.factory == iterOther->factory) {
                isDuplicate = true;
                index = std::distance(tempFactories.begin(), iterOther);
            }
        }
        if(isDuplicate) {
            // Composite with existing factory option
            tempFactories[index].odds += iter.odds;
        } else {
            // Add as a new factory
            tempFactories.push_back(iter);
        }
    }

    // Remove any entries with impossible odds
    for(auto iter = tempFactories.begin(); iter != tempFactories.end(); ++iter) {
        // Only keep entries with non-zero positive odds
        if(iter->odds <= 0.0) {
            tempFactories.erase(iter);
            --iter;
        }
    }
    
    // Normalize odds so their sum is 1.0
    float sum{0.0};
    for(auto iter = tempFactories.begin(); iter != tempFactories.end(); ++iter) {
        sum += iter->odds;
    }

    double multiplier = 1 / sum;
    for(auto iter = tempFactories.begin(); iter != tempFactories.end(); ++iter) {
        iter->odds *= static_cast<float>(multiplier);
    }

    // Clear factories and copy tempFactories over
    factories.clear();
    factories = tempFactories;

    // Default if every element has been removed (because of 0.0 odds)
    if(factories.empty()) {
        factories.push_back({});
    }

    // Output the final list of factories for testing and debugging
    for(auto iter: factories) {
        std::cout << static_cast<std::string>(iter.factory) << ", " << iter.odds << std::endl;
    }
}

Map* MapInterface::BuildMazeTwoRooms(std::vector<MapOption> mapTypes) {
    Map* mapTemp{nullptr};

    mapTemp = RandomFactory(mapTypes)->MakeMap();
    Room* r1 = RandomFactory(mapTypes)->MakeRoom(1);
    Room* r2 = RandomFactory(mapTypes)->MakeRoom(2);
    Door* theDoor = RandomFactory(mapTypes)->MakeDoor(r1, r2);

    mapTemp->AddRoom(r1);
    mapTemp->AddRoom(r2);

    r1->SetSide(Direction::North, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::East, theDoor);
    r1->SetSide(Direction::South, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(mapTypes)->MakeWall());

    r2->SetSide(Direction::North, RandomFactory(mapTypes)->MakeWall());
    r2->SetSide(Direction::East, RandomFactory(mapTypes)->MakeWall());
    r2->SetSide(Direction::South, RandomFactory(mapTypes)->MakeWall());
    r2->SetSide(Direction::West, theDoor);

    return mapTemp;
}

Map* MapInterface::BuildMazeProcedural(std::vector<MapOption> mapTypes) {
    Map* mapTemp{nullptr};

    mapTemp = RandomFactory(mapTypes)->MakeMap();
    Room* r1 = RandomFactory(mapTypes)->MakeRoom(1);

    mapTemp->AddRoom(r1);

    r1->SetSide(Direction::North, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::East, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::South, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(mapTypes)->MakeWall());

    return mapTemp;
}

Map* MapInterface::BuildMazeTree(std::vector<MapOption> mapTypes) {
    Map* mapTemp{nullptr};

    mapTemp = RandomFactory(mapTypes)->MakeMap();
    Room* r1 = RandomFactory(mapTypes)->MakeRoom(1);

    mapTemp->AddRoom(r1);

    r1->SetSide(Direction::North, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::East, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::South, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(mapTypes)->MakeWall());

    return mapTemp;
}

Map* MapInterface::BuildMazeKruskal(std::vector<MapOption> mapTypes) {
    Map* mapTemp{nullptr};

    mapTemp = RandomFactory(mapTypes)->MakeMap();
    Room* r1 = RandomFactory(mapTypes)->MakeRoom(1);

    mapTemp->AddRoom(r1);

    r1->SetSide(Direction::North, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::East, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::South, RandomFactory(mapTypes)->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(mapTypes)->MakeWall());

    return mapTemp;
}

// ============================================================= //
// The following is to be removed upon Unreal Engine integration //
// ============================================================= //

// ------ //
// Public //
// ------ //

void MapInterface::RunGame() {
    running = true;

    while(running) {
        PromptAction();
    }
}

// ------- //
// Private //
// ------- //

Player* MapInterface::MakePlayer(Room* startingRoom) const {
    return new Player(startingRoom);
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