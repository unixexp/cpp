#include <iostream>
#include <random>

using namespace std;

int getRandomNumber(int min, int max) {
    random_device rDevice;
    mt19937 mersenne(rDevice());
    return static_cast<int>(mersenne() * (max - min + 1) + min);
}

int main() {

    random_device rDevice;
    mt19937 mersenne(rDevice());

    for (int i = 0; i < 48; ++i) {
        cout << getRandomNumber(1, 10) << "\t";
        if ((i + 1) % 5 == 0)
            cout << "\n";
    }

    return 0;
}
