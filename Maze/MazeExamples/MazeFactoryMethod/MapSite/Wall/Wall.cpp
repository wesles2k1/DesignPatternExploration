#include <iostream>

#include "Wall.h"

Wall::Wall() {

}

MapSite* Wall::Enter() {
    std::cout << "Ran into wall!" << std::endl;

    return this;
}