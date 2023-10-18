#include <iostream>

#include "../MazeGame/MazeGame.h"
#include "../MazeGame/MapType.h"

#include "../Singleton/Singleton.h"

using namespace std;

int main() {

    // Creates game and demonstrates that other classes beyond MapFactory can utilize Singleton
    MazeGame* game = Singleton::Get<MazeGame>();

    // Creates first (and only) instance of BombMapFactory
    game->BuildMaze(MapType::Bomb);
    game->RunGame();
    /*
    // Creates first (and only) instance of EnchantedMapFactory
    game->BuildMaze(MapType::Enchanted);
    game->RunGame();
    
    // Recognizes the first BombMapFactory and uses that instead of making a new one.
    game->BuildMaze(MapType::Bomb);
    game->RunGame();

    // Creates first (and only) instance of MapFactory
    game->BuildMaze(MapType::Default);
    game->RunGame();
    
    // No argument results in a fully default maze being built
    game->BuildMaze();
    game->RunGame();
    */
    // Demonstrates composite use of factories (All have equal odds)
    game->BuildMaze( {
        {MapType::Default, 3.0f},
        {MapType::AtomicBomb, 3.0f},
        {MapType::Lock, 3.0f}
    } );
    game->RunGame();
    /*
    // Demonstrates composite use of factories (Enchanted will be removed)
    game->BuildMaze( {
        {MapType::Enchanted, 0.25f},
        {MapType::Bomb, 0.25f},
        {MapType::Enchanted, -0.35f},
        {MapType::Default, 1.5f},
    } );
    game->RunGame();

    // Demonstrates that invalid input results in default map
    game->BuildMaze({{MapType::Bomb, 0.0}});
    game->RunGame();
    */
    return 0;
}