#pragma once

#include <cstddef>
#include <string>
#include <type_traits>
#include "CPPUtil/Conversion/Boolean.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities to convert between datatypes.
	/// </summary>
	namespace Conversion
	{
		/// <summary>
		/// Contains functions to convert C strings.
		/// </summary>
		namespace CString
		{
			/// <summary>
			/// Converts a C string to a value of an arbitrary integer type (target type)
			/// </summary>
			/// <typeparam name="TargetType">The type of the converted value</typeparam>
			/// <param name="str">The C string to convert. This C string must represent a valid value of the target type.</param>
			/// <returns>The converted target type value.</returns>
			template<typename TargetType>
			TargetType ToInteger(const char* str)
			{
				TargetType result = 0;
				size_t index = 0;

				bool positive = true;

				// Account for a possible sign
				if (str[0] == '+' || str[0] == '-')
				{
					if constexpr (std::is_signed_v<TargetType>)
					{
						if (str[0] == '-')
						{
							positive = false;
						}
					}

					index++;
				}

				// Handle all digits
				while (str[index])
				{
					result = static_cast<TargetType>(static_cast<TargetType>(result * static_cast<TargetType>(10)) + (2 * CPPUtil::Conversion::Boolean::ToInt(positive) - 1) * static_cast<TargetType>(str[index] - '0'));

					index++;
				}

				return result;
			}

			/// <summary>
			/// Converts a C string to a floating point number.
			/// </summary>
			/// <typeparam name="T">Type of the floating point number</typeparam>
			/// <param name="str">The C string to convert. This C string must represent a valid floating point number.</param>
			/// <returns>The converted floating point number.</returns>
			template<typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
			T ToFloatingPoint(const char* str)
			{
				if constexpr (std::is_same_v<T, float>)
				{
					return std::stof(str);
				}
				else
				{
					return std::stod(str);
				}
			}

			/// <summary>
			/// Converts a C string to a wide character C string.
			/// </summary>
			/// <param name="str">The string to convert</param>
			/// <returns>The converted wide character C string. It is dynamically allocated and must be freed using delete[].</returns>
			wchar_t* ToWideCString(const char* str);
		}
	}
}