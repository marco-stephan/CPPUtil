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

		// Amount of intervals to split [0; 1] into for the distribution check
		constexpr static const size_t DISTRIBUTION_FLOATING_INTERVALS = 64;

	protected:

		template<typename Type, std::enable_if_t<std::is_floating_point_v<Type>, int> = 0>
		void testEvenDistribution()
		{
			std::vector<size_t> randomResults;

			// Prepare random result vector
			for (size_t i = 0; i < DISTRIBUTION_FLOATING_INTERVALS; i++)
			{
				randomResults.push_back(0);
			}

			// Generate random values and check if evenly distributed
			for (size_t i = 0;; i++)
			{
				Type randomValue = CPPUtil::Random::Rand<Type>();

				// Place in correct interval
				// Note that 1 is ommitted from this so all intervals are equally sized
				for (size_t i = 0; i < DISTRIBUTION_FLOATING_INTERVALS; i++)
				{
					if (randomValue < static_cast<Type>(static_cast<double>(i + 1) * (1.0 / static_cast<double>(DISTRIBUTION_FLOATING_INTERVALS))))
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

		template<typename Type, std::enable_if_t<!std::is_floating_point_v<Type>, int> = 0>
		void testEvenDistribution()
		{
			std::vector<size_t> randomResults;

			// Prepare random result vector
			for (size_t i = static_cast<size_t>(std::numeric_limits<Type>::min());; i++)
			{
				randomResults.push_back(0);

				if (i == static_cast<size_t>(std::numeric_limits<Type>::max()))
				{
					break;
				}
			}

			// Generate random values and check if evenly distributed
			for (size_t i = 0;; i++)
			{
				Type randomValue = CPPUtil::Random::Rand<Type>();

				randomResults[randomValue - std::numeric_limits<Type>::min()]++;

				if (randomResultsEvenlyDistributed(randomResults))
				{
					break;
				}
			}
		}

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

	TEST_F(Random_Test, Bool)
	{
		testEvenDistribution<bool>();
	}

	TEST_F(Random_Test, UnsignedChar)
	{
		testEvenDistribution<unsigned char>();
	}

	TEST_F(Random_Test, Char)
	{
		testEvenDistribution<char>();
	}

	TEST_F(Random_Test, Float)
	{
		testEvenDistribution<float>();
	}
}