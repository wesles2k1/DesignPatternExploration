#include <iostream>
#include <string>

#include "MazeGame.h"

Map* MazeGame::CreateMaze() {
    Map* aMaze = new Map;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(Direction::North, new Wall);
    r1->SetSide(Direction::East, theDoor);
    r1->SetSide(Direction::South, new Wall);
    r1->SetSide(Direction::West, new Wall);

    r2->SetSide(Direction::North, new Wall);
    r2->SetSide(Direction::East, new Wall);
    r2->SetSide(Direction::South, new Wall);
    r2->SetSide(Direction::West, theDoor);

    player = new Player(r1);

    return aMaze;
}

void MazeGame::RunGame() {
    running = true;

    while(running) {
        PromptAction();
    }
}

void MazeGame::PromptAction() {
    std::string action{};

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[MOVE]" << std::endl;
    std::cout << "[LOOK]" << std::endl;
    std::cout << "[QUIT]" << std::endl;
    std::cin >> action;
    std::cout << std::endl;

    if(action == "move") {
        PromptMove();
    } else if(action == "look") {
        player->LookAround();
    } else if(action == "quit") {
        running = false;
    } else {
        std::cout << "Action not recognized. Please try again" << std::endl;
    }
    std::cout << std::endl;
}

void MazeGame::PromptMove() {
    std::string direction{};

    std::cout << "What direction would you like to move?" << std::endl;
    std::cout << "[NORTH]" << std::endl;
    std::cout << "[EAST]" << std::endl;
    std::cout << "[SOUTH]" << std::endl;
    std::cout << "[WEST]" << std::endl;
    std::cin >> direction;
    std::cout << std::endl;

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