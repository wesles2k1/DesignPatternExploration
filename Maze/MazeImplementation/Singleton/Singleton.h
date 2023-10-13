#pragma once

#include <iostream>

// Statically retrieves or creates a one-of-a-kind instance of any desired classes
// Classes to be used must declare Singleton as a friend and should protect or privatize their constructor
// Allows parent-child coexistence
class Singleton final {
    public:
        // Retreives or creates (if necessary) a one-of-a-kind instance of a class
        template <typename T>
        static T* Get() {
            if (uniqueInstance<T> == nullptr) {
                //std::cout << "Making new instance." << std::endl;
                uniqueInstance<T> = new T();
            } else {
                //std::cout << "This instance already exists!" << std::endl;
            }
            return uniqueInstance<T>;
        }

    private:
        // Private deleted constructor to prevent instantiation of this class
        Singleton() = delete;

        // The one-of-a-kind instance of a class
        template <typename T>
        static T* uniqueInstance;
};

// Initialize instance to nullptr
template <typename T>
T* Singleton::uniqueInstance = nullptr;