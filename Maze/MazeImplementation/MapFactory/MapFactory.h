#pragma once

#include <iostream>

#include "../Player/Player.h"
#include "../Map/Map.h"

class MapFactory {
    public:
        // Factory Methods
        virtual Map* MakeMap() const;
        virtual Room* MakeRoom(int id) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
        virtual Player* MakePlayer(Room* startingRoom) const;

        // The method by which this class can be instantiated or retrieved
        template <typename T>
        static T* GetInstance() {
            if (uniqueInstance<T> == nullptr) {
                //std::cout << "Making new factory." << std::endl;
                // Sets the uniqueInstance, but WILL NOT COMPILE if T is anything but a MapFactory
                // This is intentional so as to disallow any instances that is not of this hierarchy
                uniqueInstance<T> = dynamic_cast<T*>(dynamic_cast<MapFactory*>(new T()));
            } else {
                //std::cout << "This factory already exists!" << std::endl;
            }
            // Will ALWAYS return a MapFactory, NEVER nullptr
            return uniqueInstance<T>;
        }

    protected:
        // The protected constructor of this class, allowing for children
        MapFactory();

    private:
        // The single instance of this class
        template <typename T>
        static T* uniqueInstance;
};

// Initialize instance to nullptr
template <typename T>
T* MapFactory::uniqueInstance = nullptr;