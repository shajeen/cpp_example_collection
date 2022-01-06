#include <iostream>
#include <type_traits>

void foo(int)
{
    std::cout << "int" << std::endl;
}

void foo(char*)
{
    std::cout << "char*" << std::endl;
}

int main()
{
    // cmp value to NULL
    if (std::is_same<decltype(NULL), decltype(0)>::value)
    {
        std::cout << "NULL == 0" << std::endl;
    }

    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
    {
        std::cout << "NULL == void" << std::endl;
    }

    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
    {
        std::cout << "NULL == std::nullptr_t" << std::endl;
    }

    foo(0);
    foo(nullptr);

    return 0;
}