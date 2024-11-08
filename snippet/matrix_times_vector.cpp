#include <iostream>
#include <vector>

auto matrix_dot_vector(std::vector<std::vector<double>> a, std::vector<double> b)
{
    std::vector<double> output(b.size());
    int k = 0;

    for (auto i : a)
    {
        if (i.size() != b.size())
        {
            return std::vector<double>{-1};
        }

        for (auto j = 0; j < i.size(); ++j)
        {
            output[k] += i[j] * b[j];
        }

        k++;
    }

    return output;
}

void print(auto output)
{
    for (auto i : output)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main ()
{
    std::vector<std::vector<double>> a {{1,2}, {2,4}};
    std::vector<double> b{1,2};

    print(matrix_dot_vector(a,b));
    print(matrix_dot_vector({{1,2,3},{2,4,5},{6,8,9}},{1,2,3}));
    print(matrix_dot_vector({{1,2},{2,4},{6,8},{12,4}},{1,2,3}));

    return 0;
}