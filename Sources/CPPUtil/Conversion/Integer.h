#pragma once

#include "CPPUtil/Math/Basics.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities to convert between datatypes.
	/// </summary>
	namespace Conversion
	{
		/// <summary>
		/// Contains functions to convert integers.
		/// </summary>
		namespace Integer
		{
			/// <summary>
			/// Converts an integer to a boolean
			/// </summary>
			/// <typeparam name="Type">Integer type</typeparam>
			/// <param name="integer">The integer to convert.</param>
			/// <returns>True if integer is non-zero; False otherwise</returns>
			template<typename Type>
			bool ToBool(Type integer)
			{
				return static_cast<bool>(integer);
			}

			/// <summary>
			/// Converts an integer to a C string
			/// </summary>
			/// <typeparam name="Type">Integer type</typeparam>
			/// <param name="integer">The integer to convert.</param>
			/// <returns>The converted C string. It is dynamically allocated and must be freed using delete[].</returns>
			template<typename Type>
			const char* ToCString(const Type integer)
			{
				size_t stringLength = (integer < 0 ? 1 : 0) + Math::Basics::NumberOfDigits(integer);
				char* string = new char[stringLength + 1];

				Type integerCopy = Math::Basics::Abs(integer);
				size_t stringIndex = stringLength;

				string[stringIndex] = '\0';

				// Iterate backwards over string as the last number is easier to determine than the first one
				do
				{
					stringIndex--;

					// Check if negative sign shall be added
					if (stringIndex == 0 && integer < 0)
					{
						string[stringIndex] = '-';
					}
					else
					{
						Type lastDigit = integerCopy % 10;

						if constexpr (std::is_signed_v<Type>)
						{
							if (lastDigit < 0)
							{
								lastDigit = -lastDigit;
							}
						}
						string[stringIndex] = '0' + lastDigit;
						integerCopy /= 10;
					}
				}
				while (stringIndex != 0);

				return string;
			}
		}
	}
}