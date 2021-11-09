#include <gtest/gtest.h>

#include "CPPUtil/Conversion/Boolean.h"

namespace CPPUtil_Test
{
	namespace Conversion_Tests
	{
		class Conversion_Boolean_Test : public ::testing::Test
		{
		public:

			virtual void SetUp() override
			{
			}

			virtual void TearDown() override
			{
			}
		};

		TEST_F(Conversion_Boolean_Test, ToCString)
		{
			ASSERT_STREQ(CPPUtil::Conversion::Boolean::ToCString(true), "true");
			ASSERT_STREQ(CPPUtil::Conversion::Boolean::ToCString(false), "false");
		}

		TEST_F(Conversion_Boolean_Test, ToInt)
		{
			ASSERT_EQ(CPPUtil::Conversion::Boolean::ToInt(true), 1);
			ASSERT_EQ(CPPUtil::Conversion::Boolean::ToInt(false), 0);
		}
	}
}