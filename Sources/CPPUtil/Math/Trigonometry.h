#pragma once

#include <cmath>
#include "Constants.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing utilities for mathematical functions.
	/// </summary>
	namespace Math
	{
		/// <summary>
		/// Contains trigonometric mathematical functions
		/// </summary>
		namespace Trigonometry
		{
			/// <summary>
			/// Converts a radians value to degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Value to convert</param>
			/// <returns>Converted value</returns>
			template<typename ValueType>
			constexpr ValueType ToDegree(ValueType radians)
			{
				return static_cast<ValueType>(radians * 180.0 / Constants::PI);
			}

			/// <summary>
			/// Converts a degree value to radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Value to convert</param>
			/// <returns>Converted value</returns>
			template<typename ValueType>
			constexpr ValueType ToRadians(ValueType degree)
			{
				return static_cast<ValueType>(degree * Constants::PI / 180.0);
			}

			/// <summary>
			/// Returns the sine of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Sine</returns>
			template<typename ValueType>
			ValueType SinRad(ValueType radians)
			{
				return sin(radians);
			}

			/// <summary>
			/// Returns the sine of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>Sine</returns>
			template<typename ValueType>
			ValueType SinDeg(ValueType degree)
			{
				return SinRad(ToRadians(degree));
			}

			/// <summary>
			/// Returns the arcus sine of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Arcus sine</returns>
			template<typename ValueType>
			ValueType ArcSinRad(ValueType radians)
			{
				return asin(radians);
			}

			/// <summary>
			/// Returns the arcus sine of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">sine</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>The type of the value</returns>
			template<typename ValueType>
			ValueType ArcSinDeg(ValueType degree)
			{
				return ToDegree(ArcSinRad(degree));
			}

			/// <summary>
			/// Returns the cosine of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Cosine</returns>
			template<typename ValueType>
			ValueType CosRad(ValueType radians)
			{
				return cos(radians);
			}

			/// <summary>
			/// Returns the cosine of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>Cosine</returns>
			template<typename ValueType>
			ValueType CosDeg(ValueType degree)
			{
				return CosRad(ToRadians(degree));
			}

			/// <summary>
			/// Returns the arcus cosine of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Arcus cosine</returns>
			template<typename ValueType>
			ValueType ArcCosRad(ValueType radians)
			{
				return acos(radians);
			}

			/// <summary>
			/// Returns the arcus cosine of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>Arcus cosine</returns>
			template<typename ValueType>
			ValueType ArcCosDeg(ValueType degree)
			{
				return ToDegree(ArcCosRad(degree));
			}

			/// <summary>
			/// Returns the tangent of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Tangent</returns>
			template<typename ValueType>
			ValueType TanRad(ValueType radians)
			{
				return tan(radians);
			}

			/// <summary>
			/// Returns the tangent of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>Tangent</returns>
			template<typename ValueType>
			ValueType TanDeg(ValueType degree)
			{
				return TanRad(ToRadians(degree));
			}

			/// <summary>
			/// Returns the arcus tangent of an angle in radians
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="radians">Angle</param>
			/// <returns>Arcus tangent</returns>
			template<typename ValueType>
			ValueType ArcTanRad(ValueType radians)
			{
				return atan(radians);
			}

			/// <summary>
			/// Returns the arcus tangent of an angle in degree
			/// </summary>
			/// <typeparam name="ValueType">The type of the value</typeparam>
			/// <param name="degree">Angle</param>
			/// <returns>Arcus tangent</returns>
			template<typename ValueType>
			ValueType ArcTanDeg(ValueType degree)
			{
				return ToDegree(ArcTanRad(degree));
			}
		}
	}
}
