#pragma once

#include <algorithm>

namespace algorithm
{
	void all_of_example()
	{
		// 1
		std::vector vec{ 2,4,6,8,10,12,14,16,18,20 };
		
		auto ret = std::any_of(vec.begin(), vec.end(), [](auto& a1) {
			return (a1 % 2 == 0);
			});
		std::cout << "all_of: " << ret << std::endl;

		ret = std::any_of(vec.begin(), vec.end(), [](auto& a1) {
			return (a1 % 2 == 1);
			});
		std::cout << "all_of: " << ret << std::endl;
	}
}