#include <iostream>
#include <array>

using namespace std;

// Return by address (pointer) case #1
int* modifyValue(int *value) {
    *value = 100;
    return value;
}

// Return by address (pointer) case #2
int* allocateArray(int size) {
    return new int[size];
}

// Return by ref case #1
int& getArrayElement(array<int, 3> &arr, int index) {
    return arr[index];
}

int main() {

    // Return by address case #1
    cout << "Return by address (pointer) case #1" << endl;
    int someValue = 10;
    cout << someValue << endl;
    int *someValueAddress = modifyValue(&someValue);
    cout << someValueAddress << " => " << someValue << endl;

    // Return by address case #2
    cout << "Return by address (pointer) case #2" << endl;
    size_t arrSize = 5;
    int *arr = allocateArray(arrSize);
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = 50;
        cout << arr[i] << endl;
    }
    delete[] arr;

    // Return by ref case #1
    cout << "Return by ref case #1" << endl;
    array<int, 3> arr2;
    for (int &i : arr2) i = 55;
    for (const int &i : arr2) cout << i << endl;
    cout << "Get link to first element of 'arr2' and change it" << endl;
    int &el = getArrayElement(arr2, 0);
    el = 56;
    for (const int &i : arr2) cout << i << endl;

    return 0;
}
