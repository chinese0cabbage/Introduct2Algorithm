//
// Created by zhangjun on 21-2-4.
//

#ifndef SPARROWZJLOCALTRYAPI_STD_ALGORITHM_TEST_H

#include "algorithm"
#include "iostream"
#include "vector"

#define SPARROWZJLOCALTRYAPI_STD_ALGORITHM_TEST_H

/**
 * std::move函数不会改变原来变量的地址，但是原来变量不指向原来的值了，新的变量指向原来的值
 */
void std_move_test() {
    std::string a = "10", b = "20";
    std::cout << "original a:" << a << " pointer:" << &a;
    std::string tmp = std::move(a);
    std::cout << "\na:" << a << " pointer:" << &a
              << "\nb:" << b << " pointer:" << &b
              << "\ntmp:" << tmp << " pointer:" << &tmp;
}

/**
 * std::remove函数只会将符合要求的n个元素移动(使用的是std::move函数)到容器的末尾，并使用删除前容器中的后n个元素覆盖移动到末尾的n个元素，返回后n个元素的第一个元素的迭代器
 */
void std_remove_test() {
    std::vector<int> v{10, 20, 30, 10, 200, 30, 10, 10, 50};
    v.erase(std::remove(v.begin(), v.end(), 10), v.end());
    std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << "\n"; });
}

void std_copy_test() {

}

/**
 * std::all_of函数会遍历容器中的所有元素，判断元素中是否所有元素都满足其后lambda表达式的条件，都满足则返回True，否则返回false
 * std::none_of函数与all_of函数类似，但是会在所有元素都不满足条件时返回True
 * std::any_of函数会遍历容器，查找是否有一个元素满足条件，有就返回True，否则返回false
 */
void std_all_of_test() {
    std::vector<int> v{10, 20, 30, 40, 50};
    std::cout << std::all_of(v.begin(), v.end(), [](int i) { return i % 10 == 0; });
}

#endif //SPARROWZJLOCALTRYAPI_STD_ALGORITHM_TEST_H
