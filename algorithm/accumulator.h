#pragma once

#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>

namespace algorithm
{
	void accumulator_example()
	{
		// 1 - sum of all element in vector.
		{
			//  std::vector<int> example_vector = std::vector<int, std::allocator<int> >(10, std::allocator<int>());
			std::vector<int> example_vector(10);
			std::generate(example_vector.begin(), example_vector.end(), std::rand);

			const auto result = std::accumulate(example_vector.begin(), example_vector.end(), 1);

			//std::operator<<(std::cout, "accumulator example (1) : \n Elements in vector: ");
			std::cout << "accumulator example (1) : \n "
				"Elements in vector: ";

			//            class __lambda_16_73
			//            {
			//            public:
			//                template<class type_parameter_0_0>
			//                inline /*constexpr */ auto operator()(const type_parameter_0_0& val) const
			//                {
			//                    (std::cout << val) << ", ";
			//                }
			//
			//#ifdef INSIGHTS_USE_TEMPLATE
			//                template<>
			//                inline /*constexpr */ void operator()(const int& val) const
			//                {
			//                    std::operator<<(std::cout.operator<<(val), ", ");
			//                }
			//#endif
			//
			//            private:
			//                template<class type_parameter_0_0>
			//                static inline auto __invoke(const type_parameter_0_0& val)
			//                {
			//                    (std::cout << val) << ", ";
			//                }
			//            public:
			//                // inline /*constexpr */ __lambda_16_73(__lambda_16_73 &&) noexcept = default;
			//
			//            };

			// std::for_each(example_vector.begin(), example_vector.end(), __lambda_16_73{});
			std::for_each(example_vector.begin(), example_vector.end(), [](const auto& val) {
				std::cout << val << ", ";
				});

			// std::operator<<(std::operator<<(std::cout, "\n sum of all element in vector: ").operator<<(result), "\n").operator<<(std::endl);
			std::cout << "\n sum of all element in vector: " << result << "\n" << std::endl;
		}


		// 2 - can be used for customized function.
		{
			//			class __lambda_9_31
			//			{
			//			public:
			//				template<class type_parameter_0_0, class type_parameter_0_1>
			//				inline /*constexpr */ auto operator()(const type_parameter_0_0& double_vector_val_1, const type_parameter_0_1& double_vector_val_2) const
			//				{
			//					const auto mul = double_vector_val_1 * double_vector_val_2;
			//					return (mul / 0.10000000000000001);
			//				}
			//
			//#ifdef INSIGHTS_USE_TEMPLATE
			//				template<>
			//				inline /*constexpr */ double operator()(const int& double_vector_val_1, const double& double_vector_val_2) const
			//				{
			//					const double mul = static_cast<double>(double_vector_val_1) * double_vector_val_2;
			//					return (mul / 0.10000000000000001);
			//				}
			//#endif
			//
			//			private:
			//				template<class type_parameter_0_0, class type_parameter_0_1>
			//				static inline auto __invoke(const type_parameter_0_0& double_vector_val_1, const type_parameter_0_1& double_vector_val_2)
			//				{
			//					const auto mul = double_vector_val_1 * double_vector_val_2;
			//					return (mul / 0.10000000000000001);
			//				}
			//			public:
			//				// inline /*constexpr */ __lambda_9_31(const __lambda_9_31 &) noexcept = default;
			//
			//			};

			// __lambda_9_31 customized_function = __lambda_9_31{};
			auto customized_function = [](const auto& double_vector_val_1, const auto& double_vector_val_2)
			{
				const auto mul = double_vector_val_1 * double_vector_val_2;
				return (mul / 1e-01);
			};

			// std::vector<double> double_vector = std::vector<double, std::allocator<double> >(10, std::allocator<double>());
			std::vector<double> double_vector(10);
			std::generate(double_vector.begin(), double_vector.end(), std::rand);

			const auto result = std::accumulate(double_vector.begin(), double_vector.end(), 1, customized_function);

			// std::operator<<(std::cout, "accumulator example (2) : \n Elements in vector: ");
			std::cout << "accumulator example (2) : \n "
				"Elements in vector: ";

			//			class __lambda_22_62
			//			{
			//			public:
			//				template<class type_parameter_0_0>
			//				inline /*constexpr */ auto operator()(const type_parameter_0_0& val) const
			//				{
			//					(std::cout << val) << ", ";
			//				}
			//
			//#ifdef INSIGHTS_USE_TEMPLATE
			//				template<>
			//				inline /*constexpr */ void operator()(const double& val) const
			//				{
			//					std::operator<<(std::cout.operator<<(val), ", ");
			//				}
			//#endif
			//
			//			private:
			//				template<class type_parameter_0_0>
			//				static inline auto __invoke(const type_parameter_0_0& val)
			//				{
			//					(std::cout << val) << ", ";
			//				}
			//			public:
			//				// inline /*constexpr */ __lambda_22_62(__lambda_22_62 &&) noexcept = default;
			//
			//			};

			// std::for_each(double_vector.begin(), double_vector.end(), __lambda_22_62{});
			std::for_each(double_vector.begin(), double_vector.end(), [](const auto& val) {
				std::cout << val << ", ";
				});

			// std::operator<<(std::operator<<(std::cout, "\n Result after using customized function to std::accumulator: ").operator<<(result), "\n").operator<<(std::endl);
			std::cout << "\n Result after using customized function to std::accumulator: " << result << "\n" << std::endl;
		}
	}
}