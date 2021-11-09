#pragma once

#include <cstdlib>
#include <limits>
#include <stdint.h>
#include <time.h>
#include <type_traits>

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing randomization utilities.
	/// Internally, the std::rand functionality is used
	/// </summary>
	namespace Random
	{
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
			// Determine how many std::rand calls are necessary to fill all bits of the value randomly
			uint8_t bitsRandMax = 0;
			int bitsmaskRandMax = 0;

			for (uint8_t i = 0; i <= sizeof(int) * CHAR_BIT; i++)
			{
				if (!(RAND_MAX & (1 << i)))
				{
					break;
				}

				bitsmaskRandMax |= (1 << i);
				bitsRandMax++;
			}

			// Fill result
			T result = 0;

			for (uint8_t bitsFilled = 0; bitsFilled < sizeof(T) * CHAR_BIT; bitsFilled += bitsRandMax)
			{
				const int randValue = (std::rand() & bitsmaskRandMax);

				result |= (randValue << bitsFilled);
			}

			return result;
		}

		/// <summary>
		/// Generates a random boolean value.
		/// </summary>
		/// <typeparam name="T">bool</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same_v<T, bool>, int> = 0>
		T Rand()
		{
			return std::rand() & 1;
		}

		/// <summary>
		/// Generates a random floating point value within the range [0, 1].
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
		T Rand()
		{
			uintmax_t randValue = Rand<uintmax_t>();

			return static_cast<T>(randValue) / static_cast<T>(std::numeric_limits<uintmax_t>::max());
		}
	}
}