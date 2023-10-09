#include "BombMazeGame.h"

#include "../../MapSite/Room/BombRoom/BombRoom.h"
#include "../../MapSite/Wall/BombWall/BombWall.h"

Room* BombMazeGame::MakeRoom(int id) const {
    return new BombRoom(id);
}

Wall* BombMazeGame::MakeWall() const {
    return new BombWall();
}