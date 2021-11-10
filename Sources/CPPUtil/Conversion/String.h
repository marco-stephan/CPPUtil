#pragma once

#include <string>
#include "CString.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities to convert between datatypes.
	/// </summary>
	namespace Conversion
	{
		/// <summary>
		/// Contains functions to convert C++ strings.
		/// </summary>
		namespace String
		{
			/// <summary>
			/// Converts a C++ string to a value of an arbitrary integer type (target type)
			/// </summary>
			/// <typeparam name="TargetType">The type of the converted value</typeparam>
			/// <param name="str">The C++ string to convert. This C++ string must represent a valid value of the target type.</param>
			/// <returns>The converted target type value.</returns>
			template<typename TargetType>
			TargetType ToInteger(const std::string str)
			{
				return CString::ToInteger<TargetType>(str.c_str());
			}

			/// <summary>
			/// Converts a C++ string to a floating point number.
			/// </summary>
			/// <typeparam name="T">Type of the floating point number</typeparam>
			/// <param name="str">The C++ string to convert. This C++ string must represent a valid floating point number.</param>
			/// <returns>The converted floating point number.</returns>
			template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
			T ToFloatingPoint(const std::string str)
			{
				return CString::ToFloatingPoint<T>(str.c_str());
			}
		}
	}
}