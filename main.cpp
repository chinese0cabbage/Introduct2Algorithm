#include <iostream>
#include "chapter4/Matrix.h"

int main() {
    const double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Vec<double> vec(arr,1,2);
    vec.show();
    return 0;
}
