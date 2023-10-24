#pragma once

#include <string>
#include <algorithm>

// This will be exposed to Unreal Engine's Blueprints

// Anytime a new GenrationMethod is to be added, it must be added to:
//      enum GenrationMethod
//      StringToMapType()
//      operator std::string()

// A complex enumeration that specifies a type of map
class GenerationMethod {
    public:
        enum GenerationMethodEnum {
            NULL_ENUM,

            TwoRooms,
            Procedural,
            BinaryTree,
            Kruskal
        };

        GenerationMethod() {};
        GenerationMethod(GenerationMethodEnum input): enumVal(input) {};

        // Allows comparison with GenerationMethodEnum constants
        operator GenerationMethodEnum() const { return enumVal; }

        // Takes a string and sets/returns this GenerationMethod
        GenerationMethod StringToGenerationMethod(std::string inputString);
        // Returns the corresponding string
        explicit operator std::string() const;

    private:
        GenerationMethodEnum enumVal{GenerationMethodEnum::NULL_ENUM};
};