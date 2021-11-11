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
		extern std::default_random_engine _randomEngine;

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

				return randomDistribution(_randomEngine);
			}
		}

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

			// According to https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution#Notes, there are many implementations
			// in which the bug is present that uniform_real_distribution<T>(a, b) actually returns a floating value in [a; b] instead of
			// [a; b). This can be easily checked by checking if the maximum generated floating point value is equal to the b. If so, use
			// the largest floating point smaller than b as the new (now inclusive) upper boundary.
			if (randomDistribution.max() == upperBoundaryExclusive)
			{
				// Current implementation is bugged and uses [a; b] --> override distribution
				const T upperBoundaryInclusive = (maxInclusive ? max : std::nextafter(max, std::numeric_limits<T>::min()));

				randomDistribution = std::uniform_real_distribution<T>(lowerBoundaryInclusive, upperBoundaryInclusive);
			}

			return randomDistribution(_randomEngine);
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
		/// Determines a random interval given several intervals. The propability of each interval is equal to its value (i.e. cardinality) in relation to the total interval sum.
		/// The cardinalities must not be negative
		/// </summary>
		/// <typeparam name="T">Type of the elements of the interval vector</typeparam>
		/// <param name="intervals">Intervals. Each interval is defined by its cardinality</param>
		/// <param name="randomIntervalIndex">Index of the random interval. Only valid if true is returned. May be NULL</param>
		/// <returns>True if a random interval could be determined; False if no intervals provided or if none of the intervals have a cardinality &gt; 0</returns>
		template<typename T>
		bool RandInterval(const std::vector<T>& intervals, size_t* randomIntervalIndex)
		{
			// Determine sum of cardinality
			double cardinalitySum = 0.0;

			for (auto interval : intervals)
			{
				cardinalitySum += static_cast<double>(interval);
			}

			// Check if any non-empty intervals were provided
			if (!cardinalitySum)
			{
				return false;
			}

			// Check if index shall be determined
			if (randomIntervalIndex)
			{
				// Generate random number
				double randomValue = Rand<double>(0.0, cardinalitySum, true, false);

				// Determine in which interval the random value lies (all intervals are placed after each other)
				for (size_t i = 0; i < intervals.size(); i++)
				{
					double interval = static_cast<double>(intervals[i]);

					if (randomValue < interval)
					{
						// Random interval determined
						*randomIntervalIndex = i;
						break;
					}

					// Discard the current interval to "move to the next interval"
					randomValue -= interval;
				}
			}

			// Random interval could be determined
			return true;
		}

		/// <summary>
		/// Returns whether an event randomly occurs
		/// </summary>
		/// <typeparam name="T">Type of the probability of the event</typeparam>
		/// <param name="probability">Probability of the event to occur. Must be in range [0; 1]</param>
		/// <returns>True if the event randomly occurred; False otherwise</returns>
		template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
		bool EventOccurs(const T& probability)
		{
			return Rand<T>(static_cast<T>(0), static_cast<T>(1), true, false) < probability;
		}
	}
}