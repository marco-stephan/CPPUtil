#include "Rand.h"

#include <cstdlib>
#include <time.h>

using namespace Util;

void Random::Init(unsigned int seed)
{
	std::srand(seed);
}

void Random::Init()
{
	Init(static_cast<unsigned int>(time(NULL)));
}