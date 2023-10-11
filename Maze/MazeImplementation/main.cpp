#include <iostream>

#include "Singleton/Singleton.h"
#include "MazeGame/MazeGame.h"
#include "MapFactory/MapFactory.h"
#include "MapFactory/BombMapFactory/BombMapFactory.h"
#include "MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"

using namespace std;

int main() {

    // Creates game and demonstrates that other classes beyond MapFactory can utilize Singleton
    auto gameTest = Singleton::Get<MazeGame>();

    // First Game
    // Creates first (and only) instance of BombMapFactory
    gameTest->CreateMaze(*Singleton::Get<BombMapFactory>());
    Singleton::Get<MazeGame>()->RunGame();
    
    // Second Game
    // Creates first (and only) instance of EnchantedMapFactory
    Singleton::Get<MazeGame>()->CreateMaze(*Singleton::Get<EnchantedMapFactory>());
    Singleton::Get<MazeGame>()->RunGame();

    // Third Game
    // Recognizes the first BombMapFactory and uses that instead of making a new one.
    gameTest->CreateMaze(*Singleton::Get<BombMapFactory>());
    gameTest->RunGame();

    // Fourth Game
    // Creates first (and only) instance of MapFactory
    Singleton::Get<MazeGame>()->CreateMaze(*Singleton::Get<MapFactory>());
    gameTest->RunGame();

    // Throughout, gameTest and Singleton::Get<MazeGame>() are used interchangably, both referring to the same, consistant instance of MazeGame.
    
    return 0;
}