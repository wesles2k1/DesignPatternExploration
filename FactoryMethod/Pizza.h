// The Abstract Product

#pragma once

#include <string>

// Base Class
class Pizza {
    public:
        void Prepare();
        void Bake();
        void Cut();
        void Box();
    
    protected:
        std::string pizzaName{""};
};

// The Concrete Products

// NY Styles
class NYCheesePizza : public Pizza {
    public:
        NYCheesePizza() {
            pizzaName = "NY Cheese Pizza";
        }
};
class NYVeggiePizza : public Pizza {
    public:
        NYVeggiePizza() {
            pizzaName = "NY Veggie Pizza";
        }
};
class NYClamPizza : public Pizza {
    public:
        NYClamPizza() {
            pizzaName = "NY Clam Pizza";
        }
};
class NYPepperoniPizza : public Pizza {
    public:
        NYPepperoniPizza() {
            pizzaName = "NY Pepperoni Pizza";
        }
};

// Chicago Styles
class ChicagoCheesePizza : public Pizza {
    public:
        ChicagoCheesePizza() {
            pizzaName = "Chicago Cheese Pizza";
        }
};
class ChicagoVeggiePizza : public Pizza {
    public:
        ChicagoVeggiePizza() {
            pizzaName = "Chicago Veggie Pizza";
        }
};
class ChicagoClamPizza : public Pizza {
    public:
        ChicagoClamPizza() {
            pizzaName = "Chicago Clam Pizza";
        }
};
class ChicagoPepperoniPizza : public Pizza {
    public:
        ChicagoPepperoniPizza() {
            pizzaName = "Chicago Pepperoni Pizza";
        }
};