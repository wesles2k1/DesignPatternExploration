#include <iostream>

#include "MapFactory/Singleton.h"
#include "MazeGame/MazeGame.h"
#include "MapFactory/MapFactory.h"
#include "MapFactory/BombMapFactory/BombMapFactory.h"
#include "MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"

using namespace std;

int main() {

    MazeGame game;

    // First Game
    // Creates first (and only) instance of BombMapFactory
    game.CreateMaze(*MapFactory::GetInstance<BombMapFactory>());
    game.RunGame();
    
    // Second Game
    // Creates first (and only) instance of EnchantedMapFactory

    game.CreateMaze(*MapFactory::GetInstance<EnchantedMapFactory>());
    game.RunGame();

    // Third Game
    // Recognizes the first BombMapFactory and uses that instead of making a new one.

    game.CreateMaze(*MapFactory::GetInstance<BombMapFactory>());
    game.RunGame();

    // Fourth Game
    // Creates first (and only) instance of MapFactory
    game.CreateMaze(*MapFactory::GetInstance<MapFactory>());
    game.RunGame();
    
    return 0;
}