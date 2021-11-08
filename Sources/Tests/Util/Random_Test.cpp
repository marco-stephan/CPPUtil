#include <gtest/gtest.h>

#include "Util/Random.h"

namespace Util_Tests
{
	class Random_Test : public ::testing::Test
	{
	public:

		virtual void SetUp() override
		{
			// Seed RNG
			Util::Random::Init();
		}

		virtual void TearDown() override
		{
		}
	};

	TEST_F(Random_Test, Bool)
	{
		while (Util::Random::Rand<bool>())
		{
		}
		while (!Util::Random::Rand<bool>())
		{
		}
	}

	TEST_F(Random_Test, UnsignedChar)
	{
		while (Util::Random::Rand<unsigned char>() != 0)
		{
		}
		while (Util::Random::Rand<unsigned char>() != std::numeric_limits<unsigned char>::max())
		{
		}
	}

	TEST_F(Random_Test, Char)
	{
		while (Util::Random::Rand<char>() != std::numeric_limits<char>::min())
		{
		}
		while (Util::Random::Rand<char>() != std::numeric_limits<char>::max())
		{
		}
	}

	TEST_F(Random_Test, Float)
	{
		for (size_t i = 0; i < 1000; i++)
		{
			float number = Util::Random::Rand<float>();

			ASSERT_TRUE(number >= 0.0f && number <= 1.0f);
		}
	}
}