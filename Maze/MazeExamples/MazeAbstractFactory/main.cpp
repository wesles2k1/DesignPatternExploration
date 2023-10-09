#include <iostream>

#include "MazeGame/MazeGame.h"
#include "MapFactory/BombMapFactory/BombMapFactory.h"
#include "MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"

using namespace std;

int main() {
    MazeGame game;
    EnchantedMapFactory factory;

    game.CreateMaze(factory);

    game.RunGame();

    return 0;
}