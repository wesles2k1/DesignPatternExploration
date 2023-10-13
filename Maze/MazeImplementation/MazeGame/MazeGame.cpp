#include "MazeGame.h"

// ------ //
// Public //
// ------ //

Map* MazeGame::BuildMaze(MapType factory) {
    return BuildMaze( { {factory, 1.0f} } );
}

Map* MazeGame::BuildMaze(std::vector<FactoryOption> factories) {
    Map* aMaze = nullptr;

    // Prepare the FactoryOptions for being used
    PrepFactoryOptions(factories);

    // Prime the seed
    srand(static_cast<unsigned int>(time(0)));

    aMaze = RandomFactory(factories)->MakeMap();
    Room* r1 = RandomFactory(factories)->MakeRoom(1);
    Room* r2 = RandomFactory(factories)->MakeRoom(2);
    Door* theDoor = RandomFactory(factories)->MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(Direction::North, RandomFactory(factories)->MakeWall());
    r1->SetSide(Direction::East, theDoor);
    r1->SetSide(Direction::South, RandomFactory(factories)->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(factories)->MakeWall());

    r2->SetSide(Direction::North, RandomFactory(factories)->MakeWall());
    r2->SetSide(Direction::East, RandomFactory(factories)->MakeWall());
    r2->SetSide(Direction::South, RandomFactory(factories)->MakeWall());
    r2->SetSide(Direction::West, theDoor);

    player = RandomFactory(factories)->MakePlayer(r1);

    return aMaze;
}

void MazeGame::RunGame() {
    running = true;

    while(running) {
        PromptAction();
    }
}

//Player* MazeGame::MakePlayer(Room* startingRoom) const {
//    return new Player(startingRoom);
//}

// ------- //
// Private //
// ------- //

void MazeGame::PromptAction() {
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

void MazeGame::PromptMove() {
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

MapFactory* MazeGame::RandomFactory(std::vector<FactoryOption>& factories) const {
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
            //std::cout << iter->factory.ToString() << std::endl;
        }
        iter++;
    }


    return selectedFactory;
}

void MazeGame::PrepFactoryOptions(std::vector<FactoryOption>& factories) const {
    std::vector<FactoryOption> tempFactories;

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

    // Output for testing and debugging
    //for(auto iter: factories) {
    //    std::cout << iter.factory.ToString() << ", " << iter.odds << std::endl;
    //}
    //std::cout << std::endl;
}
