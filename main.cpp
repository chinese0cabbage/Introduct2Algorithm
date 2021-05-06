#include <iostream>
#include "fundamentalType/Matrix.h"
#include "utils/sort.h"

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//    Matrix<double> matrix(arr, 5, 4);
//    std::cout << matrix;
    std::vector<double> v(arr,arr+16);
    sort::insertSort(arr,arr+16,__gnu_cxx::__ops::__iter_less_iter());
    std::for_each(arr, arr + 16, [=](double i) { std::cout << i << "\t"; });
    return 0;
}
