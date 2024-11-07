#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    const std::vector number = {1,2,3,4,5,6,7,8,9,10};
    auto even = [](int i){return 0 == i % 2;};

    std::vector<int> temp;
    std::copy_if(std::begin(number), std::end(number), std::back_inserter(temp), even);
    std::vector<int> temp2(std::begin(temp)+1, std::end(temp));

    for (auto iter = std::rbegin(temp2); iter != std::rend(temp2); ++iter)
        std::cout << *iter << " ";
}
