#include "AtomicBombMapFactory.h"

// Factory Methods

Room* AtomicBombMapFactory::MakeRoom(int id) const {
    return new AtomicBombRoom(id);
}