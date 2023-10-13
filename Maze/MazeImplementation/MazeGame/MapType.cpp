#include "MapType.h"

// ------ //
// Public //
// ------ //

MapFactory* MapType::ToMapFactory() const {
    MapFactory* returnFactory;

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnFactory = Singleton::Get<MapFactory>();
            break;
        case MapTypeEnum::Enchanted:
            returnFactory = Singleton::Get<EnchantedMapFactory>();
            break;
        case MapTypeEnum::Bomb:
            returnFactory = Singleton::Get<BombMapFactory>();
            break;
        default:
            returnFactory = nullptr;
    }

    return returnFactory;
}

std::string MapType::ToString() const {
    std::string returnString{""};

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnString = "MapFactory";
            break;
        case MapTypeEnum::Enchanted:
            returnString = "EnchantedMapFactory";
            break;
        case MapTypeEnum::Bomb:
            returnString = "BombMapFactory";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}