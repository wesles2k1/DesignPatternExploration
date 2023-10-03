// Concrete Creator

#pragma once

#include "../Pizza.h"
#include "../PizzaStore.h"

class NYPizzaStore : public PizzaStore {
    protected:
        // The Factory Method
        Pizza* CreatePizza(PizzaType type);
};