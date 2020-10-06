#pragma once

#include <numeric>
#include <vector>
#include <iostream>

namespace algorithm
{
    void accumulator_example()
    {
        // 1
        std::vector<int> vec{1,2,3,4,5,6,7,8,9,1};
        auto result = std::accumulate(vec.begin(), vec.end(), 0);
        std::cout << "accumulator: " << result << std::endl;

        // 2
        auto fun_add = [](auto& add1, auto& add2)
        {
            return (add1 * add2);
        };
        
        result = std::accumulate(vec.begin(), vec.end(), 1, fun_add);
        std::cout << "accumulator with fun:" << result << std::endl;
    }
}