#pragma once

#include <cstdlib>
#include <limits>
#include <stdint.h>
#include <time.h>
#include <type_traits>

namespace Util
{
	/// <summary>
	/// A namespace containing randomization utilities.
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
		/// Generates a random value within the range [0, 255].
		/// </summary>
		/// <typeparam name="T">uint8_t</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same<T, uint8_t>::value && ((RAND_MAX + 1) & 0xff) == 0, int> = 0>
		T Rand()
		{
			int randValue = std::rand();

			return static_cast<uint8_t>(randValue & 0xff);
		}

		/// <summary>
		/// Generates a random value within the range [0, 255].
		/// </summary>
		/// <typeparam name="T">uint8_t</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same<T, uint8_t>::value && ((RAND_MAX + 1) & 0xff) != 0, int> = 0>
		T Rand()
		{
			// Build an uint8_t bit by bit
			uint8_t result = 0;

			for (int i = 0; i < 8; i++)
			{
				int randValue = static_cast<uint8_t>(Rand<bool>());

				result |= randValue << i;
			}

			return result;
		}

		/// <summary>
		/// Generates a random boolean value.
		/// </summary>
		/// <typeparam name="T">bool</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_same<T, bool>::value, int> = 0>
		T Rand()
		{
			return std::rand() & 1;
		}

		/// <summary>
		/// Generates a random floating point value within the range [0, 1].
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<std::is_floating_point<T>::value, int> = 0>
		T Rand()
		{
			unsigned long long randValue = Rand<unsigned long long>();

			return static_cast<T>(randValue) / static_cast<T>(std::numeric_limits<unsigned long long>::max());
		}

		/// <summary>
		/// Generates a random value between the minimal and maximal value.
		/// </summary>
		/// <typeparam name="T">Type of the random value to generate</typeparam>
		/// <returns>The random value.</returns>
		template<typename T, std::enable_if_t<!std::is_same<T, uint8_t>::value && !std::is_same<T, bool>::value && !std::is_floating_point<T>::value, int> = 0>
		T Rand()
		{
			T result = 0;

			// Build result byte by byte
			for (size_t i = 0; i < sizeof(T); i++)
			{
				result |= (static_cast<T>(Rand<uint8_t>()) << i * 8);
			}

			return result;
		}
	}
}