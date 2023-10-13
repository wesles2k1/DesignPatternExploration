#pragma once

#include <vector>

#include "../MapFactory/MapFactory.h"

// A list of different factories and their corresponding frequencies by percentage
// This might be better off as a struct that corrects itself (more info in MazeGame::RandomFactory)

// I wonder if this can be generallized like how Singleton was? Template "MapFactory" in Option?
class FactoryRatios {
    public:
        // The elements that make up this class's list
        struct Option {
            MapFactory* factory{nullptr};
            float odds{0.0};
        };
        
        // Is there a way to consolidate these?
        void AddOption(Option newOption); // Replacement to PushBack
        void AddOptionAndRebalance(Option newOption); // Calls AddOption and then NormalizeOdds
        void AddOption(std::vector<Option> newOptions); // Allows for multiple options to be added at once
        void AddOptionAndRebalance(std::vector<Option> newOptions); // Calls AddOption and then NormalizeOdds

        Option& operator[](size_t index); // Accessor

        // Readjust all "odds" values so they sum up to 1.0 while keeping their reletive proportions to each other
        void NormalizeOdds();

    private:
        std::vector<Option> elements{};
};