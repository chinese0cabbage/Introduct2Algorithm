//
// Created by johnjun on 2020/11/23.
//

#ifndef INTRODUCT2ALGORITHM_MATRIX_H

#include "iostream"
#include "Vec.h"

#define INTRODUCT2ALGORITHM_MATRIX_H

static int count;
template<typename Ty>
class Matrix {
private:
    std::vector<Vec<Ty>> _vecs;
    Ty *_localArr;
    int _row, _col;

    void Multiply(const Matrix<Ty> &left, const Matrix<Ty> &right,
                  int left_row_start, int left_row_end, int left_col_start, int left_col_end,
                  Matrix<Ty> &des);

public:
    explicit Matrix(Ty *originArray, int row, int col) {
        _row = row;
        _col = col;
        _localArr = originArray;
        for (int i = 0; i < _row; ++i) {
            _vecs.push_back(Vec<Ty>(_localArr + i * _col, _localArr + (i + 1) * _col));
        }
    }

    explicit Matrix(std::vector<Ty> &v, int row, int col) {
        Matrix(v.data(), row, col);
    }

    inline const Vec<Ty> &operator[](int i) const {
        return _vecs.at(i);
    }

    const Matrix<Ty> operator*(Matrix<Ty> &other) const;

    inline Vec<Ty> col_vec(int i) {
        Ty *arr = (Ty *) malloc(sizeof(Ty) * _col);
        for (int j = 0; j < _col; ++j) {
            arr[j] = _vecs.at(i)[j];
        }
        return Vec<Ty>(arr, arr + _col, COL_VEC);
    }

    inline int row() const { return _row; }

    inline int col() const { return _col; }

    inline

    friend std::ostream &operator<<(std::ostream &os, Matrix &matrix) {
        for (int i = 0; i < matrix._row; ++i) {
            for (int j = 0; j < matrix._row; ++j) {
                os << matrix._vecs.at(i)[j] << '\t';
            }
            os << '\n';
        }
    }
};


#endif //INTRODUCT2ALGORITHM_MATRIX_H
