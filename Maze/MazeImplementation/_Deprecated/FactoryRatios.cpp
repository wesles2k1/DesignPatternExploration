#include <vector>

#include "FactoryRatios.h"

void FactoryRatios::AddOption(Option newOption) {
    elements.push_back(newOption);
}

void FactoryRatios::AddOptionAndRebalance(Option newOption) {
    elements.push_back(newOption);
    NormalizeOdds();
}

void FactoryRatios::AddOption(std::vector<Option> newOptions) {
    for(size_t i{0}; i < newOptions.size(); i++) {
        elements.push_back(newOptions[i]);
    }
}

void FactoryRatios::AddOptionAndRebalance(std::vector<Option> newOptions) {
    for(size_t i{0}; i < newOptions.size(); i++) {
        elements.push_back(newOptions[i]);
    }
    NormalizeOdds();
}

FactoryRatios::Option& FactoryRatios::operator[](size_t index) {
    if (index >= elements.size()) {
        exit(0);
    }
    return elements[index];
}

void FactoryRatios::NormalizeOdds() {

}