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

    enum SortVariety {
        MERGE,
        SELECTION,
        INSERT,
        SHELL
    };

    template<typename _RandomAccessIterator, typename _Compare>
    inline void mergeSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                          _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
#define __type typename std::iterator_traits<_RandomAccessIterator>::value_type
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept < _RandomAccessIterator >)
        __glibcxx_function_requires(_LessThanComparableConcept < __type >)
        __glibcxx_requires_valid_range(__first, __last)
        int len = __last - __first;
        if (len == 0 || len == 1) return;
        if (len == 2) {
            if (!__compare(__first, __first + 1))
                interChange(__first, __first + 1);
            return;
        }
#ifdef DEBUG_MODE
        debugFun(__first, __last);
#endif
        _RandomAccessIterator __aux(__first);
        for (; __first != __last; __aux++, __first++) {
            _RandomAccessIterator __aux(__first);
        }
        __aux -= len;
        __first -= len;
        mergeSort(__aux, __aux + len / 2, __compare);
#ifdef DEBUG_MODE
        debugFun(__aux, __aux + len / 2);
#endif
        mergeSort(__aux + len / 2, __aux + len, __compare);
#ifdef DEBUG_MODE
        debugFun(__aux + len / 2, __aux + len);
#endif
        std::__merge(__aux, __aux + len / 2, __aux + len / 2, __aux + len, __first, __compare);
    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void selectionSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                              _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        //检查迭代器是否可以随机访问
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept <
                                    _RandomAccessIterator >)
        //检查迭代器是否可以进行比较
        __glibcxx_function_requires(_LessThanComparableConcept <
                                    typename std::iterator_traits<_RandomAccessIterator>::value_type >)
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
    inline void insertSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                           _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        //检查迭代器是否可以随机访问
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept <
                                    _RandomAccessIterator >)
        //检查迭代器是否可以进行比较
        __glibcxx_function_requires(_LessThanComparableConcept <
                                    typename std::iterator_traits<_RandomAccessIterator>::value_type >)
        //检查迭代器范围是否合理
        __glibcxx_requires_valid_range(__first, __last);
        if (__first == __last) return;

        for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i) {
#ifdef DEBUG_MODE
            debugFun(__first, __last);
#endif
            if (__compare(__i, __first)) { //前面已排序元素集体后挪
                typename std::iterator_traits<_RandomAccessIterator>::value_type __val = std::move(*__i);
                std::move_backward(__first, __i, __i + 1);
                *__first = std::move(__val);
            } else { //向前遍历寻找合适的位置插入
                std::__unguarded_linear_insert(__i, __gnu_cxx::__ops::__val_comp_iter(__compare));
            }
        }
    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void shellSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                          _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept < _RandomAccessIterator >)
        __glibcxx_function_requires(
                _LessThanComparableConcept < typename std::iterator_traits<_RandomAccessIterator>::value_type >)
        __glibcxx_requires_valid_range(__first, __last)
        int len = __last - __first, h = 1;
        while (h < len / 3) h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h; i < len; ++i) {
#ifdef DEBUG_MODE
                debugFun(__first, __last);
#endif
                for (int j = i; j >= h; j -= h) {
                    if (__compare(__first + j, __first + j - h))
                        interChange(*(__first + j), *(__first + j - h));
                }
            }
            h /= 3;
        }
    }
}

#endif //INTRODUCT2ALGORITHM_SORT_H
