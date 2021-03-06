//
// Created by johnjun on 2020/11/25.
//

#ifndef INTRODUCT2ALGORITHM_VEC_H

#include <vector>
#include "iostream"
#include "malloc.h"
#include "assert.h"
#include "math.h"

#define INTRODUCT2ALGORITHM_VEC_H

#define OPERATE_MEMORY

enum characteristic {
    ROW_VEC,
    COL_VEC
};

template<typename Ty>
class Vec {
private:
    Ty *_localArr;
    int _len;
    characteristic _chart = ROW_VEC;

#ifdef OPERATE_MEMORY
    Ty *_begin, *_end;
#endif
public:
    Vec(Ty *localArr, int len, characteristic chart = ROW_VEC) : _localArr(localArr), _len(len),
                                                                 _chart(chart) {}

    Vec(const std::vector<Ty> &v, characteristic chart = ROW_VEC) : _localArr(v.data()), _len(v.size()),
                                                                    _chart(chart) {}

    Vec(const Ty *localArr, int begin, int end, characteristic chart = ROW_VEC) {
        _len = end - begin;
        _localArr = (Ty *) malloc(sizeof(Ty) * _len);
        _chart = chart;
        for (int i = begin; i < end; ++i)
            _localArr[i - begin] = localArr[i];
    }

    Vec(const Vec<Ty> &v, characteristic chart = ROW_VEC) : _localArr(v._localArr), _len(v._len),
                                                            _chart(chart) {}

#ifdef OPERATE_MEMORY

    explicit Vec(Ty *begin, Ty *end) {
        _begin = begin;
        _end = end;
        _len = end - begin;
        _localArr = _begin;
    }

#endif

    inline const int len() const { return _len; };

    inline const Ty *arrayPointor() const { return _localArr; };

    const Vec<Ty> operator+(const Vec<Ty> &v) {
        assert(v.len() == _len);
        Ty *result = (Ty *) malloc(sizeof(Ty) * _len);
        auto source = v.arrayPointor();
        for (int i = 0; i < _len; ++i) {
            result[i] = source[i] + _localArr[i];
        }
        return Vec<Ty>(result, _len);
    }

    const void operator+=(const Vec<Ty> &v) {
        for (int i = 0; i < _len; ++i) {
            _localArr[i] += v._localArr[i];
        }
    }

    const Vec<Ty> operator*(double times) {
        auto result = (Ty *) malloc(sizeof(Ty) * _len);
        for (int i = 0; i < _len; ++i) {
            result[i] = _localArr[i] * times;
        }
        return Vec<Ty>(result, _len);
    }

    const void operator*=(double times) {
        for (int i = 0; i < _len; ++i) {
            _localArr[i] *= times;
        }
    }

    const Vec<Ty> operator-(const Vec<Ty> &v) {
        return this + v * (-1);
    }

    const void operator-=(const Vec<Ty> &v) {
        for (int i = 0; i < _len; ++i) {
            _localArr[i] -= v._localArr[i];
        }
    }

    const Vec<Ty> operator/(double times) {
        assert(times != 0);
        return this * (1 / times);
    }

    const void operator/=(double times) {
        assert(times != 0);
        for (int i = 0; i < _len; ++i) {
            _localArr[i] /= times;
        }
    }

    inline void T() {
        if (_chart == ROW_VEC)
            _chart = COL_VEC;
        else
            _chart = ROW_VEC;
    }

    inline const Ty operator[](int index) const {
        return _localArr[index];
    }

    const Ty dot(Vec<Ty> &v) const {
        assert(_len == v._len);
        Ty total = 0;
        for (int i = 0; i < _len; ++i) {
            total += _localArr[i] * v._localArr[i];
        }
        return total;
    }

    inline const Ty product(const Vec<Ty> &v) {
        assert(_chart == v._chart && _len == v._len);
        return this->dot(v);
    }

    inline const characteristic Type() const {
        return _chart;
    }

    const double length() const {
        double total = 0;
        for (int i = 0; i < _len; ++i) {
            total += pow(_localArr[i], 2);
        }
        return sqrt(total);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vec &vec) {
        for (int i = 0; i < vec._len; ++i) {
            os << vec._localArr[i] << '\t';
        }
        return os;
    }
};


#endif //INTRODUCT2ALGORITHM_VEC_H
