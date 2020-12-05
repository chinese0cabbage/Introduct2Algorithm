#include <iostream>
#include "fundamentalType/Matrix.h"

int main() {//https://zhuanlan.zhihu.com/p/91062516
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Matrix<double> matrix(arr, 5, 4);
    std::cout << matrix;
    return 0;
}
