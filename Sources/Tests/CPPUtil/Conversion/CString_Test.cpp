#include <gtest/gtest.h>

#include <tuple>
#include "CPPUtil/Conversion/CString.h"

namespace CPPUtil_Test
{
	namespace Conversion_Tests
	{
		class Conversion_CString_Test : public ::testing::Test
		{
		protected:

			const std::vector<std::tuple<const int, const char*>> INT_STRING_PAIRS = {
				{3, "3"},
				{17738, "17738"},
				{0, "0"},
				{-7, "-7"},
				{-71084, "-71084"}
			};

			const std::vector<std::tuple<const unsigned int, const char*>> UNSIGNED_INT_STRING_PAIRS = {
				{3, "3"},
				{17738, "17738"},
				{0, "0"}
			};

			const std::vector<std::tuple<const float, const char*>> FLOAT_STRING_PAIRS = {
				{3.1f, "3.1"},
				{300000000000.1f, "300000000000.1"},
				{-3.1f, "-3.1"}
			};

			const std::vector<std::tuple<const double, const char*>> DOUBLE_STRING_PAIRS = {
				{3.1, "3.1"},
				{300000000000.1, "300000000000.1"},
				{-3.1, "-3.1"}
			};

			const std::vector<std::tuple<const wchar_t*, const char*>> WSTRING_STRING_PAIRS = {
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

		TEST_F(Conversion_CString_Test, ToSignedInt)
		{
			for (size_t i = 0; i < INT_STRING_PAIRS.size(); i++)
			{
				const int& intValue = std::get<0>(INT_STRING_PAIRS[i]);
				const char* stringValue = std::get<1>(INT_STRING_PAIRS[i]);

				ASSERT_EQ(CPPUtil::Conversion::CString::ToInteger<int>(stringValue), intValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_CString_Test, ToUnsignedInt)
		{
			for (size_t i = 0; i < UNSIGNED_INT_STRING_PAIRS.size(); i++)
			{
				const unsigned int& unsignedIntValue = std::get<0>(UNSIGNED_INT_STRING_PAIRS[i]);
				const char* stringValue = std::get<1>(UNSIGNED_INT_STRING_PAIRS[i]);

				ASSERT_EQ(CPPUtil::Conversion::CString::ToInteger<unsigned int>(stringValue), unsignedIntValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_CString_Test, ToFloat)
		{
			for (size_t i = 0; i < FLOAT_STRING_PAIRS.size(); i++)
			{
				const float& floatValue = std::get<0>(FLOAT_STRING_PAIRS[i]);
				const char* stringValue = std::get<1>(FLOAT_STRING_PAIRS[i]);

				ASSERT_FLOAT_EQ(CPPUtil::Conversion::CString::ToFloatingPoint<float>(stringValue), floatValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_CString_Test, ToDouble)
		{
			for (size_t i = 0; i < DOUBLE_STRING_PAIRS.size(); i++)
			{
				const double& doubleValue = std::get<0>(DOUBLE_STRING_PAIRS[i]);
				const char* stringValue = std::get<1>(DOUBLE_STRING_PAIRS[i]);

				ASSERT_DOUBLE_EQ(CPPUtil::Conversion::CString::ToFloatingPoint<double>(stringValue), doubleValue) << "Index: " << i;
			}
		}

		TEST_F(Conversion_CString_Test, ToWStr)
		{
			for (size_t i = 0; i < WSTRING_STRING_PAIRS.size(); i++)
			{
				const wchar_t* wstringValue = std::get<0>(WSTRING_STRING_PAIRS[i]);
				const char* stringValue = std::get<1>(WSTRING_STRING_PAIRS[i]);

				wchar_t* wstring = CPPUtil::Conversion::CString::ToWideCString(stringValue);

				ASSERT_STREQ(wstring, wstringValue) << "Index: " << i;

				delete[] wstring;
			}
		}
	}
}