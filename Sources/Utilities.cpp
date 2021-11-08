#include <iostream>
#include "Util/Random.h"

void testRandomizer()
{
	using namespace Util;

	Random::Init();

	// Make sure random unsigned data types work correctly
	while (Random::Rand<unsigned char>() != 0)
	{
	}
	while (Random::Rand<unsigned char>() != std::numeric_limits<unsigned char>::max())
	{
	}

	// Make sure random data types work correctly
	while (Random::Rand<char>() != std::numeric_limits<char>::min())
	{
	}
	while (Random::Rand<char>() != std::numeric_limits<char>::max())
	{
	}

	// Make sure random bool work correctly
	while (Random::Rand<bool>())
	{
	}
	while (!Random::Rand<bool>())
	{
	}

	// Make sure random floating points work correctly
	for (int i = 0; i < 1000; i++)
	{
		float number = Random::Rand<float>();

		if (number < 0 || number > 1)
		{
			throw new std::exception("random floating point not within the range [0, 1].");
		}
	}
}

int main()
{
	testRandomizer();
}