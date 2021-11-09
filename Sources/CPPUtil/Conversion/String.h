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
			/// Converts a C++ string to a float.
			/// </summary>
			/// <param name="str">The C++ string to convert. This C++ string must represent a valid float.</param>
			/// <returns>The converted float.</returns>
			float ToFloat(const std::string str);

			/// <summary>
			/// Converts a C++ string to a double.
			/// </summary>
			/// <param name="str">The C++ string to convert. This C++ string must represent a valid float.</param>
			/// <returns>The converted double.</returns>
			double ToDouble(const std::string str);
		}
	}
}