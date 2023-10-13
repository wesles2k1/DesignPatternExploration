#pragma once

#include "MapType.h"

// This will be exposed to Unreal Engine's Blueprints

// Expresses a factory and its odds of being used
struct FactoryOption {
    MapType factory{MapType::Default};
    float odds{0.0};
};