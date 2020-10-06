#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <forward_list>

namespace algorithm
{
    void binary_search_example()
    {
        std::vector vec{1, 4, 23, 6, 98, 34, 6, 657, 90, 34, 68, 43, 689};
        std::sort(vec.begin(), vec.end());

        std::cout << "binary_search: ";
        std::for_each(vec.begin(), vec.end(), [](auto i) {
            std::cout << i << " ,";
        });
        std::cout << std::endl;

        for (auto i : std::forward_list{1, 23, 9, 90, 689})
        {
            std::cout << i << " == " << std::binary_search(vec.begin(), vec.end(), i) << ", ";
        }
    }
} // namespace algorithm