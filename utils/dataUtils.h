//
// Created by cobot on 20-12-5.
//

#ifndef INTRODUCT2ALGORITHM_DATAUTILS_H
#define INTRODUCT2ALGORITHM_DATAUTILS_H

template <typename T>
void __interChange(T &a, T &b){
    T tmp=a;
    a=std::move(b);
    b=std::move(tmp);
}

template <typename T>
void __interChange(T *a, T *b){
    T tmp=*a;
    *a=*b;
    *b=tmp;
}

#endif //INTRODUCT2ALGORITHM_DATAUTILS_H
