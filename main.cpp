#include <iostream>
#include <valarray>
#include "fundamentalType/Matrix.h"
#include "utils/heap_core.h"
#include "vector"
#include "stdlib.h"
#include "array"
#include "iterator"
#include "set"
#include "hashtable.h"

#define SIZE 100000

void sortVarietyCompare() {
    std::array<int, SIZE> arr;
    for (int i = 0; i < SIZE; ++i) {
        srand(time(0));
        arr.at(i) = rand() % SIZE;
    }
    clock_t t_begin, t_end;
    t_begin = clock();
    //函数段
    t_end = clock();
    //计算时长=t_end-t_begin
}

bool compare(double a, double b) {
    return b > a;
}

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    std::vector<double> v(arr, arr + 16);
    std::cout << "\n";
    v.reserve(5);
    std::for_each(v.begin(), v.end(), [=](double i) { std::cout << i << "\t"; });
    return 0;
}
