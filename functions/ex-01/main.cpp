#include <iostream>
#include <array>

using namespace std;

// g++ --std=c++11 ./ex1.cpp -o ./ex1 && ./ex1

int boo() {
    return 0;
}

int main() {

    int (*booPtr)() = boo;
    cout << (*booPtr)() << endl;
    // same by implicit dereference
    cout << booPtr() << endl;

    return 0;
}
