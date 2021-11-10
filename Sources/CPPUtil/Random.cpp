#include "Random.h"

std::default_random_engine CPPUtil::Random::_randomEngine;

void CPPUtil::Random::Init(unsigned int seed)
{
	_randomEngine.seed(seed);
}

void CPPUtil::Random::Init()
{
	std::random_device rd;

	_randomEngine.seed(rd());
}