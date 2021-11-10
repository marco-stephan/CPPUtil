#include <CPPUtil/Random.h>

int main(int argc, char* argv[])
{
	// Initialize RNG
	CPPUtil::Random::Init();

	// Generate random values
	bool randomBool = CPPUtil::Random::Rand<bool>(); // Random bool
	int randomInt = CPPUtil::Random::Rand<int>(10, 20, true, true); // Random int between 10 and 20 (both included)
	float randomFloat = CPPUtil::Random::Rand<float>(-2.0f, 5.7f, true, false);  // Random float between -2 and 5.7 (-2 included, 5.7 excluded)

	// Generate random interval
	size_t randomIndex;
	CPPUtil::Random::RandInterval(std::vector<float> {0.2f, 0.7f, 0.1f}, &randomIndex); // randomIndex is 0 with a probability of 20%, 1 with 70% and 2 with 10%

	// Generate random occurrence
	bool eventOccurred = CPPUtil::Random::EventOccurs(0.95f); // eventOccurred is true with a probability of 95%

	return 0;
}