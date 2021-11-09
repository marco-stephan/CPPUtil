#pragma once

#include <cmath>

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities for mathematical functions.
	/// </summary>
	namespace Math
	{
		/// <summary>
		/// Contains basic mathematical functions
		/// </summary>
		namespace Basics
		{
			/// <summary>
			/// Returns the absolute value of a given value
			/// </summary>
			/// <typeparam name="ValueType">The type of value</typeparam>
			/// <param name="value"Value to determine the absolute value from></param>
			/// <returns>Absolute value</returns>
			template<typename ValueType>
			inline ValueType Abs(ValueType value)
			{
				if constexpr (std::is_signed_v<ValueType>)
				{
					return value < 0 ? -value : value;
				}

				return value;
			}

			/// <summary>
			/// Returns the number of digits of an integer. Note that the sign is not counted.
			/// </summary>
			/// <param name="value">Value</param>
			/// <returns>The total number of digits of the given integer</returns>
			template<typename ValueType>
			size_t NumberOfDigits(ValueType value)
			{
				size_t result = 1;
				bool positive = value >= 0;

				for (ValueType valueCopy = value; (positive ? valueCopy >= 10 : valueCopy <= -10); result++)
				{
					valueCopy /= 10;
				}

				return result;
			}

			/// <summary>
			/// Returns whether a value lies inside a given range
			/// </summary>
			/// <typeparam name="ValueType">The type of value</typeparam>
			/// <param name="value">Value to check</param>
			/// <param name="lowerBoundary">Lower boundary of the range (inclusive)</param>
			/// <param name="upperBoundary">Upper boundary of the range (inclusive)</param>
			/// <returns>True if the value lies in [lowerBoundary; upperBoundary]; False otherwise</returns>
			template<typename ValueType>
			inline bool InRange(ValueType value, ValueType lowerBoundary, ValueType upperBoundary)
			{
				return value >= lowerBoundary && value <= upperBoundary;
			}

			/// <summary>
			/// Returns the value raised to a power. The exponent may be given at run-time
			/// </summary>
			/// <typeparam name="BaseType">The type of base</typeparam>
			/// <typeparam name="ExponentType">The type of exponent</typeparam>
			/// <param name="base">Base</param>
			/// <param name="exponent">Exponent</param>
			/// <returns>Base raised to the power of exponent</returns>
			template<typename BaseType, typename ExponentType>
			inline BaseType Pow(BaseType base, ExponentType exponent)
			{
				return static_cast<BaseType>(pow(base, exponent));
			}

			/// <summary>
			/// Returns the value raised to a power. The exponent must be given at compile-time
			/// </summary>
			/// <typeparam name="exponent">Exponent the base shall be raised to</typeparam>
			/// <typeparam name="BaseType">The type of base</typeparam>
			/// <param name="base">Base</param>
			/// <returns>Base raised to the power of exponent</returns>
			template<int exponent, typename BaseType>
			inline BaseType Pow(BaseType base)
			{
				if constexpr (exponent < 0)
				{
					return static_cast<BaseType>(1) / Pow<-exponent>(base);
				}
				else if constexpr (exponent == 0)
				{
					return static_cast<BaseType>(1);
				}
				else
				{
					const BaseType powHalfExponent = Pow<exponent / 2>(base);

					if (exponent & 1)
					{
						return powHalfExponent * powHalfExponent * base;
					}

					return powHalfExponent * powHalfExponent;
				}
			}

			/// <summary>
			/// Returns the degree-th root of a value. The degree must be given at compile-time
			/// </summary>
			/// <typeparam name="degree">Degree of the root. Its absolute must not be larger than 3</typeparam>
			/// <typeparam name="ValueType">The type of value</typeparam>
			/// <param name="value">Value</param>
			/// <returns>Degree-th root of value</returns>
			template<int degree, typename ValueType>
			inline ValueType Root(ValueType value)
			{
				if constexpr (degree < 0)
				{
					return static_cast<ValueType>(1) / Root<-degree>(value);
				}
				else if constexpr (degree == 1)
				{
					return value;
				}
				else if constexpr (degree == 2)
				{
					return static_cast<ValueType>(sqrt(value));
				}
				else if constexpr (degree == 3)
				{
					return static_cast<ValueType>(cbrt(value));
				}
			}
		}
	}
}
