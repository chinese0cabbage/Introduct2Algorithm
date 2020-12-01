//
// Created by johnjun on 2020/11/23.
//

#include "Matrix.h"

template<typename Ty>
Matrix<Ty>::Matrix(Ty *originArray, int row, int col) {
    _row=row;
    _col=col;
    _localArr=originArray;
    for (int i = 0; i < _row; ++i) {
        _vecs.push_back(Vec<Ty>(_localArr+i*_col,_localArr+(i+1)*_col));
    }
}

template<typename Ty>
Matrix<Ty>::Matrix(std::vector<Ty> &v, int row, int col) {
    Matrix(v.data(),row,col);
}
