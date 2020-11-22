#include <iostream>
#include "chapter4/MaxSunArray.h"

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    std::vector<double> v(arr, arr + 16);
    MaxSunArray m(v);
    auto result = m.FindMaxSunArray();
    std::cout << result.first << '\t' << result.second;
    return 0;
}
