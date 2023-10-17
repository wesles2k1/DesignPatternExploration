#include "BombMapFactory.h"

// Factory Methods

Room* BombMapFactory::MakeRoom(int id) const {
    return new BombRoom(id);
}

Wall* BombMapFactory::MakeWall() const {
    return new BombWall();
}