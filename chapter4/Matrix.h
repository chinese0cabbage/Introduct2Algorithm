//
// Created by johnjun on 2020/11/23.
//

#ifndef INTRODUCT2ALGORITHM_MATRIX_H
#define INTRODUCT2ALGORITHM_MATRIX_H

#include "iostream"
#include "Vec.h"

template<typename T>
class Matrix {
private:
    std::vector<Vec<T>> _vecs;
    T *_localArr, *head, *tail;
    int _row,_col;
public:
    Matrix(T *originArray, int row, int col);

    Matrix(std::vector<T> v, int row, int col);

    void show();
};


#endif //INTRODUCT2ALGORITHM_MATRIX_H
