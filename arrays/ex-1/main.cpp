#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

int** allocate2dArray(size_t rows, size_t cols) {
    int **arr = new int *[rows];
    for (int row = 0; row < rows; ++row) {
        arr[row] = new int[cols];
    }
    return arr;
}

void fill2dArray(int **arr, size_t rows, size_t cols) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            arr[row][col] = rand() % 99;
        }
    }
}

void unallocate2dArray(int **arr, size_t rows) {
    for (int row = 0; row < rows; ++row) {
        delete[] arr[row];
    }
    delete[] arr;
}

int main() {

    srand(time(NULL));

    size_t rows = 5;
    size_t cols = 5;

    int **arr = allocate2dArray(rows, cols);
    fill2dArray(arr, rows, cols);

    for (int row = 0; row < rows; ++row) {
        string colStr = "";
        for (int col = 0; col < cols; ++col) {
            colStr += to_string(arr[row][col]) + " ";
        }
        cout << colStr << endl;
    }

    unallocate2dArray(arr, rows);

    return 0;
}
