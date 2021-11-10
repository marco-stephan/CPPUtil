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
		/// Generates a random integer point value within the range [min, max] (min and max are minimum and maximum value of corresponding integer type).
		/// </summary>
		/// <typeparam name="T">Any integral type</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>, int> = 0>
		T Rand()
		{
			return Rand<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max(), true, true);
		}

		/// <summary>
		/// Generates a random integer value within the provided range
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <param name="min">Lower boundary of the range</param>
		/// <param name="max">Upper boundary of the range</param>
		/// <param name="minInclusive">True to include the lower boundary; False if it shall be excluded</param>
		/// <param name="maxInclusive">True to include the upper boundary; False if it shall be excluded</param>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>, int> = 0>
		T Rand(const T min, const T max, const bool minInclusive, const bool maxInclusive)
		{
			if constexpr (sizeof(T) < 2)
			{
				// For some reason MSVC does not support a uniform_int_distribution<T> where sizeof(T) < 2 (e.g. uint8_t)
				// Therefore, we just generate one for int16_t and then cast it down

				return static_cast<T>(Rand<int16_t>(static_cast<int16_t>(min), static_cast<int16_t>(max), minInclusive, maxInclusive));
			}
			else
			{
				const T lowerBoundaryInclusive = (minInclusive ? min : min + 1);
				const T upperBoundaryInclusive = (maxInclusive ? max : max - 1);

				std::uniform_int_distribution<T> randomDistribution(lowerBoundaryInclusive, upperBoundaryInclusive);

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
			return Rand<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max(), true, true);
		}

		/// <summary>
		/// Generates a random boolean value within the provided range
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <param name="min">Lower boundary of the range</param>
		/// <param name="max">Upper boundary of the range</param>
		/// <param name="minInclusive">True to include the lower boundary; False if it shall be excluded</param>
		/// <param name="maxInclusive">True to include the upper boundary; False if it shall be excluded</param>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same_v<T, bool>, int> = 0>
		T Rand(const T min, const T max, const bool minInclusive, const bool maxInclusive)
		{
			return static_cast<T>(Rand<uint8_t>(static_cast<uint8_t>(min), static_cast<uint8_t>(max), minInclusive, maxInclusive));
		}

		/// <summary>
		/// Generates a random floating point value within the range [0, 1].
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
		T Rand()
		{
			return Rand<T>(static_cast<T>(0.0), static_cast<T>(1.0), true, true);
		}

		/// <summary>
		/// Generates a random floating point value within the provided range
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <param name="min">Lower boundary of the range</param>
		/// <param name="max">Upper boundary of the range</param>
		/// <param name="minInclusive">True to include the lower boundary; False if it shall be excluded</param>
		/// <param name="maxInclusive">True to include the upper boundary; False if it shall be excluded</param>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
		T Rand(const T min, const T max, const bool minInclusive, const bool maxInclusive)
		{
			const T lowerBoundaryInclusive = (minInclusive ? min : std::nextafter(min, std::numeric_limits<T>::max()));
			const T upperBoundaryExclusive = (maxInclusive ? std::nextafter(max, std::numeric_limits<T>::max()) : max);

			std::uniform_real_distribution<T> randomDistribution(lowerBoundaryInclusive, upperBoundaryExclusive);

			return randomDistribution(randomEngine);
		}
	}
}