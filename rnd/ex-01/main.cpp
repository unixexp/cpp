#include <iostream>
#include <random>

using namespace std;

int getRandomNumberByRnd(int min, int max) {
    return min + ( rand() % ( max - min + 1 ) );
}

int getRandomNumberByMersenne(int min, int max) {
    random_device rDevice;
    mt19937 mersenne(rDevice());
    uniform_int_distribution<int> distr(min, max);
    return distr(mersenne);
}

int main() {

    srand(time(0));

    random_device rDevice;
    mt19937 mersenne(rDevice());

    for (int j = 0; j < 2; ++j) {

        j == 0 ? cout << "Mersene algo" : cout << "Rnd algo";
        cout << "\n";

        for (int i = 0; i < 25; ++i) {
            if (j == 0) {
                cout << getRandomNumberByMersenne(5, 25) << "\t";
            } else {
                cout << getRandomNumberByRnd(5, 25) << "\t";
            }

            if ((i + 1) % 5 == 0)
                cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}
