#include "BombMapFactory.h"

#include "../../MapSite/Room/BombRoom/BombRoom.h"
#include "../../MapSite/Wall/BombWall/BombWall.h"

// Factory Methods

Room* BombMapFactory::MakeRoom(int id) const {
    return new BombRoom(id);
}

Wall* BombMapFactory::MakeWall() const {
    return new BombWall();
}