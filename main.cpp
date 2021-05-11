#include <iostream>
#include <valarray>
#include "fundamentalType/Matrix.h"
#include "utils/sort.h"
#include "vector"
#include "stdlib.h"
#include "array"

#define SIZE 100000

void sortVarietyCompare(){
    std::array<int,SIZE> arr;
    for (int i = 0; i < SIZE; ++i) {
        srand(time(0));
        arr.at(i)=rand()%SIZE;
    }
    clock_t t_begin,t_end;
    t_begin=clock();
    //函数段
    t_end=clock();
    //计算时长=t_end-t_begin
}

bool compare(double a, double b){
    return b>a;
}

int main() {
    double arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//    Matrix<double> matrix(arr, 5, 4);
//    std::cout << matrix;
    std::vector<double> v(arr,arr+16);
//    std::__make_heap(v.begin(),v.end(),__gnu_cxx::__ops::__iter_comp_iter(compare));
    sort::selectionSort(v.begin(),v.end(),__gnu_cxx::__ops::__iter_comp_iter(compare));
//    sort::__unguarded_partition(v.begin(),v.begin()+2,__gnu_cxx::__ops::__iter_comp_iter(compare));
//    __interChange(v.begin().operator*(),(v.end()-1).operator*());
    std::for_each(v.begin(),v.end(), [=](double i) { std::cout << i << "\t"; });
    return 0;
}
