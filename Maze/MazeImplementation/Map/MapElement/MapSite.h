#pragma once

// Defines a component of the map/part of the room
class MapSite {
    public:
        virtual ~MapSite() = default;
        virtual MapSite* Enter() = 0;
};