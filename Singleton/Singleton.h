#include <string>

class Singleton {
    public:
        static Singleton* GetInstance(std::string newValue);
        std::string GetValue();
    protected:
        static Singleton* uniqueInstance;
        Singleton(std::string newValue);
        std::string value;
};