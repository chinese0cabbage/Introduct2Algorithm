//
// Created by zhangjun on 21-6-15.
//

#ifndef INTRODUCT2ALGORITHM_HEAP_H

#include "debug/debug.h"
#include "bits/predefined_ops.h"
#include "bits/stl_iterator_base_funcs.h"

#define INTRODUCT2ALGORITHM_HEAP_H

#ifndef DEBUG_MODE
#define DEBUG_MODE
#endif

namespace I2A {
    /**
     * the core predicating method whether a range is heap or not
     * @tparam _RandomAccessIterator
     * @tparam _Distance
     * @tparam _Compare
     * @param __begin
     * @param __len
     * @param __comp
     * @return
     */
    template<typename _RandomAccessIterator, typename _Distance, typename _Compare>
    _Distance __is_heap_until(_RandomAccessIterator __begin, _Distance __len, _Compare __comp) {
        _Distance __parent = 0;
        for (_Distance __child = 1; __child < __len; ++__child) {
            //判断父子节点位置是否正确
            if (__comp(__begin + __parent, __begin + __child)) {
                return __child;
            }
            //判断当前的子节点是否是当前父节点的第二个子节点，等效于__chile % 2 == 0
            if (__child & 1 == 0) {
                __parent++;
            }
        }
    }

    /**
     * the core method to input an element to a heap
     * adjust element between __endIndex and __root,making the range meet the specification of heap
     * @tparam _RandomAccessIterator
     * @tparam _Distance
     * @tparam _Tp
     * @tparam _Compare
     * @param __first
     * @param __root
     * @param __value
     * @param __compare
     */
    template<typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare>
    void __push_heap(_RandomAccessIterator __first, _Distance __root, _Distance __endIndex, _Tp __value,
                     _Compare __compare) {
        for (_Distance __parent = (__endIndex - 1) / 2;
             __parent > __root && !__compare(__first + __parent, __endIndex);
             __endIndex = __parent, __parent = (__endIndex - 1) / 2) {
            *(__first + __parent) = std::move(*(__first + __endIndex));
        }
        *(__first + __root) = std::move(__value);
    }

    template<typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare>
    void __adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex, _Distance __len, _Tp __value, _Compare __comp) {
        const _Distance __topIndex = __holeIndex;
        _Distance __secondChild = __holeIndex;
        while (__secondChild < (__len - 1) / 2) {
            __secondChild = 2 * (__secondChild + 1);
            if (__comp(__first + __secondChild, __first + (__secondChild - 1)))
                __secondChild--;
            *(__first + __holeIndex) = _GLIBCXX_MOVE(*(__first + __secondChild));
            __holeIndex = __secondChild;
        }
        if ((__len & 1) == 0 && __secondChild == (__len - 2) / 2) {
            __secondChild = 2 * (__secondChild + 1);
            *(__first + __holeIndex) = _GLIBCXX_MOVE(*(__first + (__secondChild - 1)));
            __holeIndex = __secondChild - 1;
        }
        std::__push_heap(__first, __holeIndex, __topIndex, _GLIBCXX_MOVE(__value),
                         __gnu_cxx::__ops::__iter_comp_val(__comp));
    }
}

//函数定义参数列表加入只申明变量类型而不给形参的类型名，这样可以对重载但函数前半部分传参一样的函数进行区分

#endif //INTRODUCT2ALGORITHM_HEAP_H
