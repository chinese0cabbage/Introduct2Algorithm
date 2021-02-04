//
// Created by johnjun on 2020/11/23.
//

#ifndef INTRODUCT2ALGORITHM_MATRIX_H
#define INTRODUCT2ALGORITHM_MATRIX_H

#include "iostream"
#include "Vec.h"

template<typename Ty>
class Matrix {
private:
    std::vector<Vec<Ty>> _vecs;
    Ty *_localArr;
    int _row, _col;
public:
    explicit Matrix(Ty *originArray, int row, int col){
        _row=row;
        _col=col;
        _localArr=originArray;
        for (int i = 0; i < _row; ++i) {
            _vecs.push_back(Vec<Ty>(_localArr+i*_col,_localArr+(i+1)*_col));
        }
    }

    explicit Matrix(std::vector<Ty> &v, int row, int col){
        Matrix(v.data(),row,col);
    }

    inline const Vec<Ty> &operator[](int i) const {
        return _vecs.at(i);
    }

    inline Vec<Ty> col_vec(int i) {
        Ty *arr = (Ty *) malloc(sizeof(Ty) * _col);
        for (int j = 0; j < _col; ++j) {
            arr[j] = _vecs.at(i)[j];
        }
        return Vec<Ty>(arr, arr + _col, COL_VEC);
    }

    inline const int row() const { return _row; }

    inline const int col() const { return _col; }

    friend std::ostream &operator<<(std::ostream &os, Matrix &matrix) {
        for (int i = 0; i < matrix._row; ++i) {
            for (int j = 0; j < matrix._row; ++j) {
                os << matrix._vecs.at(i)[j] << '\t';
            }
            os << '\n';
        }
        return os;
    }
};


#endif //INTRODUCT2ALGORITHM_MATRIX_H
