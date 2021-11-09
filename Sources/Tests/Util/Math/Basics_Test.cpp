#include <gtest/gtest.h>

#include "Util/Math/Basics.h"

namespace Util_Tests
{
	namespace Math_Tests
	{
		class Math_Basics_Test : public ::testing::Test
		{
		public:

			virtual void SetUp() override
			{
			}

			virtual void TearDown() override
			{
			}
		};

		TEST_F(Math_Basics_Test, Abs)
		{
			ASSERT_EQ(Util::Math::Basics::Abs(7), 7);
			ASSERT_EQ(Util::Math::Basics::Abs(0), 0);
			ASSERT_DOUBLE_EQ(Util::Math::Basics::Abs(3.14), 3.14);
			ASSERT_DOUBLE_EQ(Util::Math::Basics::Abs(-3.14), 3.14);
			ASSERT_EQ(Util::Math::Basics::Abs(-984), 984);
		}

		TEST_F(Math_Basics_Test, NumberOfDigits)
		{
			ASSERT_EQ(Util::Math::Basics::NumberOfDigits(0), 1);
			ASSERT_EQ(Util::Math::Basics::NumberOfDigits(-0), 1);
			ASSERT_EQ(Util::Math::Basics::NumberOfDigits(1234), 4);
			ASSERT_EQ(Util::Math::Basics::NumberOfDigits(-1234), 4);
			ASSERT_EQ(Util::Math::Basics::NumberOfDigits(10), 2);
		}

		TEST_F(Math_Basics_Test, InRange)
		{
			ASSERT_TRUE(Util::Math::Basics::InRange(0, -1, 1));
			ASSERT_TRUE(Util::Math::Basics::InRange(0.0f, -1.0f, 1.0f));
			ASSERT_TRUE(Util::Math::Basics::InRange(5.0f, 5.0f, 10.0f));

			ASSERT_FALSE(Util::Math::Basics::InRange(-5.0f, 5.0f, 10.0f));
			ASSERT_FALSE(Util::Math::Basics::InRange(0.0f, 5.0f, 10.0f));
			ASSERT_FALSE(Util::Math::Basics::InRange(0, 2, 4));
		}

		TEST_F(Math_Basics_Test, Pow)
		{
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow(2.0f, 4.0f), 16.0f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow(2.0f, 0.0f), 1.0f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow(2.0f, -1.0f), 0.5f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow(-3.0f, 2.0f), 9.0f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow(-3.0f, 3.0f), -27.0f);

			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow<2>(2.0f), 4.0f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Pow<-2>(2.0f), 0.25f);
		}

		TEST_F(Math_Basics_Test, Root)
		{
			ASSERT_FLOAT_EQ(Util::Math::Basics::Root<2>(4.0f), 2.0f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Root<-2>(4.0f), 0.5f);
			ASSERT_FLOAT_EQ(Util::Math::Basics::Root<3>(27.0f), 3.0f);
		}
	}
}