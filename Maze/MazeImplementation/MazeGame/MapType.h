#pragma once

#include <string>

#include "../Singleton/Singleton.h"
#include "../MapFactory/MapFactory.h"
#include "../MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"
#include "../MapFactory/BombMapFactory/BombMapFactory.h"

// This will be exposed to Unreal Engine's Blueprints

// Anytime a new MapFactory is derived, it must be added to:
//      this file's #include
//      enum MapTypeEnum
//      ToMapFactory()
//      ToString()

// A complex enumeration that specifies a type of map
class MapType {
    public:
        enum MapTypeEnum {
            Default,
            Enchanted,
            Bomb
        };

        MapType() {};
        MapType(MapTypeEnum input): enumVal(input) {};

        // Allows comparison with MapTypeEnum constants
        operator MapTypeEnum() const { return enumVal; }

        // Returns the corresponding MapFactory
        MapFactory* ToMapFactory() const;
        // Returns the corresponding string
        std::string ToString() const;

    private:
        MapTypeEnum enumVal{MapTypeEnum::Default};
};

// A bit of credit from this is owed to Kered13 from https://www.reddit.com/r/cpp/comments/zw59lh/enums_with_methods/