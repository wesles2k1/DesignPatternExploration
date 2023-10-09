#pragma once

#include <string>

// A singleton wrapper to provide access to the map facotries
template <typename T> class MapFactoryMaster {
    public:
        static MapFactoryMaster* GetInstance();
    protected:
        static MapFactoryMaster* uniqueInstance;
        MapFactoryMaster();
};