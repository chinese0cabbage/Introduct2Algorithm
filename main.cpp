#include <iostream>
#include "fundamentalType/Matrix.h"
#include "utils/sort.h"

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Matrix<double> matrix(arr, 5, 4);
    std::cout << matrix;
    sort::mergeSort<double >(arr,16);
    return 0;
}
