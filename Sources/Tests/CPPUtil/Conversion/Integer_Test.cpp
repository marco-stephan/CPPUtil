#include <gtest/gtest.h>

#include <tuple>
#include "CPPUtil/Conversion/Integer.h"

namespace CPPUtil_Test
{
	namespace Conversion_Tests
	{
		class Conversion_Integer_Test : public ::testing::Test
		{
		protected:

			const std::vector<std::tuple<const char*, const int>> STRING_INT_PAIRS = {
				{"3", 3},
				{"17738", 17738},
				{"0", 0},
				{"-7", -7},
				{"-71084", -71084}
			};

			const std::vector<std::tuple<const char*, const unsigned int>> STRING_UNSIGNED_INT_PAIRS = {
				{"3", 3},
				{"17738", 17738},
				{"0", 0}
			};

		public:

			virtual void SetUp() override
			{
			}

			virtual void TearDown() override
			{
			}
		};

		TEST_F(Conversion_Integer_Test, ToBool)
		{
			ASSERT_TRUE(CPPUtil::Conversion::Integer::ToBool(1));
			ASSERT_TRUE(CPPUtil::Conversion::Integer::ToBool(7));
			ASSERT_TRUE(CPPUtil::Conversion::Integer::ToBool(-7));

			ASSERT_FALSE(CPPUtil::Conversion::Integer::ToBool(0));
		}

		TEST_F(Conversion_Integer_Test, ToCStringInt)
		{
			for (size_t i = 0; i < STRING_INT_PAIRS.size(); i++)
			{
				const char* stringValue = std::get<0>(STRING_INT_PAIRS[i]);
				const int intValue = std::get<1>(STRING_INT_PAIRS[i]);

				const char* string = CPPUtil::Conversion::Integer::ToCString(intValue);

				ASSERT_STREQ(string, stringValue) << "Index: " << i;

				delete[] string;
			}
		}

		TEST_F(Conversion_Integer_Test, ToCStringUnsignedInt)
		{
			for (size_t i = 0; i < STRING_UNSIGNED_INT_PAIRS.size(); i++)
			{
				const char* stringValue = std::get<0>(STRING_UNSIGNED_INT_PAIRS[i]);
				const unsigned int unsignedIntValue = std::get<1>(STRING_UNSIGNED_INT_PAIRS[i]);

				const char* string = CPPUtil::Conversion::Integer::ToCString(unsignedIntValue);

				ASSERT_STREQ(string, stringValue) << "Index: " << i;

				delete[] string;
			}
		}
	}
}