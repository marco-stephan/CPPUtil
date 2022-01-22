#include <gtest/gtest.h>

#include "CPPUtil/CString.h"

namespace CPPUtil_Test
{
	class CString_Test : public ::testing::Test
	{
	public:

		virtual void SetUp() override
		{
		}

		virtual void TearDown() override
		{
		}
	};

	TEST_F(CString_Test, Strcmp)
	{
		ASSERT_EQ(CPPUtil::CString::Strcmp("Test", "Test"), 0);

		ASSERT_NE(CPPUtil::CString::Strcmp("Test", "Not Test"), 0);
		ASSERT_NE(CPPUtil::CString::Strcmp("Test", "TEST"), 0);
		ASSERT_EQ(CPPUtil::CString::Strcmp("Test", "TEST", false), 0);

		ASSERT_LT(CPPUtil::CString::Strcmp("e", "f"), 0);
		ASSERT_GT(CPPUtil::CString::Strcmp("f", "e"), 0);
	}

	TEST_F(CString_Test, Strlen)
	{
		ASSERT_EQ(CPPUtil::CString::Strlen("a"), 1);
		ASSERT_EQ(CPPUtil::CString::Strlen("Test"), 4);
		ASSERT_EQ(CPPUtil::CString::Strlen(""), 0);
	}

	TEST_F(CString_Test, Strcat)
	{
		const char* string1 = "Hello ";
		const char* string2 = "World";
		const char* string3 = "!";
		const char* stringConcatenated = "Hello World!";

		char* concatenatedString = CPPUtil::CString::Strcat({string1, string2, string3});

		ASSERT_STREQ(concatenatedString, stringConcatenated);
		delete[] concatenatedString;
	}

	TEST_F(CString_Test, Strcpy)
	{
		const char* string = "Test";
		const char* shortenedString = "Tes";

		char* copiedString = CPPUtil::CString::Strcpy(string);

		ASSERT_STREQ(copiedString, string);
		delete[] copiedString;

		copiedString = CPPUtil::CString::Strcpy(string, 3);
		ASSERT_STREQ(copiedString, shortenedString);
		delete[] copiedString;
	}

	TEST_F(CString_Test, Strpos)
	{
		size_t substringPosition;

		ASSERT_TRUE(CPPUtil::CString::Strpos("Hello World", "Wor", &substringPosition));
		ASSERT_EQ(substringPosition, 6);

		ASSERT_FALSE(CPPUtil::CString::Strpos("Hello World", "Non-existent substring", &substringPosition));

		ASSERT_TRUE(CPPUtil::CString::Strpos("Hello World", "Hello World", &substringPosition));
		ASSERT_EQ(substringPosition, 0);

		ASSERT_TRUE(CPPUtil::CString::Strpos("Hello World", "ello", NULL));
	}

	TEST_F(CString_Test, Levenshtein)
	{
		ASSERT_EQ(CPPUtil::CString::Levenshtein("", ""), 0);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("a", ""), 1);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("", "a"), 1);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("Hello", "llo"), 2);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("Hello", "Hello"), 0);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("Hello", "HELLO"), 4);
		ASSERT_EQ(CPPUtil::CString::Levenshtein("Hello", "HELLO", false), 0);
	}

	TEST_F(CString_Test, IsIntegerInt)
	{
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>("132453"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>("+132453"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>("-132453"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>("-0"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>(std::to_string(std::numeric_limits<int>::max()).c_str()));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<int>((std::string("0") + std::to_string(std::numeric_limits<int>::max())).c_str()));

		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>(""));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("3.1415"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("3."));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("+-3"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("-"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("."));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>("This is not an integer"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>((std::to_string(std::numeric_limits<int>::max()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>((std::to_string(std::numeric_limits<int>::min()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
	}

	TEST_F(CString_Test, IsIntegerUnsignedInt)
	{
		ASSERT_TRUE(CPPUtil::CString::IsInteger<unsigned int>("132453"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<unsigned int>("+132453"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<unsigned int>("0"));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<unsigned int>(std::to_string(std::numeric_limits<unsigned int>::max()).c_str()));
		ASSERT_TRUE(CPPUtil::CString::IsInteger<unsigned int>((std::string("0") + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));

		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>(""));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("-132453"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("3.1415"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("3."));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("-3"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("-"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("."));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<unsigned int>("This is not an integer"));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::max()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
		ASSERT_FALSE(CPPUtil::CString::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::min()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
	}

	TEST_F(CString_Test, IsFloat)
	{
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("132453"));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("3.1415"));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("3."));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint(".0"));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("-132453"));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("-3.1415"));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("-3."));
		ASSERT_TRUE(CPPUtil::CString::IsFloatingPoint("-.0"));

		ASSERT_FALSE(CPPUtil::CString::IsFloatingPoint("+-3"));
		ASSERT_FALSE(CPPUtil::CString::IsFloatingPoint("-"));
		ASSERT_FALSE(CPPUtil::CString::IsFloatingPoint("."));
		ASSERT_FALSE(CPPUtil::CString::IsFloatingPoint("3.14.15"));
		ASSERT_FALSE(CPPUtil::CString::IsFloatingPoint("This is not an float"));
	}
}