#include <iostream>
#include <array>

using namespace std;

// g++ --std=c++11 ./std-array-vector.cpp -o ./std-array-vector && ./std-array-vector

void printArraySize(const array<int, 4> &arr) {
    cout << arr.size() << endl;
}

void printArray(const array<int, 4> &arr) {
    for (const int &el : arr) {
        cout << el << ' ' << endl;
    }
}

int main() {

    const array<int, 4> myArray = {10, 20, 30, 40};
    printArraySize(myArray);
    printArray(myArray);

    return 0;
}
