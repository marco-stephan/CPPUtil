#include <gtest/gtest.h>

#include "Util/Conversion/Boolean.h"

namespace Util_Tests
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
			ASSERT_STREQ(Util::Conversion::Boolean::ToCString(true), "true");
			ASSERT_STREQ(Util::Conversion::Boolean::ToCString(false), "false");
		}

		TEST_F(Conversion_Boolean_Test, ToInt)
		{
			ASSERT_EQ(Util::Conversion::Boolean::ToInt(true), 1);
			ASSERT_EQ(Util::Conversion::Boolean::ToInt(false), 0);
		}
	}
}