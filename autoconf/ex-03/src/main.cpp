#include <iostream>
#include <array>
#include "dollars.h"

using namespace std;

// Operators overloading example

int main() {

    Dollars d1(10);
    Dollars d2(20);
    Dollars dSum = d1 + d2;

    cout << dSum.getDollars() << endl;

    return 0;
}
