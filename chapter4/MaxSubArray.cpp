//
// Created by johnjun on 2020/11/22.
//

#include "MaxSubArray.h"

MaxSubArray::MaxSubArray(const std::vector<double> &localArr) : _localArr(localArr) {}

std::pair<int, int> MaxSubArray::FindMaxSubArray() {
    auto result = FindMaxSubArray(0, _localArr.size() - 1);
    return result.first;
}

std::pair<std::pair<int, int>, double> MaxSubArray::FindMaxSubArray(int begin, int end) {
    if (begin == end)
        return std::make_pair(std::make_pair(begin, end), _localArr.at(end));
    int mid = (begin + end) / 2;
    auto front = FindMaxSubArray(begin, mid);
    auto cross = FindMaxSubArrayCrossMid(begin, end);
    auto behand = FindMaxSubArray(mid + 1, end);
    std::pair<std::pair<int, int>, double> result;
    if (front.second > cross.second)
        result = front;
    else
        result = cross;
    if (behand.second > result.second)
        result = behand;
    return result;
}

std::pair<std::pair<int, int>, double> MaxSubArray::FindMaxSubArrayCrossMid(int begin, int end) {
    double total = -3.40282347e+38, cur = 0;
    int mid = (begin + end) / 2, behand = mid, front = mid;
    for (int i = mid; i < end; ++i) {
        cur += _localArr.at(i);
        if (cur > total) {
            total = cur;
            behand = i;
        }
    }
    for (int j = mid - 1; j > 0; --j) {
        cur += _localArr.at(j);
        if (cur > total) {
            total = cur;
            front = j;
        }
    }
    return std::make_pair(std::make_pair(front, behand), total);
}
