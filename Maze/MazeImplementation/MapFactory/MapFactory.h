#pragma once

#include <iostream>
#include <type_traits>

#include "../Player/Player.h"
#include "../Map/Map.h"

class MapFactory {
    public:
        // The method by which this class can be instantiated or retrieved
        template <typename T>
        static T* GetInstance() {
            if (uniqueInstance<T> == nullptr) {
                std::cout << "Making new factory." << std::endl;
                uniqueInstance<T> = new T();
                // This function is lacking a way to ensure T is of type MapFactory, but incorrect use in this way doesn't seem to hinder its intended effect, so it isn't of great priority now
            } else {
                std::cout << "This factory already exists!" << std::endl;
            }
            return uniqueInstance<T>;
        }

        // Factory Methods
        virtual Map* MakeMap() const;
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
        virtual Player* MakePlayer(Room* startingRoom) const;

    protected:
        // The protected constructor of this class
            // This allows subclass constructors to be customized
            // The downside is that once instantiation has occurred, the object can't be constructed again at all with different parameters for different behaviors, but it would be possible (and might be worth doing) to add an additional method to this class that allows the reconstruction of a singleton instance for different parameterization.
        MapFactory();

    private:
        // The single instance of this class
        template <typename T>
        static T* uniqueInstance;
};

// Initialize instance to nullptr
template <typename T>
T* MapFactory::uniqueInstance = nullptr;