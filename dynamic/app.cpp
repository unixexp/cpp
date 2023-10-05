#include <iostream>
#include <unistd.h>

int main() {

    const int TIMEOUT = 15;
    int seconds = 0;
    int count = 10000000;
    int *foo;

    foo = new int[count];
    int allocatedBytes = count * sizeof(int);

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        foo[i] = rand() % 100;
    }

    std::cout << "Allocated Bytes/MBytes: " + std::to_string(allocatedBytes) + "/"
        + std::to_string(allocatedBytes / 1024 / 1024) << std::endl;

    while (seconds < TIMEOUT) {
        seconds++;
        usleep(1000000);
    }

    std::cout << "Delete pointer" << std::endl;
    delete[] foo;

    while (1) {
        usleep(1000000);
    }

    return 0;
}