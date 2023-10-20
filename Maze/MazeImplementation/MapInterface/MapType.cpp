#include "MapType.h"

// ------ //
// Public //
// ------ //

MapType::operator MapFactory*() const {
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
        case MapTypeEnum::AtomicBomb:
            returnFactory = Singleton::Get<AtomicBombMapFactory>();
            break;
        case MapTypeEnum::Lock:
            returnFactory = Singleton::Get<LockMapFactory>();
            break;
        default:
            returnFactory = nullptr;
    }

    return returnFactory;
}

MapType::operator std::string() const {
    std::string returnString{""};

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnString = "DefaultMap";
            break;
        case MapTypeEnum::Enchanted:
            returnString = "EnchantedMap";
            break;
        case MapTypeEnum::Bomb:
            returnString = "BombMap";
            break;
        case MapTypeEnum::AtomicBomb:
            returnString = "AtomicBombMap";
            break;
        case MapTypeEnum::Lock:
            returnString = "LockMap";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}
