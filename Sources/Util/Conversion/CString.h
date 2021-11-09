#pragma once

#include <cstddef>
#include <type_traits>
#include "Util/Conversion/Boolean.h"

namespace Util
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
					result = static_cast<TargetType>(static_cast<TargetType>(result * static_cast<TargetType>(10)) + (2 * Util::Conversion::Boolean::ToInt(positive) - 1) * static_cast<TargetType>(str[index] - '0'));

					index++;
				}

				return result;
			}

			/// <summary>
			/// Converts a C string to a float.
			/// </summary>
			/// <param name="str">The C string to convert. This C string must represent a valid float.</param>
			/// <returns>The converted float.</returns>
			float ToFloat(const char* str);

			/// <summary>
			/// Converts a C string to a double.
			/// </summary>
			/// <param name="str">The C string to convert. This C string must represent a valid float.</param>
			/// <returns>The converted double.</returns>
			double ToDouble(const char* str);

			/// <summary>
			/// Converts a C string to a wide character C string.
			/// </summary>
			/// <param name="str">The string to convert</param>
			/// <returns>The converted wide character C string. It is dynamically allocated and must be freed using delete[].</returns>
			wchar_t* ToWideCString(const char* str);
		}
	}
}