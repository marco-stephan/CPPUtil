#include <CPPUtil/String.h>

int main(int argc, char* argv[])
{
	// Compare strings
	bool stringsEqual;
	stringsEqual = (CPPUtil::String::Strcmp(std::string("Test"), std::string("Test")) == 0); // stringsEqual = true
	stringsEqual = (CPPUtil::String::Strcmp(std::string("Test"), std::string("Test2")) == 0); // stringsEqual = false
	stringsEqual = (CPPUtil::String::Strcmp(std::string("Test"), std::string("TEST")) == 0); // stringsEqual = false
	stringsEqual = (CPPUtil::String::Strcmp(std::string("Test"), std::string("TEST"), false) == 0); // stringsEqual = true

	// Trim
	std::string trimmedString;
	trimmedString = CPPUtil::String::TrimLeft(std::string("  Test  ")); // trimmedString = "Test  "
	trimmedString = CPPUtil::String::TrimRight(std::string("  Test  ")); // trimmedString = "  Test"
	trimmedString = CPPUtil::String::Trim(std::string("  Test  ")); // trimmedString = "Test"

	// Split
	std::vector<std::string> splitStrings;
	splitStrings = CPPUtil::String::Split(std::string("Test1 a Test2  Test3 "), ' ', false); // splitStrings = {"Test1", "a", "Test2", "", "Test3", ""}
	splitStrings = CPPUtil::String::Split(std::string("Test1 a Test2  Test3 "), ' ', true); // splitStrings = {"Test1", "a", "Test2", "Test3", ""}
	splitStrings = CPPUtil::String::Split(std::string("Test1 a Test2  Test3 "), " a", true); // splitStrings = {"Test1", "Test2", "Test3", ""}

	// Is integer
	bool isType;
	isType = CPPUtil::String::IsInteger<int>(std::string("123")); // isType = true
	isType = CPPUtil::String::IsInteger<int>(std::string("-123")); // isType = true
	isType = CPPUtil::String::IsInteger<uint8_t>(std::string("+255")); // isType = true
	isType = CPPUtil::String::IsInteger<uint8_t>(std::string("256")); // isType = false
	isType = CPPUtil::String::IsInteger<uint8_t>(std::string("-1")); // isType = false

	// Is floating point
	isType = CPPUtil::String::IsFloatingPoint(std::string("3.1415")); // isType = true
	isType = CPPUtil::String::IsFloatingPoint(std::string("3.14.15")); // isType = false
	isType = CPPUtil::String::IsFloatingPoint(std::string("-7")); // isType = true

	return 0;
}