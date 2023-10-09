#include <iostream>

#include "MazeGame/MazeGame.h"

using namespace std;

int main() {
    MazeGame game;

    game.CreateMaze();

    game.RunGame();

    return 0;
}