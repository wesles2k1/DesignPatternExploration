#include <iostream>

#include "MazeGame/BombMazeGame/BombMazeGame.h"
#include "MazeGame/EnchantedMazeGame/EnchantedMazeGame.h"

using namespace std;

int main() {
    EnchantedMazeGame game;

    game.CreateMaze();

    game.RunGame();

    return 0;
}