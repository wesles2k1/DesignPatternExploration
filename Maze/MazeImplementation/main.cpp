#include <iostream>

#include "MazeGame/MazeGame.h"
#include "MazeGame/MapType.h"

#include "Singleton/Singleton.h"

using namespace std;

int main() {

    // Creates game and demonstrates that other classes beyond MapFactory can utilize Singleton
    MazeGame* game = Singleton::Get<MazeGame>();

    // First Game
    // Creates first (and only) instance of BombMapFactory
    game->BuildMaze(MapType::Bomb);
    game->RunGame();
    
    // Second Game
    // Creates first (and only) instance of EnchantedMapFactory
    game->BuildMaze(MapType::Enchanted);
    game->RunGame();
    
    // Third Game
    // Recognizes the first BombMapFactory and uses that instead of making a new one.
    game->BuildMaze(MapType::Bomb);
    game->RunGame();

    // Fourth Game
    // Creates first (and only) instance of MapFactory
    game->BuildMaze(MapType::Default);
    game->RunGame();
    
    // Fifth Game
    // No argument results in a fully default maze being built
    game->BuildMaze();
    game->RunGame();

    // Sixth Game
    // Demonstrates composite use of factories (All have equal chance)
    game->BuildMaze( {
        {MapType::Default, 3.0f},
        {MapType::Bomb, 3.0f},
        {MapType::Enchanted, 3.0f}
    } );
    game->RunGame();

    // Seventh Game
    // Demonstrates composite use of factories (Enchanted will be removed)
    game->BuildMaze( {
        {MapType::Enchanted, 0.25f},
        {MapType::Bomb, 0.25f},
        {MapType::Enchanted, -0.35f},
        {MapType::Default, 1.5f},
    } );
    game->RunGame();
    
    // Issues:

    // This is a valid parameter, but I'm not quite sure how to check for it or protect against it, as it breaks everything
    //game->BuildMaze( { {},{} } );
    
    return 0;
}