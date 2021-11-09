#include <gtest/gtest.h>

#include "CPPUtil/Random.h"

namespace CPPUtil_Test
{
	class Random_Test : public ::testing::Test
	{
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
		while (CPPUtil::Random::Rand<bool>())
		{
		}
		while (!CPPUtil::Random::Rand<bool>())
		{
		}
	}

	TEST_F(Random_Test, UnsignedChar)
	{
		while (CPPUtil::Random::Rand<unsigned char>() != 0)
		{
		}
		while (CPPUtil::Random::Rand<unsigned char>() != std::numeric_limits<unsigned char>::max())
		{
		}
	}

	TEST_F(Random_Test, Char)
	{
		while (CPPUtil::Random::Rand<char>() != std::numeric_limits<char>::min())
		{
		}
		while (CPPUtil::Random::Rand<char>() != std::numeric_limits<char>::max())
		{
		}
	}

	TEST_F(Random_Test, Float)
	{
		for (size_t i = 0; i < 1000; i++)
		{
			float number = CPPUtil::Random::Rand<float>();

			ASSERT_TRUE(number >= 0.0f && number <= 1.0f);
		}
	}
}