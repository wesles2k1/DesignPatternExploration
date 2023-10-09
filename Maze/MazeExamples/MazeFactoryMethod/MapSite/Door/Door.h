#pragma once

#include "../Room/Room.h"

// Defines a Door to be put into a Map
class Door: public MapSite {
    public:
        Door(Room* newRoom1 = nullptr, Room* newRoom2 = nullptr);
        
        virtual MapSite* Enter();
        Room* OtherSideFrom(Room*);

    protected:
        Room* room1{nullptr};
        Room* room2{nullptr};
        bool isOpen{false};
};