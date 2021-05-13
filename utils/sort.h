//
// Created by cobot on 20-12-5.
//

#ifndef INTRODUCT2ALGORITHM_SORT_H

#include "dataUtils.h"
#include "mutex"
#include "thread"
#include "algorithm"
#include "numeric"

#define DEBUG_MODE

#define INTRODUCT2ALGORITHM_SORT_H

namespace sort {
#ifdef DEBUG_MODE

    template<typename _RandomAccessIterator>
    void __debugFun(_RandomAccessIterator __first, _RandomAccessIterator __last) {
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
    void mergeSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                   _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
#define __type typename std::iterator_traits<_RandomAccessIterator>::value_type
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept < _RandomAccessIterator >)
        __glibcxx_function_requires(_LessThanComparableConcept < __type >)
        __glibcxx_requires_valid_range(__first, __last)
        typename std::iterator_traits<_RandomAccessIterator>::difference_type __len = __last - __first;
        if (__len == 0 || __len == 1) return;
        if (__len == 2) {
            if (!__compare(__first, __first + 1))
                __interChange(*__first, *(__first + 1));
            return;
        }
#ifdef DEBUG_MODE
        __debugFun(__first, __last);
#endif
        //采用vector作为辅助空间转存排序的元素，违背了泛型编程的初衷
        //但为了转存迭代器内的元素，重新用内存配置器构造容器并迭代存储是在重复vector内部的工作，因此选择直接调用
        std::vector<__type> __v(__first, __last);
        mergeSort(__v.begin(), __v.begin() + __len / 2, __compare);
#ifdef DEBUG_MODE
        __debugFun(__v.begin(), __v.begin() + __len / 2);
#endif
        mergeSort(__v.begin() + __len / 2, __v.begin() + __len, __compare);
#ifdef DEBUG_MODE
        __debugFun(__v.begin() + __len / 2, __v.begin() + __len);
#endif
        std::__merge(__v.begin(), __v.begin() + __len / 2, __v.begin() + __len / 2, __v.begin() + __len, __first,
                     __compare);
    }

    template<typename _RandomAccessIterator, typename _Compare>
    void selectionSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                       _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        //检查迭代器是否可以随机访问
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept <
                                    _RandomAccessIterator >)
        //检查迭代器是否可以进行比较
        __glibcxx_function_requires(_LessThanComparableConcept <
                                    typename std::iterator_traits<_RandomAccessIterator>::value_type >)
        //检查迭代器范围是否合理
        __glibcxx_requires_valid_range(__first, __last);
#define __type typename std::iterator_traits<_RandomAccessIterator>::difference_type
        __type __exchangeMark = 0;
        for (;;) {
#ifdef DEBUG_MODE
            __debugFun(__first, __last);
#endif
            __type __searchMark = __exchangeMark, goalMark = __searchMark;
            while (__first + __searchMark != __last) {
                if (__compare(__first + __searchMark, __first + goalMark)) {
                    goalMark = __searchMark;
                }
                __searchMark++;
            };
            if (__first + __exchangeMark == __last) return;
            __interChange(*(__first + __exchangeMark), *(__first + goalMark));
            __exchangeMark++;
        }
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
            __debugFun(__first, __last);
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
    void shellSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                   _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept < _RandomAccessIterator >)
        __glibcxx_function_requires(
                _LessThanComparableConcept < typename std::iterator_traits<_RandomAccessIterator>::value_type >)
        __glibcxx_requires_valid_range(__first, __last)
        typename std::iterator_traits<_RandomAccessIterator>::difference_type __len = __last - __first, __h = 1;
        while (__h < __len / 3) __h = 3 * __h + 1;
        while (__h >= 1) {
            for (int i = __h; i < __len; ++i) {
#ifdef DEBUG_MODE
                __debugFun(__first, __last);
#endif
                for (int j = i; j >= __h; j -= __h) {
                    if (__compare(__first + j, __first + j - __h))
                        __interChange(*(__first + j), *(__first + j - __h));
                }
            }
            __h /= 3;
        }
    }

    template<typename _RandomAccessIterator, typename _Compare>
    _RandomAccessIterator
    __unguarded_partition(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __compare) {
        _RandomAccessIterator __forward = __first, __back = __last;
        for (;;) {
            while (__compare(++__forward, __first)) {
                if (__forward == __last) break;
            }
            while (__compare(__first, --__back)) {
                if (__back == __first) break;
            }
            if (__forward >= __back) break;
            __interChange(*__forward, *__back);
        }
        __interChange(*__first, *__back);
        return __back;
    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void quickSort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                          _Compare __compare = __gnu_cxx::__ops::__iter_less_iter()) {
        __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept < _RandomAccessIterator >)
        __glibcxx_function_requires(
                _LessThanComparableConcept < typename std::iterator_traits<_RandomAccessIterator>::value_type >)
        __glibcxx_requires_valid_range(__first, __last)
        if (__last - __first <= 1) return;
#ifdef DEBUG_MODE
        __debugFun(__first, __last);
#endif
        _RandomAccessIterator __mid = sort::__unguarded_partition(__first, __last, __compare);
#ifdef DEBUG_MODE
        __debugFun(__first, __last);
#endif
        quickSort(__first, __mid, __compare);
#ifdef DEBUG_MODE
        __debugFun(__first, __mid);
#endif
        quickSort(__mid + 1, __last, __compare);
#ifdef DEBUG_MODE
        __debugFun(__mid, __last);
#endif
    }
}

namespace misunderstand {
    /**
     * 判断指定范围内的迭代器序列是否是一个最大/小堆
     * @tparam _RandomAccessIterator
     * @tparam _Distance
     * @tparam _Compare
     * @param __first
     * @param __n
     * @param __comp
     * @return
     */
    template<typename _RandomAccessIterator, typename _Distance, typename _Compare>
    _Distance __is_heap_until(_RandomAccessIterator __first, _Distance __n,_Compare __comp) {
        _Distance __parent = 0;
        for (_Distance __child = 1; __child < __n; ++__child) {
            // ++__child：目的是遍历两个孩子节点
            if (__comp(__first + __parent, __first + __child))
                return __child;
            //如果__child是奇数的话则证明当前节点的两个孩子节点都已经检查完成，++__parent继续检查下一个节点的孩子节点是否满足要求
            if ((__child & 1) == 0)
                ++__parent;
        }
        return __n;
    }
}

#endif //INTRODUCT2ALGORITHM_SORT_H
