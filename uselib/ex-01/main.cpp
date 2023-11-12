#include <iostream>
#include "SmartLibrary/include/SmartContainer.hpp"

int main() {

    SmartContainer<int> smartContainer(10);

    for (int i = 0; i < smartContainer.getLength(); ++i) {
        smartContainer[i] = (i + 10);
        std::cout << smartContainer[i] << " ";
    }

    return 0;
}
