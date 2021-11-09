#include "Random.h"

#include <cstdlib>
#include <time.h>

void CPPUtil::Random::Init(unsigned int seed)
{
	std::srand(seed);
}

void CPPUtil::Random::Init()
{
	Init(static_cast<unsigned int>(time(NULL)));
}