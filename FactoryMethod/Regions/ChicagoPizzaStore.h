// Concrete Creator

#pragma once

#include "../Pizza.h"
#include "../PizzaStore.h"
#include "../PizzaType.h"

class ChicagoPizzaStore : public PizzaStore {
    protected:
        // The Factory Method
        Pizza CreatePizza(PizzaType type);
};