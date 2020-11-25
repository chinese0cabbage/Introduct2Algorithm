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
public:
    Matrix(T *originArray, int row, int col);//一个矩阵拆分为多个行向量，每一个行向量都是一个Vec，但其内存相连接的属性不更改，可以连续访问

    Matrix(std::vector<T> v, int row, int col);

    void show();
};


#endif //INTRODUCT2ALGORITHM_MATRIX_H
