#pragma once

#include <algorithm>
#include <vector>

namespace algorithm
{
	void any_of_example()
	{
		// 1
		std::vector vec{ 1,2,3,4,5,6,7,8,9 };
		auto result = std::any_of(vec.begin(), vec.end(), [](auto& i) {
			return (i % 2 == 0);
			});
		std::cout << "any_of: " << result << std::endl;
	}
}