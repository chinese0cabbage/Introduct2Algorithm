//
// Created by cobot on 20-12-5.
//

#ifndef INTRODUCT2ALGORITHM_SORT_H
#define INTRODUCT2ALGORITHM_SORT_H

class sort{
public:
    template <typename T>
    void MergeSort(T* arr, int len){
        MergeSort(arr,arr+len);
    }

private:
    template <typename T>
    void MergeSort(T *begin,T *end){

    }
};

#endif //INTRODUCT2ALGORITHM_SORT_H
