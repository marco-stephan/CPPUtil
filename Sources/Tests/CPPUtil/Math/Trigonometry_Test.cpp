#include <gtest/gtest.h>

#include "CPPUtil/Math/Trigonometry.h"

namespace CPPUtil_Test
{
	namespace Math_Tests
	{
		class Math_Trigonometry_Test : public ::testing::Test
		{
		protected:

			constexpr static const double DOUBLE_EQ_EPSILON = 0.00000001;

		public:

			virtual void SetUp() override
			{
			}

			virtual void TearDown() override
			{
			}
		};

		TEST_F(Math_Trigonometry_Test, ToDegree)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToDegree(0.0), 0.0);
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToDegree(2 * CPPUtil::Math::Constants::PI), 360.0);
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToDegree(-CPPUtil::Math::Constants::PI), -180.0);
		}

		TEST_F(Math_Trigonometry_Test, ToRadians)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToRadians(0.0), 0.0);
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToRadians(360.0), 2 * CPPUtil::Math::Constants::PI);
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ToRadians(-180.0), -CPPUtil::Math::Constants::PI);
		}

		TEST_F(Math_Trigonometry_Test, SinRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::SinRad(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(CPPUtil::Math::Constants::PI / 4.0), CPPUtil::Math::Basics::Root<2>(2.0) / 2.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(CPPUtil::Math::Constants::PI / 2.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(CPPUtil::Math::Constants::PI), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(3.0 * CPPUtil::Math::Constants::PI / 2.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(2.0 * CPPUtil::Math::Constants::PI), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinRad(-3.0 * CPPUtil::Math::Constants::PI / 2.0), 1.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, SinDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::SinDeg(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(45.0), CPPUtil::Math::Basics::Root<2>(2.0) / 2.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(90.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(180.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(270.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(360.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::SinDeg(-270.0), 1.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcSinRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcSinRad(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinRad(CPPUtil::Math::Basics::Root<2>(2.0) / 2.0), CPPUtil::Math::Constants::PI / 4.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinRad(1.0), CPPUtil::Math::Constants::PI / 2.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinRad(-1.0), -CPPUtil::Math::Constants::PI / 2.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcSinDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcSinDeg(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinDeg(CPPUtil::Math::Basics::Root<2>(2.0) / 2.0), 45.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinDeg(1.0), 90.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcSinDeg(-1.0), -90.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, CosRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::CosRad(0.0), 1.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(CPPUtil::Math::Constants::PI / 4.0), CPPUtil::Math::Basics::Root<2>(2.0) / 2.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(CPPUtil::Math::Constants::PI / 2.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(CPPUtil::Math::Constants::PI), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(3.0 * CPPUtil::Math::Constants::PI / 2.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(2.0 * CPPUtil::Math::Constants::PI), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosRad(-3.0 * CPPUtil::Math::Constants::PI / 2.0), 0.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, CosDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::CosDeg(0.0), 1.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(45.0), CPPUtil::Math::Basics::Root<2>(2.0) / 2.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(90.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(180.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(270.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(360.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::CosDeg(-270.0), 0.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcCosRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcCosRad(0.0), CPPUtil::Math::Constants::PI / 2.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosRad(CPPUtil::Math::Basics::Root<2>(2.0) / 2.0), CPPUtil::Math::Constants::PI / 4.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosRad(1.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosRad(-1.0), CPPUtil::Math::Constants::PI, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcCosDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcCosDeg(0.0), 90.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosDeg(CPPUtil::Math::Basics::Root<2>(2.0) / 2.0), 45.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosDeg(1.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcCosDeg(-1.0), 180.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, TanRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::TanRad(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(CPPUtil::Math::Constants::PI / 4.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(3.0 * CPPUtil::Math::Constants::PI / 4.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(CPPUtil::Math::Constants::PI), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(-CPPUtil::Math::Constants::PI / 4.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(-3.0 * CPPUtil::Math::Constants::PI / 4.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanRad(-CPPUtil::Math::Constants::PI), 0.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, TanDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::TanDeg(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(45.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(135.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(180.0), 0.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(-45.0), -1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(-135.0), 1.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::TanDeg(-180.0), 0.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcTanRad)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcTanRad(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcTanRad(1.0), CPPUtil::Math::Constants::PI / 4.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcTanRad(-1.0), -CPPUtil::Math::Constants::PI / 4.0, DOUBLE_EQ_EPSILON);
		}

		TEST_F(Math_Trigonometry_Test, ArcTanDeg)
		{
			ASSERT_DOUBLE_EQ(CPPUtil::Math::Trigonometry::ArcTanDeg(0.0), 0.0);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcTanDeg(1.0), 45.0, DOUBLE_EQ_EPSILON);
			ASSERT_NEAR(CPPUtil::Math::Trigonometry::ArcTanDeg(-1.0), -45.0, DOUBLE_EQ_EPSILON);
		}
	}
}