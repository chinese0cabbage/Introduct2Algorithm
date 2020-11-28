//
// Created by johnjun on 2020/11/25.
//

#ifndef INTRODUCT2ALGORITHM_VEC_H
#define INTRODUCT2ALGORITHM_VEC_H

#define OPERATE_MEMORY

#include <vector>
#include "iostream"
#include "malloc.h"
#include "assert.h"


template<typename T>
class Vec {
private:
    T *_localArr;
    int _len;
#ifdef OPERATE_MEMORY
    T *_begin, *_end;
#endif
public:
    Vec(T *localArr, int len) : _localArr(localArr), _len(len) {}

    Vec(const std::vector<T> &v) : _localArr(v.data()), _len(v.size()) {}

    Vec(const T *localArr, int begin, int end) {
        _len = end - begin;
        _localArr = (T *) malloc(sizeof(T) * _len);
        for (int i = begin; i < end; ++i)
            _localArr[i - begin] = localArr[i];
    }

    Vec(const Vec<T> &v): _localArr(v._localArr), _len(v._len){}

#ifdef OPERATE_MEMORY

    Vec(T *begin, T *end) {
        _begin = begin;
        _end = end;
        _len = end - begin;
        _localArr = _begin;
    }

#endif

    inline const int len() const{return _len;};

    inline const T* arrayPointor() const{return _localArr;};

    const Vec<T> operator+(Vec<T> &v){
        assert(v.len()==_len);
        T *result=(T *)malloc(sizeof(T)*_len);
        auto source=v.arrayPointor();
        for (int i = 0; i < _len; ++i) {
            result[i]=source[i]+_localArr[i];
        }
        return Vec<T>(result,_len);
    }

    const void operator+=(Vec<T> &v){
        for (int i = 0; i < _len; ++i) {
            _localArr[i]+=v._localArr[i];
        }
    }

    const Vec<T> operator*(double times){
        auto result=(T *)malloc(sizeof(T)*_len);
        for (int i = 0; i < _len; ++i) {
            result[i] = _localArr[i] * times;
        }
        return Vec<T>(result, _len);
    }

    const void operator*=(double times){
        for (int i = 0; i < _len; ++i) {
            _localArr[i]*=times;
        }
    }

    const Vec<T> operator-(Vec<T> &v){
        return this+v*(-1);
    }

    const void operator-=(Vec<T> &v){
        for (int i = 0; i < _len; ++i) {
            _localArr[i]-=v._localArr[i];
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Vec &vec) {
        for (int i = 0; i < vec._len; ++i) {
            os << vec._localArr[i] << '\t';
        }
        return os;
    }
};


#endif //INTRODUCT2ALGORITHM_VEC_H
