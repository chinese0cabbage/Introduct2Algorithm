//
// Created by zhangjun on 21-6-16.
//

#ifndef INTRODUCT2ALGORITHM_DEBUG_TOOL_H
#define INTRODUCT2ALGORITHM_DEBUG_TOOL_H

namespace I2A {
    template<typename _RandomAccessIterator>
    void __debugFun(_RandomAccessIterator __first, _RandomAccessIterator __last) {
        int exchangeMark = 0;
        while (__first + exchangeMark != __last) {
            std::cout << *(__first + exchangeMark) << "\t";
            exchangeMark++;
        }
        std::cout << "\n";
    }
}

#endif //INTRODUCT2ALGORITHM_DEBUG_TOOL_H
