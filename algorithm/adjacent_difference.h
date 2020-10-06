#pragma once

#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

namespace algorithm
{
    void adjacent_difference_example()
    {
        auto print = [](auto r)
        {
            for (auto n : r)
                std::cout << n << ' ';
        };

        // 1
        std::vector v{1,2,3,4,5,6,7,8,9,10};
        std::vector<size_t> r(v.size());
        std::adjacent_difference(v.begin(), v.end(), r.begin());
        std::cout << "adjacent_difference: ";
        print(r);

        // 2
        auto fun_add = [](auto& a1, auto& a3)
        {
            return (a1 * a3);
        };
        std::adjacent_difference(v.begin(), v.end(), r.begin(), fun_add);
        std::cout << "adjacent_differtence_fun:";
        print(r);
    }
} // namespace algorithm