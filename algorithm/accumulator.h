#pragma once

#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>

namespace algorithm
{
	class __lambda_16_73
	{
	public:
		template<class type_parameter_0_0>
		inline /*constexpr */ auto operator()(const type_parameter_0_0& val) const
		{
			(std::cout << val) << ", ";
		}

	private:
		template<class type_parameter_0_0>
		static inline auto __invoke(const type_parameter_0_0& val)
		{
			(std::cout << val) << ", ";
		}
	};

	class __lambda_9_31
	{
	public:
		template<class type_parameter_0_0, class type_parameter_0_1>
		inline /*constexpr */ auto operator()(const type_parameter_0_0& double_vector_val_1, const type_parameter_0_1& double_vector_val_2) const
		{
			const auto mul = double_vector_val_1 * double_vector_val_2;
			return (mul / 0.10000000000000001);
		}

	private:
		template<class type_parameter_0_0, class type_parameter_0_1>
		static inline auto __invoke(const type_parameter_0_0& double_vector_val_1, const type_parameter_0_1& double_vector_val_2)
		{
			const auto mul = double_vector_val_1 * double_vector_val_2;
			return (mul / 0.10000000000000001);
		}
	};

	void accumulator_example()
	{
		// 1 - sum of all element in vector.
		{
			std::vector<int> example_vector = std::vector<int, std::allocator<int> >(10, std::allocator<int>());
			std::generate(example_vector.begin(), example_vector.end(), std::rand);

			const auto result = std::accumulate(example_vector.begin(), example_vector.end(), 1);

			std::operator<<(std::cout, "accumulator example (1) : \n Elements in vector: ");

			std::for_each(example_vector.begin(), example_vector.end(), __lambda_16_73{});

			std::operator<<(std::operator<<(std::cout, "\n sum of all element in vector: ").operator<<(result), "\n").operator<<(std::endl);
		}


		// 2 - can be used for customized function.
		{
			__lambda_9_31 customized_function = __lambda_9_31{};

			std::vector<double> double_vector = std::vector<double, std::allocator<double> >(10, std::allocator<double>());
			std::generate(double_vector.begin(), double_vector.end(), std::rand);

			const auto result = std::accumulate(double_vector.begin(), double_vector.end(), 1, customized_function);

			std::operator<<(std::cout, "accumulator example (2) : \n Elements in vector: ");

			std::for_each(double_vector.begin(), double_vector.end(), __lambda_16_73{});

			std::operator<<(std::operator<<(std::cout, "\n Result after using customized function to std::accumulator: ").operator<<(result), "\n").operator<<(std::endl);
		}
	}
}