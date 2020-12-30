//
// Created by cobot on 20-12-5.
//

#ifndef INTRODUCT2ALGORITHM_SORT_H

#include "dataUtils.h"
#include "mutex"
#include "thread"

#define INTRODUCT2ALGORITHM_SORT_H

class sort{
public:
    template <typename T>
    static void mergeSort(T *arr, int len){
        mergeSort(arr,arr+len);
    }

private:
    template <typename T>
    static void mergeSort(T *begin, T *end){
        switch (end-begin) {
            case 0:
                return;
            case 1:
                return;
            case 2:
                interChange(begin,begin+1);
                return;
            default:
                int mid=(end-begin)/2;
                std::thread t1(mergeSort,begin,begin+mid);
                std::thread t2(mergeSort,begin+mid,end);
                t1.join();
                t2.join();
                //不借助T(n)的空间复杂度实现两个有序数组的合并
        }
    }
};

#endif //INTRODUCT2ALGORITHM_SORT_H
