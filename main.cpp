#include <iostream>
#include "fundamentalType/Matrix.h"
#include "utils/sort.h"

bool compare(double a, double b){
    return b>a;
}

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//    Matrix<double> matrix(arr, 5, 4);
//    std::cout << matrix;
    std::vector<double> v(arr,arr+16);
    sort::mergeSort(arr,arr+16,__gnu_cxx::__ops::__iter_comp_iter(compare));
    std::for_each(arr, arr + 16, [=](double i) { std::cout << i << "\t"; });
    return 0;
}
