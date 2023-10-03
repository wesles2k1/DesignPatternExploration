#include <iostream>

#include "Singleton.h"

using namespace std;

int main() {

    cout << Singleton::GetInstance("First Value")->GetValue() << endl;
    cout << Singleton::GetInstance("Second Value")->GetValue() << endl;
    cout << Singleton::GetInstance("First Value")->GetValue() << endl;

    return 0;
}