#pragma once

#include "Basics.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities for mathematical functions.
	/// </summary>
	namespace Math
	{
		/// <summary>
		/// Contains mathematical constants
		/// </summary>
		namespace Constants
		{
			// Pi
			constexpr static const double PI = 3.14159265358979323846;

			// Golden ratio (~1.618034)
			static const double GOLDEN_RATIO = (1.0 + Basics::Root<2>(5.0)) / 2.0;

			// Golden angle (~2.399963 rad)
			static const double GOLDEN_ANGLE = 2.0 * PI * (2.0 - GOLDEN_RATIO);
		}
	}
}