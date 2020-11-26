//
// Created by johnjun on 2020/11/25.
//

#ifndef INTRODUCT2ALGORITHM_VEC_H
#define INTRODUCT2ALGORITHM_VEC_H

#include <vector>
#include "iostream"

template<typename T>
class Vec {
private:
    T *_localArr;
    int _len;
public:
    Vec(T *localArr, int len) : _localArr(localArr), _len(len) {}

    Vec(const std::vector<T> &v) : _localArr(v.data()), _len(v.size()) {}

    Vec(const T *localArr, int begin, int end) {
        _len = end - begin;
        T *newArr = new T(_len);
        for (int i = begin; i < end; ++i)
            newArr[i - begin] = localArr[i];
        _localArr = newArr;
    }

    void show(){
        for (int i = 0; i < _len; ++i)
            std::cout<<_localArr[i]<<'\t';
    }
};


#endif //INTRODUCT2ALGORITHM_VEC_H
