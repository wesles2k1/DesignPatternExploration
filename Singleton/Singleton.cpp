#include "Singleton.h"

// Public

Singleton* Singleton::GetInstance(std::string newValue) {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new Singleton(newValue);
    }
    return uniqueInstance;
}

std::string Singleton::GetValue() {
    return value;
}

// Private

Singleton* Singleton::uniqueInstance = nullptr;

Singleton::Singleton(std::string newValue) {
    value = newValue;
}