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
#ifdef OPERATE_MEMORY
    T *_begin,*_end;
#endif
public:
    Vec(T *localArr, int len) : _localArr(localArr), _len(len) {}

    Vec(const std::vector<T> &v) : _localArr(v.data()), _len(v.size()) {}

    Vec(const T *localArr, int begin, int end) {
        _len = end - begin;
        _localArr = new T(_len);
        for (int i = begin; i < end; ++i)
            _localArr[i - begin] = localArr[i];
    }
#ifdef OPERATE_MEMORY
    Vec(T *begin, T *end):_begin(begin),_end(end),_len((end-begin)/sizeof(T)){}
#endif

    friend std::ostream &operator << (std::ostream &os,const Vec &vec) {
        for (int i = 0; i < vec._len; ++i) {
            os<<vec._localArr[i]<<'\t';
        }
        return os;
    }
};


#endif //INTRODUCT2ALGORITHM_VEC_H
