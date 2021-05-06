//
// Created by cobot on 20-12-5.
//

#ifndef INTRODUCT2ALGORITHM_SORT_H

#include "dataUtils.h"
#include "mutex"
#include "thread"
#include "algorithm"

#define DEBUG_MODE

#define INTRODUCT2ALGORITHM_SORT_H

namespace sort {
#ifdef DEBUG_MODE

    template<typename _RandomAccessIterator>
    void debugFun(_RandomAccessIterator __first, _RandomAccessIterator __last) {
        int exchangeMark = 0;
        while (__first + exchangeMark != __last) {
            std::cout << *(__first + exchangeMark) << "\t";
            exchangeMark++;
        }
        std::cout << "\n";
    }

#endif

    template<typename _RandomAccessIterator, typename _Compare>
    inline void mergeSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                          _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {

    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void selectionSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                              _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        //检查迭代器是否可以随机访问
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept <
                                    _RandomAccessIterator >)
        //检查迭代器是否可以进行比较
        __glibcxx_function_requires(_LessThanComparableConcept <
                                    typename iterator_traits<_RandomAccessIterator>::value_type >)
        //检查迭代器范围是否合理
        __glibcxx_requires_valid_range(__first, __last);
        int exchangeMark = 0;
        for (;;) {
#ifdef DEBUG_MODE
            debugFun(__first, __last);
#endif
            int searchMark = exchangeMark, goalMark = searchMark;
            while (__first + searchMark != __last) {
                if (__compare(__first + searchMark, __first + goalMark)) {
                    goalMark = searchMark;
                }
                searchMark++;
            };
            if (__first + exchangeMark == __last) return;
            interChange(*(__first + exchangeMark), *(__first + goalMark));
            exchangeMark++;
        };
    }

    template<typename _RandomAccessIterator, typename _Compare>
    void __unguarded_linear_insert(_RandomAccessIterator __last,_Compare __comp)
    {
        typename std::iterator_traits<_RandomAccessIterator>::value_type __val = _GLIBCXX_MOVE(*__last);
        _RandomAccessIterator __next = __last;
        --__next;
        while (__comp(__val, __next))
        {
            *__last = _GLIBCXX_MOVE(*__next);
            __last = __next;
            --__next;
        }
        *__last = _GLIBCXX_MOVE(__val);
    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void insertSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                           _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        //检查迭代器是否可以随机访问
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept <
                                    _RandomAccessIterator >)
        //检查迭代器是否可以进行比较
        __glibcxx_function_requires(_LessThanComparableConcept <
                                    typename iterator_traits<_RandomAccessIterator>::value_type >)
        //检查迭代器范围是否合理
        __glibcxx_requires_valid_range(__first, __last);
        if (__first == __last) return;

        for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i) {
#ifdef DEBUG_MODE
            debugFun(__first, __last);
#endif
            if (__compare(__i, __first)) { //前面已排序元素集体后挪
                typename std::iterator_traits<_RandomAccessIterator>::value_type __val = _GLIBCXX_MOVE(*__i);
                _GLIBCXX_MOVE_BACKWARD3(__first, __i, __i + 1);
                *__first = _GLIBCXX_MOVE(__val);
            } else{ //向前遍历寻找合适的位置插入
                sort::__unguarded_linear_insert(__i,__gnu_cxx::__ops::__val_comp_iter(__compare));
            }
        }
    }
}

#endif //INTRODUCT2ALGORITHM_SORT_H
