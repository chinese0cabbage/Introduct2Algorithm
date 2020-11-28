#include <iostream>
#include "chapter4/Matrix.h"

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Vec<double> vec(arr,arr+5);
    std::cout<<vec<<std::endl;
    Vec<double> vec1(arr+5,arr+10);
    std::cout << vec1 << std::endl;
    auto v=vec+vec1;
    std::cout << v;
    return 0;
}
