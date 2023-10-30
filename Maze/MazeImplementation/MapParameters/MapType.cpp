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

MapType MapType::StringToMapType(std::string inputString) {
    std::transform(inputString.begin(), inputString.end(), inputString.begin(), [](unsigned char c){return std::tolower(c);});

    if(inputString == "default") {
        *this = MapType::Default;
    } else if(inputString == "enchanted") {
        *this = MapType::Enchanted;
    } else if(inputString == "bomb") {
        *this = MapType::Bomb;
    } else if(inputString == "atomic bomb") {
        *this = MapType::AtomicBomb;
    } else if(inputString == "lock") {
        *this = MapType::Lock;
    } else {
        *this = MapType::NULL_ENUM;
    }
    
    return *this;
}

MapType::operator std::string() const {
    std::string returnString{""};

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnString = "Default";
            break;
        case MapTypeEnum::Enchanted:
            returnString = "Enchanted";
            break;
        case MapTypeEnum::Bomb:
            returnString = "Bomb";
            break;
        case MapTypeEnum::AtomicBomb:
            returnString = "Atomic Bomb";
            break;
        case MapTypeEnum::Lock:
            returnString = "Lock";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}
