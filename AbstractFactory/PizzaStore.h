// Abstract Creator Class (defines abstract factory method)

#pragma once

#include "Pizza.h"

class PizzaStore {
    public:
        Pizza* OrderPizza(PizzaType type);
    
    protected:
        // The Factory Method
        virtual Pizza* CreatePizza(PizzaType type) = 0;
};