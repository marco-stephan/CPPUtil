#include <gtest/gtest.h>

#include "CPPUtil/String.h"

namespace CPPUtil_Test
{
	class String_Test : public ::testing::Test
	{
	public:

		virtual void SetUp() override
		{
		}

		virtual void TearDown() override
		{
		}
	};

	TEST_F(String_Test, Strcmp)
	{
		ASSERT_EQ(CPPUtil::String::Strcmp(std::string("Test"), std::string("Test")), 0);

		ASSERT_NE(CPPUtil::String::Strcmp(std::string("Test"), std::string("Not Test")), 0);
		ASSERT_NE(CPPUtil::String::Strcmp(std::string("Test"), std::string("TEST")), 0);
		ASSERT_EQ(CPPUtil::String::Strcmp(std::string("Test"), std::string("TEST"), false), 0);

		ASSERT_LT(CPPUtil::String::Strcmp(std::string("e"), std::string("f")), 0);
		ASSERT_GT(CPPUtil::String::Strcmp(std::string("f"), std::string("e")), 0);
	}

	TEST_F(String_Test, Trimleft)
	{
		ASSERT_EQ(CPPUtil::String::TrimLeft("Hello World"), "Hello World");
		ASSERT_EQ(CPPUtil::String::TrimLeft("\t\t  Hello World"), "Hello World");
		ASSERT_EQ(CPPUtil::String::TrimLeft("\t\t  Hello World  \t\t  "), "Hello World  \t\t  ");
		ASSERT_EQ(CPPUtil::String::TrimLeft("Hello World  \t\t  "), "Hello World  \t\t  ");
	}

	TEST_F(String_Test, TrimRight)
	{
		ASSERT_EQ(CPPUtil::String::TrimRight("Hello World"), "Hello World");
		ASSERT_EQ(CPPUtil::String::TrimRight("\t\t  Hello World"), "\t\t  Hello World");
		ASSERT_EQ(CPPUtil::String::TrimRight("\t\t  Hello World  \t\t  "), "\t\t  Hello World");
		ASSERT_EQ(CPPUtil::String::TrimRight("Hello World  \t\t  "), "Hello World");
	}

	TEST_F(String_Test, Trim)
	{
		ASSERT_EQ(CPPUtil::String::Trim("Hello World"), "Hello World");
		ASSERT_EQ(CPPUtil::String::Trim("\t\t  Hello World"), "Hello World");
		ASSERT_EQ(CPPUtil::String::Trim("\t\t  Hello World  \t\t  "), "Hello World");
		ASSERT_EQ(CPPUtil::String::Trim("Hello World  \t\t  "), "Hello World");
	}

	TEST_F(String_Test, Split)
	{
		std::vector<std::string> splitString;

		splitString = CPPUtil::String::Split("", ' ', false);
		ASSERT_EQ(splitString.size(), 1);
		ASSERT_EQ(splitString[0], "");

		splitString = CPPUtil::String::Split(" ", ' ', false);
		ASSERT_EQ(splitString.size(), 2);
		ASSERT_EQ(splitString[0], "");
		ASSERT_EQ(splitString[1], "");

		splitString = CPPUtil::String::Split("  T  ", ' ', false);
		ASSERT_EQ(splitString.size(), 5);
		ASSERT_EQ(splitString[0], "");
		ASSERT_EQ(splitString[1], "");
		ASSERT_EQ(splitString[2], "T");
		ASSERT_EQ(splitString[3], "");
		ASSERT_EQ(splitString[4], "");

		splitString = CPPUtil::String::Split("Test1 Test2 Test3 ", ' ', false);
		ASSERT_EQ(splitString.size(), 4);
		ASSERT_EQ(splitString[0], "Test1");
		ASSERT_EQ(splitString[1], "Test2");
		ASSERT_EQ(splitString[2], "Test3");
		ASSERT_EQ(splitString[3], "");

		splitString = CPPUtil::String::Split("Test1     Test2  Test3  ", ' ', false);
		ASSERT_EQ(splitString.size(), 10);
		ASSERT_EQ(splitString[0], "Test1");
		ASSERT_EQ(splitString[1], "");
		ASSERT_EQ(splitString[2], "");
		ASSERT_EQ(splitString[3], "");
		ASSERT_EQ(splitString[4], "");
		ASSERT_EQ(splitString[5], "Test2");
		ASSERT_EQ(splitString[6], "");
		ASSERT_EQ(splitString[7], "Test3");
		ASSERT_EQ(splitString[8], "");
		ASSERT_EQ(splitString[9], "");

		splitString = CPPUtil::String::Split("Test1   e Test2  Test3  ", " e", false);
		ASSERT_EQ(splitString.size(), 13);
		ASSERT_EQ(splitString[0], "T");
		ASSERT_EQ(splitString[1], "st1");
		ASSERT_EQ(splitString[2], "");
		ASSERT_EQ(splitString[3], "");
		ASSERT_EQ(splitString[4], "");
		ASSERT_EQ(splitString[5], "");
		ASSERT_EQ(splitString[6], "T");
		ASSERT_EQ(splitString[7], "st2");
		ASSERT_EQ(splitString[8], "");
		ASSERT_EQ(splitString[9], "T");
		ASSERT_EQ(splitString[10], "st3");
		ASSERT_EQ(splitString[11], "");
		ASSERT_EQ(splitString[12], "");

		splitString = CPPUtil::String::Split("", ' ', true);
		ASSERT_EQ(splitString.size(), 1);
		ASSERT_EQ(splitString[0], "");

		splitString = CPPUtil::String::Split(" ", ' ', true);
		ASSERT_EQ(splitString.size(), 2);
		ASSERT_EQ(splitString[0], "");
		ASSERT_EQ(splitString[1], "");

		splitString = CPPUtil::String::Split("  T  ", ' ', true);
		ASSERT_EQ(splitString.size(), 3);
		ASSERT_EQ(splitString[0], "");
		ASSERT_EQ(splitString[1], "T");
		ASSERT_EQ(splitString[2], "");

		splitString = CPPUtil::String::Split("Test1 Test2 Test3 ", ' ', true);
		ASSERT_EQ(splitString.size(), 4);
		ASSERT_EQ(splitString[0], "Test1");
		ASSERT_EQ(splitString[1], "Test2");
		ASSERT_EQ(splitString[2], "Test3");
		ASSERT_EQ(splitString[3], "");

		splitString = CPPUtil::String::Split("Test1     Test2  Test3  ", ' ', true);
		ASSERT_EQ(splitString.size(), 4);
		ASSERT_EQ(splitString[0], "Test1");
		ASSERT_EQ(splitString[1], "Test2");
		ASSERT_EQ(splitString[2], "Test3");
		ASSERT_EQ(splitString[3], "");

		splitString = CPPUtil::String::Split("Test1   e Test2  Test3  ", " e", true);
		ASSERT_EQ(splitString.size(), 7);
		ASSERT_EQ(splitString[0], "T");
		ASSERT_EQ(splitString[1], "st1");
		ASSERT_EQ(splitString[2], "T");
		ASSERT_EQ(splitString[3], "st2");
		ASSERT_EQ(splitString[4], "T");
		ASSERT_EQ(splitString[5], "st3");
		ASSERT_EQ(splitString[6], "");
	}

	TEST_F(String_Test, IsIntegerInt)
	{
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>("132453"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>("+132453"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>("-132453"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>("-0"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>(std::to_string(std::numeric_limits<int>::max())));
		ASSERT_TRUE(CPPUtil::String::IsInteger<int>(std::string("0") + std::to_string(std::numeric_limits<int>::max())));

		ASSERT_FALSE(CPPUtil::String::IsInteger<int>(""));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("3.1415"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("3."));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("+-3"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("-"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("."));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>("This is not an integer"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>((std::to_string(std::numeric_limits<int>::max()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>((std::to_string(std::numeric_limits<int>::min()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
	}

	TEST_F(String_Test, IsIntegerUnsignedInt)
	{
		ASSERT_TRUE(CPPUtil::String::IsInteger<unsigned int>("132453"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<unsigned int>("+132453"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<unsigned int>("0"));
		ASSERT_TRUE(CPPUtil::String::IsInteger<unsigned int>(std::to_string(std::numeric_limits<unsigned int>::max())));
		ASSERT_TRUE(CPPUtil::String::IsInteger<unsigned int>(std::string("0") + std::to_string(std::numeric_limits<unsigned int>::max())));

		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>(""));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("-132453"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("3.1415"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("3."));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("-3"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("-"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("."));
		ASSERT_FALSE(CPPUtil::String::IsInteger<unsigned int>("This is not an integer"));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::max()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
		ASSERT_FALSE(CPPUtil::String::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::min()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
	}

	TEST_F(String_Test, IsFloat)
	{
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("132453"));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("3.1415"));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("3."));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint(".0"));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("-132453"));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("-3.1415"));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("-3."));
		ASSERT_TRUE(CPPUtil::String::IsFloatingPoint("-.0"));

		ASSERT_FALSE(CPPUtil::String::IsFloatingPoint("+-3"));
		ASSERT_FALSE(CPPUtil::String::IsFloatingPoint("-"));
		ASSERT_FALSE(CPPUtil::String::IsFloatingPoint("."));
		ASSERT_FALSE(CPPUtil::String::IsFloatingPoint("3.14.15"));
		ASSERT_FALSE(CPPUtil::String::IsFloatingPoint("This is not an float"));
	}
}