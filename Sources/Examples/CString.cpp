#include <CPPUtil/CString.h>

int main(int argc, char* argv[])
{
	// Compare strings
	bool stringsEqual;
	stringsEqual = (CPPUtil::CString::Strcmp("Test", "Test") == 0); // stringsEqual = true
	stringsEqual = (CPPUtil::CString::Strcmp("Test", "Test2") == 0); // stringsEqual = false
	stringsEqual = (CPPUtil::CString::Strcmp("Test", "TEST") == 0); // stringsEqual = false
	stringsEqual = (CPPUtil::CString::Strcmp("Test", "TEST", false) == 0); // stringsEqual = true

	// Length of string
	size_t stringLength;
	stringLength = CPPUtil::CString::Strlen(""); // stringLength = 0
	stringLength = CPPUtil::CString::Strlen("Test"); // stringLength = 4

	// Concatenate strings
	char* concatenatedStrings;
	concatenatedStrings = CPPUtil::CString::Strcat(std::vector<const char*> {"Hello ", "World", "!"}); // concatenatedStrings = "Hello World!"
	delete[] concatenatedStrings;

	// Copy string
	char* copiedString;
	copiedString = CPPUtil::CString::Strcpy("Hello World!"); // copiedString = "Hello World!"
	delete[] copiedString;
	copiedString = CPPUtil::CString::Strcpy("Hello World!", 3); // copiedString = "Hel"
	delete[] copiedString;

	// Find first occurrence
	bool stringFound;
	size_t position;
	stringFound = CPPUtil::CString::Strpos("Hello World!", "Test", &position); // stringFound = false
	stringFound = CPPUtil::CString::Strpos("Hello World!", "World", &position); // stringFound = true, position = 6
	stringFound = CPPUtil::CString::Strpos("Hello World!", "l", &position); // stringFound = true, position = 2

	// Levenshtein distance
	size_t levenshteinDistance;
	levenshteinDistance = CPPUtil::CString::Levenshtein("kitten", "sitting"); // levenshteinDistance = 3
	levenshteinDistance = CPPUtil::CString::Levenshtein("kitten", "siTTing", true); // levenshteinDistance = 5

	// Is integer
	bool isType;
	isType = CPPUtil::CString::IsInteger<int>("123"); // isType = true
	isType = CPPUtil::CString::IsInteger<int>("-123"); // isType = true
	isType = CPPUtil::CString::IsInteger<uint8_t>("+255"); // isType = true
	isType = CPPUtil::CString::IsInteger<uint8_t>("256"); // isType = false
	isType = CPPUtil::CString::IsInteger<uint8_t>("-1"); // isType = false

	// Is floating point
	isType = CPPUtil::CString::IsFloatingPoint("3.1415"); // isType = true
	isType = CPPUtil::CString::IsFloatingPoint("3.14.15"); // isType = false
	isType = CPPUtil::CString::IsFloatingPoint("-7"); // isType = true

	return 0;
}