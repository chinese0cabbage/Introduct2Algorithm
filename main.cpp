#include <iostream>
#include <valarray>
#include "fundamentalType/Matrix.h"
#include "utils/heap_core.h"
#include "vector"
#include "stdlib.h"
#include "array"
#include "iterator"

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
//    I2A::__adjust_heap(v.begin(),0,10,13,__gnu_cxx::__ops::__iter_less_iter());
    I2A::__make_heap(v.begin(), v.end(), __gnu_cxx::__ops::__iter_less_iter());
//    std::for_each(v.begin(), v.end(), [=](double i) { std::cout << i << "\t"; });
//    std::cout << "\n";
//    std::__adjust_heap(v.begin(),0,16,21,__gnu_cxx::__ops::__iter_less_iter());
//    int i=0;
//    while (i++<16) {
//        std::__pop_heap(v.begin(), v.end()-i, v.end()-i, __gnu_cxx::__ops::__iter_less_iter());
//        std::for_each(v.begin(), v.end(), [=](double i) { std::cout << i << "\t"; });
//        std::cout << "\n";
//    }
//    std::__adjust_heap(v.begin(), 0, 16, 20, __gnu_cxx::__ops::__iter_less_iter());
    std::cout << "\n";
    std::for_each(v.begin(), v.end(), [=](double i) { std::cout << i << "\t"; });
    return 0;
}
