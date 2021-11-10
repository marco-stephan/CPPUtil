#include "Random.h"

std::default_random_engine CPPUtil::Random::randomEngine;

void CPPUtil::Random::Init(unsigned int seed)
{
	randomEngine.seed(seed);
}

void CPPUtil::Random::Init()
{
	std::random_device rd;

	randomEngine.seed(rd());
}