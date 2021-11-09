#include <gtest/gtest.h>

#include <tuple>
#include "CPPUtil/Conversion/String.h"

namespace CPPUtil_Test
{
	namespace Conversion_Tests
	{
		class Conversion_String_Test : public ::testing::Test
		{
		protected:

			const std::vector<std::tuple<const int, const std::string>> INT_STRING_PAIRS = {
				{3, "3"},
				{17738, "17738"},
				{0, "0"},
				{-7, "-7"},
				{-71084, "-71084"}
			};

			const std::vector<std::tuple<const unsigned int, const std::string>> UNSIGNED_INT_STRING_PAIRS = {
				{3, "3"},
				{17738, "17738"},
				{0, "0"}
			};

			const std::vector<std::tuple<const float, const std::string>> FLOAT_STRING_PAIRS = {
				{3.1f, "3.1"},
				{300000000000.1f, "300000000000.1"},
				{-3.1f, "-3.1"}
			};

			const std::vector<std::tuple<const double, const std::string>> DOUBLE_STRING_PAIRS = {
				{3.1, "3.1"},
				{300000000000.1, "300000000000.1"},
				{-3.1, "-3.1"}
			};

			const std::vector<std::tuple<const wchar_t*, const std::string>> WSTRING_STRING_PAIRS = {
				{L"", ""},
				{L"Test", "Test"},
				{L"Test with spaces", "Test with spaces"}
			};

		public:

			virtual void SetUp() override
			{
			}

			virtual void TearDown() override
			{
			}
		};

		TEST_F(Conversion_String_Test, ToSignedInt)
		{
			for (size_t i = 0; i < INT_STRING_PAIRS.size(); i++)
			{
				const int& intValue = std::get<0>(INT_STRING_PAIRS[i]);
				const std::string& stringValue = std::get<1>(INT_STRING_PAIRS[i]);

				ASSERT_EQ(CPPUtil::Conversion::String::ToInteger<int>(stringValue), intValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_String_Test, ToUnsignedInt)
		{
			for (size_t i = 0; i < UNSIGNED_INT_STRING_PAIRS.size(); i++)
			{
				const unsigned int& unsignedIntValue = std::get<0>(UNSIGNED_INT_STRING_PAIRS[i]);
				const std::string& stringValue = std::get<1>(UNSIGNED_INT_STRING_PAIRS[i]);

				ASSERT_EQ(CPPUtil::Conversion::String::ToInteger<unsigned int>(stringValue), unsignedIntValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_String_Test, ToFloat)
		{
			for (size_t i = 0; i < FLOAT_STRING_PAIRS.size(); i++)
			{
				const float& floatValue = std::get<0>(FLOAT_STRING_PAIRS[i]);
				const std::string& stringValue = std::get<1>(FLOAT_STRING_PAIRS[i]);

				ASSERT_FLOAT_EQ(CPPUtil::Conversion::String::ToFloat(stringValue), floatValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_String_Test, ToDouble)
		{
			for (size_t i = 0; i < DOUBLE_STRING_PAIRS.size(); i++)
			{
				const double& doubleValue = std::get<0>(DOUBLE_STRING_PAIRS[i]);
				const std::string& stringValue = std::get<1>(DOUBLE_STRING_PAIRS[i]);

				ASSERT_DOUBLE_EQ(CPPUtil::Conversion::String::ToDouble(stringValue), doubleValue) << "Index: " << i;
			}
		}
	}
}