#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

void swapPointers(int *&ptrA, int *&ptrB) {
    int *tmpPtrB = ptrB;
    ptrB = ptrA;
    ptrA = tmpPtrB;
}

int main() {

    int a = 10;
    int b = 20;
    int *ptrA = &a;
    int *ptrB = &b;

    cout << "ptrA => " << ptrA << " => " << *ptrA << endl;
    cout << "ptrB => " << ptrB << " => " << *ptrB << endl;

    swapPointers(ptrA, ptrB);

    cout << "------------- SWAP -------------" << endl;
    cout << "ptrA => " << ptrA << " => " << *ptrA << endl;
    cout << "ptrB => " << ptrB << " => " << *ptrB << endl;

    return 0;
}
