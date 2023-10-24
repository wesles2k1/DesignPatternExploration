#include "GenerationMethod.h"

// ------ //
// Public //
// ------ //

GenerationMethod GenerationMethod::StringToGenerationMethod(std::string inputString) {
    std::transform(inputString.begin(), inputString.end(), inputString.begin(), [](unsigned char c){return std::tolower(c);});

    if(inputString == "two rooms") {
        *this = GenerationMethod::TwoRooms;
    } else if(inputString == "procedural") {
        *this = GenerationMethod::Procedural;
    } else if(inputString == "binary tree") {
        *this = GenerationMethod::BinaryTree;
    } else if(inputString == "kruskal") {
        *this = GenerationMethod::Kruskal;
    } else {
        *this = GenerationMethod::NULL_ENUM;
    }

    return *this;
}

GenerationMethod::operator std::string() const {
    std::string returnString{""};

    switch(enumVal) {
        case GenerationMethodEnum::TwoRooms:
            returnString = "Two Rooms";
            break;
        case GenerationMethodEnum::Procedural:
            returnString = "Procedural";
            break;
        case GenerationMethodEnum::BinaryTree:
            returnString = "Binary Tree";
            break;
        case GenerationMethodEnum::Kruskal:
            returnString = "Kruskal";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}
