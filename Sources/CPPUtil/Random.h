#pragma once

#include <cstdint>
#include <limits>
#include <random>
#include <type_traits>

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing randomization utilities.
	/// Internally, the std::rand functionality is used
	/// </summary>
	namespace Random
	{
		extern std::default_random_engine randomEngine;

		/// <summary>
		/// Initializes the randomization utilities.
		/// </summary>
		/// <param name="seed">The seed.</param>
		void Init(unsigned int seed);

		/// <summary>
		/// Initializes the randomization utilities.
		/// </summary>
		void Init();

		/// <summary>
		/// Generates a random value within the minimum and maximum value of an integer.
		/// </summary>
		/// <typeparam name="T">Any integral type</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>, int> = 0>
		T Rand()
		{
			if constexpr (sizeof(T) < 2)
			{
				// For some reason MSVC does not support a uniform_int_distribution<T> where sizeof(T) < 2
				// Therefore, we just generate one for int16_t and then cast it down
				std::uniform_int_distribution<int16_t> randomDistribution(static_cast<int16_t>(std::numeric_limits<T>::min()), static_cast<int16_t>(std::numeric_limits<T>::max()));

				return static_cast<T>(randomDistribution(randomEngine));
			}
			else
			{
				std::uniform_int_distribution<T> randomDistribution(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());

				return randomDistribution(randomEngine);
			}
		}

		/// <summary>
		/// Generates a random boolean value.
		/// </summary>
		/// <typeparam name="T">bool</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same_v<T, bool>, int> = 0>
		T Rand()
		{
			std::uniform_int_distribution<uint16_t> randomDistribution(0, 1);

			return static_cast<bool>(randomDistribution(randomEngine));
		}

		/// <summary>
		/// Generates a random floating point value within the range [0, 1).
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
		T Rand()
		{
			std::uniform_real_distribution<T> randomDistribution(static_cast<T>(0.0), static_cast<T>(1.0));

			return randomDistribution(randomEngine);
		}
	}
}