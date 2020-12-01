#include <iostream>
#include "chapter4/Matrix.cpp"

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Matrix<double> matrix(arr, 4, 4);
    std::cout << matrix;
    return 0;
}
