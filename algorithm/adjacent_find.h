#pragma once

#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

namespace algorithm
{
	void adjacent_find_example()
	{
		// 1
		std::vector vec{ 1,2,3,4,4,5,6,7,8,8,10,10 };
		auto ret = std::adjacent_find(vec.begin(), vec.end());
		std::cout << "\nadjacent_find:" << *ret << std::endl;

		// 2
		ret = std::adjacent_find(vec.begin(), vec.end(), std::greater<int>());
		std::cout << "adjacent_find_fun: " << std::distance(vec.begin(),ret) << std::endl;
	}
}