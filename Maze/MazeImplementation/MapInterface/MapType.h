#pragma once

#include <string>
#include <algorithm>

#include "../Singleton/Singleton.h"
#include "../MapFactory/MapFactory.h"
#include "../MapFactory/BombMapFactory/BombMapFactory.h"
#include "../MapFactory/BombMapFactory/AtomicBombMapFactory/AtomicBombMapFactory.h"
#include "../MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"
#include "../MapFactory/LockMapFactory/LockMapFactory.h"

// This will be exposed to Unreal Engine's Blueprints

// Anytime a new MapFactory is added, it must be added to:
//      this file's #include
//      enum MapTypeEnum
//      ToMapFactory()
//      StringToMapType()
//      operator std::string()

// A complex enumeration that specifies a type of map
class MapType {
    public:
        enum MapTypeEnum {
            NULL_ENUM,

            Default,
            Bomb,
            AtomicBomb,
            Enchanted,
            Lock
        };

        MapType() {};
        MapType(MapTypeEnum input): enumVal(input) {};

        // Allows comparison with MapTypeEnum constants
        operator MapTypeEnum() const { return enumVal; }

        // Returns the corresponding MapFactory
        MapFactory* ToMapFactory() const;

        // Takes a string and sets/returns this MapType
        MapType StringToMapType(std::string inputString);
        // Returns the corresponding string
        explicit operator std::string() const;

    private:
        MapTypeEnum enumVal{MapTypeEnum::Default};
};

// A bit of credit from this is owed to Kered13 from https://www.reddit.com/r/cpp/comments/zw59lh/enums_with_methods/