//
// Created by johnjun on 2020/11/22.
//

#ifndef INTRODUCT2ALGORITHM_MAXSUNARRAY_H
#define INTRODUCT2ALGORITHM_MAXSUNARRAY_H

#include "vector"

//all caculation include begin and end index
class MaxSunArray {
public:
    MaxSunArray(const std::vector<double> &localArr);

    std::pair<int, int> FindMaxSunArray();

private:
    std::vector<double> _localArr;

    std::pair<std::pair<int, int>, double> FindMaxSunArray(int begin, int end);

    std::pair<std::pair<int, int>, double> FindMaxSunArrayCrossMid(int begin, int end);
};


#endif //INTRODUCT2ALGORITHM_MAXSUNARRAY_H
