#include <iostream>

auto foo_len()
{
    auto i = 2;
    return i;
}

constexpr auto foo_len_constexpr()
{
    return 5;
}

inline constexpr auto fibnacci(const long n) -> long
{
    return n == 1 || n == 2 ? 1 : fibnacci(n - 1) + fibnacci(n - 2);
}

int main()
{
    constexpr auto len = 1+2+3;
    int arr1[len];
    int arr2[foo_len_constexpr() + 1];
    constexpr auto result = fibnacci(20);
    std::cout << result << std::endl;

    return 0;
}