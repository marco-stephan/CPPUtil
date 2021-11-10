#include <gtest/gtest.h>

#include "CPPUtil/Math/Basics.h"
#include "CPPUtil/Random.h"

namespace CPPUtil_Test
{
	class Random_Test : public ::testing::Test
	{
	private:

		// Amount of elements needed to perform the distribution check
		constexpr static const size_t DISTRIBUTION_MIN_ELEMENTS = 100000;

		// Max deviation between expectancy value and each element of the distribution
		constexpr static const double DISTRIBUTION_MAX_DEVIATION = 0.025;

		// Amount of intervals to split [0; 1) into for the distribution check
		constexpr static const size_t DISTRIBUTION_FLOATING_INTERVALS = 32;

		// Amount of iterations to make sure that if min = max and both boundaries are inclusive, only min = max is returned
		constexpr static const size_t MIN_MAX_ITERATIONS = 1000;

		// Value of the min = max value
		constexpr static const size_t MIN_MAX_VALUE = 11;

	protected:

		/// <summary>
		/// Checks whether the CPPUtil::Random::Rand<Type>() function returns an even distribution
		/// </summary>
		/// <typeparam name="Type">Type of the values to randomize</typeparam>
		/// <param name="min">Lower boundary of the values to generate (inclusive)</param>
		/// <param name="max">Upper boundary of the values to generate (exclusive)</param>
		template<typename Type, std::enable_if_t<std::is_floating_point_v<Type>, int> = 0>
		void testEvenDistribution(const Type min, const Type max)
		{
			std::vector<size_t> randomResults;

			// Prepare random result vector
			for (size_t i = 0; i < DISTRIBUTION_FLOATING_INTERVALS; i++)
			{
				randomResults.push_back(0);
			}

			// Generate random values and check if evenly distributed
			while (true)
			{
				Type randomValue = CPPUtil::Random::Rand<Type>(min, max, true, false);

				// Place in correct interval
				for (size_t i = 0; i < DISTRIBUTION_FLOATING_INTERVALS; i++)
				{
					if (randomValue < min + static_cast<Type>(static_cast<double>(i + 1) * (1.0 / static_cast<double>(DISTRIBUTION_FLOATING_INTERVALS))))
					{
						randomResults[i]++;
						break;
					}
				}

				if (randomResultsEvenlyDistributed(randomResults))
				{
					break;
				}
			}
		}

		/// <summary>
		/// Checks whether the CPPUtil::Random::Rand<Type>() function returns an even distribution
		/// </summary>
		/// <typeparam name="Type">Type of the values to randomize</typeparam>
		/// <param name="min">Lower boundary of the values to generate (inclusive)</param>
		/// <param name="max">Upper boundary of the values to generate (inclusive)</param>
		template<typename Type, std::enable_if_t<!std::is_floating_point_v<Type>, int> = 0>
		void testEvenDistribution(const Type min, const Type max)
		{
			std::vector<size_t> randomResults;

			// Prepare random result vector
			for (size_t i = static_cast<size_t>(min);; i++)
			{
				randomResults.push_back(0);

				if (i == static_cast<size_t>(max))
				{
					break;
				}
			}

			// Generate random values and check if evenly distributed
			while (true)
			{
				Type randomValue = CPPUtil::Random::Rand<Type>(min, max, true, true);

				randomResults[randomValue - min]++;

				if (randomResultsEvenlyDistributed(randomResults))
				{
					break;
				}
			}
		}

		/// <summary>
		/// Checks whether the CPPUtil::Random::RandInterval<Type>() function returns a distribution corresponding to the cardinality-sum of cardinality-relation
		/// </summary>
		/// <typeparam name="Type">Type of the vector's elements</typeparam>
		/// <param name="intervals">Intervals used for the randomization</param>
		template<typename Type>
		void testIntervalDistribution(const std::vector<Type>& intervals)
		{
			std::vector<size_t> randomResults;

			// Prepare random result vector
			for (auto interval : intervals)
			{
				randomResults.push_back(0);
			}

			// Generate random values and check if evenly distributed
			while (true)
			{
				size_t randomIndex;

				ASSERT_TRUE(CPPUtil::Random::RandInterval(intervals, &randomIndex));

				randomResults[randomIndex]++;

				if (randomResultsCardinalityDistributed(randomResults, intervals))
				{
					break;
				}
			}
		}

		/// <summary>
		/// Checks whether the provided random value vector is semi-evenly distributed
		/// </summary>
		/// <param name="randomResults">Random value vector. Contains the number of times each "element" has been hit</param>
		/// <returns>True if semi-evenly distributed; False otherwise</returns>
		bool randomResultsEvenlyDistributed(std::vector<size_t>& randomResults)
		{
			// Vector must contain at least DISTRIBUTION_MIN_ELEMENTS random results
			size_t sum = 0;

			for (size_t& randomResult : randomResults)
			{
				sum += randomResult;
			}

			if (sum < DISTRIBUTION_MIN_ELEMENTS)
			{
				return false;
			}

			// All elements of the random result vector (i.e. the distribution results) must not deviate more than DISTRIBUTION_MAX_DEVIATION from the expectancy value
			double expectancyValue = round(static_cast<double>(sum) / static_cast<double>(randomResults.size()));

			for (size_t& randomResult : randomResults)
			{
				if (CPPUtil::Math::Basics::Abs(1.0 - static_cast<double>(randomResult) / expectancyValue) > DISTRIBUTION_MAX_DEVIATION)
				{
					return false;
				}
			}

			// Distribution is more or less even
			return true;
		}

		/// <summary>
		/// Checks whether the provided random value vector is distributed accordingly to an interval vector (i.e. to cardinality)
		/// </summary>
		/// <param name="randomResults">Random value vector. Contains the number of times each "element" has been hit</param>
		/// <returns>True if distributed accordingly to cardinality; False otherwise</returns>
		template<typename Type>
		bool randomResultsCardinalityDistributed(std::vector<size_t>& randomResults, const std::vector<Type>& intervals)
		{
			// Vector must contain at least DISTRIBUTION_MIN_ELEMENTS random results
			size_t sum = 0;

			for (size_t& randomResult : randomResults)
			{
				sum += randomResult;
			}

			if (sum < DISTRIBUTION_MIN_ELEMENTS)
			{
				return false;
			}

			// Determine sum of cardinality
			double cardinalitySum = 0.0;

			for (auto interval : intervals)
			{
				cardinalitySum += static_cast<double>(interval);
			}

			// All elements of the random result vector (i.e. the distribution results) must not deviate more than DISTRIBUTION_MAX_DEVIATION from the expectancy value
			for (size_t i = 0; i < randomResults.size(); i++)
			{
				size_t& randomResult = randomResults[i];
				auto interval = intervals[i];

				if (interval == 0)
				{
					// If zero-width interval -> There must not be any hits
					[&](){ASSERT_EQ(randomResult, 0);}();
				}
				else
				{
					double expectancyValue = round(static_cast<double>(sum) * static_cast<double>(interval) / static_cast<double>(cardinalitySum));

					if (CPPUtil::Math::Basics::Abs(1.0 - static_cast<double>(randomResult) / expectancyValue) > DISTRIBUTION_MAX_DEVIATION)
					{
						return false;
					}
				}
			}

			// Distribution is more or less correct
			return true;
		}

		/// <summary>
		/// Tests whether if min = max and both boundaries are inclusive, only the min = max value is returned at all times
		/// </summary>
		/// <typeparam name="Type">Type of the values to randomize</typeparam>
		template<typename Type>
		void testMinEqualsMax()
		{
			for (size_t i = 0; i < MIN_MAX_ITERATIONS; i++)
			{
				const Type randomValue = CPPUtil::Random::Rand<Type>(static_cast<Type>(MIN_MAX_VALUE), static_cast<Type>(MIN_MAX_VALUE), true, true);

				if constexpr (std::is_floating_point_v<Type>)
				{
					if constexpr (std::is_same_v<Type, float>)
					{
						ASSERT_FLOAT_EQ(randomValue, static_cast<Type>(MIN_MAX_VALUE));
					}
					else
					{
						ASSERT_DOUBLE_EQ(randomValue, static_cast<Type>(MIN_MAX_VALUE));
					}
				}
				else
				{
					ASSERT_EQ(randomValue, static_cast<Type>(MIN_MAX_VALUE));
				}
			}
		}

	public:

		virtual void SetUp() override
		{
			// Seed RNG
			CPPUtil::Random::Init();
		}

		virtual void TearDown() override
		{
		}
	};

	TEST_F(Random_Test, RandBool)
	{
		testEvenDistribution<bool>(std::numeric_limits<bool>::min(), std::numeric_limits<bool>::max());
		testEvenDistribution<bool>(false, false);
		testEvenDistribution<bool>(true, true);

		testMinEqualsMax<bool>();
	}

	TEST_F(Random_Test, RandUnsignedChar)
	{
		testEvenDistribution<unsigned char>(std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max());
		testEvenDistribution<unsigned char>(17, 104);

		testMinEqualsMax<unsigned char>();
	}

	TEST_F(Random_Test, RandChar)
	{
		testEvenDistribution<char>(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
		testEvenDistribution<char>(17, 104);

		testMinEqualsMax<char>();
	}

	TEST_F(Random_Test, RandFloat)
	{
		testEvenDistribution<float>(0.0f, 1.0f);
		testEvenDistribution<float>(-8.0f, 20.0f);

		testMinEqualsMax<float>();
	}

	TEST_F(Random_Test, RandDouble)
	{
		testEvenDistribution<double>(0.0, 1.0);
		testEvenDistribution<double>(-8.0, 20.0);

		testMinEqualsMax<double>();
	}

	TEST_F(Random_Test, RandIntervalBool)
	{
		ASSERT_FALSE(CPPUtil::Random::RandInterval<bool>({}, nullptr));
		ASSERT_FALSE(CPPUtil::Random::RandInterval<bool>({false, false, false}, nullptr));

		testIntervalDistribution<bool>({true, false, true, true, false, true, true, true, true, true});
		testIntervalDistribution<bool>({true});
	}

	TEST_F(Random_Test, RandIntervalUnsignedChar)
	{
		ASSERT_FALSE(CPPUtil::Random::RandInterval<unsigned char>({}, nullptr));
		ASSERT_FALSE(CPPUtil::Random::RandInterval<unsigned char>({0, 0, 0}, nullptr));

		testIntervalDistribution<unsigned char>({1, 0, 9, 40, 0, 240, 123, 37, 91, 2});
		testIntervalDistribution<unsigned char>({100});
	}

	TEST_F(Random_Test, RandIntervalChar)
	{
		ASSERT_FALSE(CPPUtil::Random::RandInterval<char>({}, nullptr));
		ASSERT_FALSE(CPPUtil::Random::RandInterval<char>({0, 0, 0}, nullptr));

		testIntervalDistribution<char>({1, 0, 9, 40, 0, 127, 123, 37, 91, 2});
		testIntervalDistribution<char>({100});
	}

	TEST_F(Random_Test, RandIntervalFloat)
	{
		ASSERT_FALSE(CPPUtil::Random::RandInterval<float>({}, nullptr));
		ASSERT_FALSE(CPPUtil::Random::RandInterval<float>({0.0f, 0.0f, 0.0f}, nullptr));

		testIntervalDistribution<float>({1.0f, 0.0f, 9.0f, 40.0f, 0.0f, 240.0f, 123.0f, 37.0f, 91.0f, 2.0f});
		testIntervalDistribution<float>({1.0f});
		testIntervalDistribution<float>({0.2f, 0.8f});
	}

	TEST_F(Random_Test, RandIntervalDouble)
	{
		ASSERT_FALSE(CPPUtil::Random::RandInterval<double>({}, nullptr));
		ASSERT_FALSE(CPPUtil::Random::RandInterval<double>({0.0, 0.0, 0.0}, nullptr));

		testIntervalDistribution<double>({1.0, 0.0, 9.0, 40.0, 0.0, 240.0, 123.0, 37.0, 91.0, 2.0});
		testIntervalDistribution<double>({1.0});
		testIntervalDistribution<double>({0.2, 0.8});
	}
}