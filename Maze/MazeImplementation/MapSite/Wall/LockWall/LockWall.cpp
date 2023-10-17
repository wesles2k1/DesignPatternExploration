#include <iostream>

#include "LockWall.h"

MapSite* LockWall::Enter() {
    std::cout << "There's a key hanging on the wall!" << std::endl;
    std::cout << "You don't think it's yours, though, so you better not take it." << std::endl;

    return this;
}