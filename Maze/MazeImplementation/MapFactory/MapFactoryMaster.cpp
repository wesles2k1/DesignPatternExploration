#include "MapFactoryMaster.h"

// ------ //
// Public //
// ------ //

template <typename T>
MapFactoryMaster<T>* MapFactoryMaster<T>::GetInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new MapFactoryMaster<T>();
    }
    return uniqueInstance;
}

// ------- //
// Private //
// ------- //

// Initialize instance to nullptr
template <typename T>
MapFactoryMaster<T>* MapFactoryMaster<T>::uniqueInstance = nullptr;

// Constructor
template <typename T>
MapFactoryMaster<T>::MapFactoryMaster() {

}