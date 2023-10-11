#pragma once

#include <iostream>

class Singleton {
    public:
        // The method by which this class can be instantiated or retrieved
        template <typename T>
        static T* GetInstance() {
            if (uniqueInstance<T> == nullptr) {
                //std::cout << "Making new instance." << std::endl;
                uniqueInstance<T> = new T();
            } else {
                //std::cout << "This instance already exists!" << std::endl;
            }
            return uniqueInstance<T>;
        }

    protected:
        // The protected constructor of this class, allowing for children
        Singleton() {};

    private:
        // The single instance of this class
        template <typename T>
        static T* uniqueInstance;
};

// Initialize instance to nullptr
template <typename T>
T* Singleton::uniqueInstance = nullptr;