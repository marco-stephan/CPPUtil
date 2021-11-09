#include <gtest/gtest.h>

#include "Util/CString.h"

namespace Util_Tests
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
		ASSERT_EQ(Util::CString::Strcmp("Test", "Test"), 0);

		ASSERT_NE(Util::CString::Strcmp("Test", "Not Test"), 0);
		ASSERT_NE(Util::CString::Strcmp("Test", "TEST"), 0);
		ASSERT_EQ(Util::CString::Strcmp("Test", "TEST", false), 0);

		ASSERT_LT(Util::CString::Strcmp("e", "f"), 0);
		ASSERT_GT(Util::CString::Strcmp("f", "e"), 0);
	}

	TEST_F(CString_Test, Strlen)
	{
		ASSERT_EQ(Util::CString::Strlen("a"), 1);
		ASSERT_EQ(Util::CString::Strlen("Test"), 4);
		ASSERT_EQ(Util::CString::Strlen(""), 0);
	}

	TEST_F(CString_Test, Strcat)
	{
		const char* string1 = "Hello ";
		const char* string2 = "World";
		const char* string3 = "!";
		const char* stringConcatenated = "Hello World!";

		char* concatenatedString = Util::CString::Strcat({string1, string2, string3});

		ASSERT_STREQ(concatenatedString, stringConcatenated);
		delete[] concatenatedString;
	}

	TEST_F(CString_Test, Strcpy)
	{
		const char* string = "Test";
		const char* shortenedString = "Tes";

		char* copiedString = Util::CString::Strcpy(string);

		ASSERT_STREQ(copiedString, string);
		delete[] copiedString;

		copiedString = Util::CString::Strcpy(string, 3);
		ASSERT_STREQ(copiedString, shortenedString);
		delete[] copiedString;
	}

	TEST_F(CString_Test, Strpos)
	{
		size_t substringPosition;

		ASSERT_TRUE(Util::CString::Strpos("Hello World", "Wor", &substringPosition));
		ASSERT_EQ(substringPosition, 6);

		ASSERT_FALSE(Util::CString::Strpos("Hello World", "Non-existent substring", &substringPosition));

		ASSERT_TRUE(Util::CString::Strpos("Hello World", "Hello World", &substringPosition));
		ASSERT_EQ(substringPosition, 0);

		ASSERT_TRUE(Util::CString::Strpos("Hello World", "ello", NULL));
	}

	TEST_F(CString_Test, Levenshtein)
	{
		ASSERT_EQ(Util::CString::Levenshtein("", ""), 0);
		ASSERT_EQ(Util::CString::Levenshtein("a", ""), 1);
		ASSERT_EQ(Util::CString::Levenshtein("", "a"), 1);
		ASSERT_EQ(Util::CString::Levenshtein("Hello", "llo"), 2);
		ASSERT_EQ(Util::CString::Levenshtein("Hello", "Hello"), 0);
		ASSERT_EQ(Util::CString::Levenshtein("Hello", "HELLO"), 4);
		ASSERT_EQ(Util::CString::Levenshtein("Hello", "HELLO", false), 0);
	}

	TEST_F(CString_Test, IsIntegerInt)
	{
		ASSERT_TRUE(Util::CString::IsInteger<int>("132453"));
		ASSERT_TRUE(Util::CString::IsInteger<int>("-132453"));
		ASSERT_TRUE(Util::CString::IsInteger<int>("-0"));

		ASSERT_FALSE(Util::CString::IsInteger<int>("3.1415"));
		ASSERT_FALSE(Util::CString::IsInteger<int>("3."));
		ASSERT_FALSE(Util::CString::IsInteger<int>("+-3"));
		ASSERT_FALSE(Util::CString::IsInteger<int>("-"));
		ASSERT_FALSE(Util::CString::IsInteger<int>("."));
		ASSERT_FALSE(Util::CString::IsInteger<int>("This is not an integer"));
		ASSERT_FALSE(Util::CString::IsInteger<int>((std::to_string(std::numeric_limits<int>::max()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
		ASSERT_FALSE(Util::CString::IsInteger<int>((std::to_string(std::numeric_limits<int>::min()) + std::to_string(std::numeric_limits<int>::max())).c_str()));
	}

	TEST_F(CString_Test, IsIntegerUnsignedInt)
	{
		ASSERT_TRUE(Util::CString::IsInteger<unsigned int>("132453"));
		ASSERT_TRUE(Util::CString::IsInteger<unsigned int>("+132453"));
		ASSERT_TRUE(Util::CString::IsInteger<unsigned int>("0"));

		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("3.1415"));
		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("3."));
		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("-3"));
		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("-"));
		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("."));
		ASSERT_FALSE(Util::CString::IsInteger<unsigned int>("This is not an integer"));
		ASSERT_FALSE(Util::CString::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::max()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
		ASSERT_FALSE(Util::CString::IsInteger<int>((std::to_string(std::numeric_limits<unsigned int>::min()) + std::to_string(std::numeric_limits<unsigned int>::max())).c_str()));
	}

	TEST_F(CString_Test, IsFloat)
	{
		ASSERT_TRUE(Util::CString::IsFloatingPoint("132453"));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("3.1415"));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("3."));
		ASSERT_TRUE(Util::CString::IsFloatingPoint(".0"));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("-132453"));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("-3.1415"));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("-3."));
		ASSERT_TRUE(Util::CString::IsFloatingPoint("-.0"));

		ASSERT_FALSE(Util::CString::IsFloatingPoint("+-3"));
		ASSERT_FALSE(Util::CString::IsFloatingPoint("-"));
		ASSERT_FALSE(Util::CString::IsFloatingPoint("."));
		ASSERT_FALSE(Util::CString::IsFloatingPoint("3.14.15"));
		ASSERT_FALSE(Util::CString::IsFloatingPoint("This is not an float"));
	}
}
