#pragma once

#include <string>
#include <vector>
#include "CString.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing C++ string utilities.
	/// </summary>
	namespace String
	{
		/// <summary>
		/// Compares two strings.
		/// </summary>
		/// <param name="str1">The first string (as C++ string).</param>
		/// <param name="str2">The second string (as C++ string).</param>
		/// <param name="caseSensitive">True if lower and upper case are to be differentiated; False otherwise</param>
		/// <returns>
		/// 0.. Both C strings are equal<para/>
		/// &lt;0.. The first character that does not match has a lower value in str1 than in str2<para/>
		/// &gt;0.. The first character that does not match has a higher value in str1 than in str2
		/// </returns>
		int Strcmp(const std::string str1, const std::string str2, bool caseSensitive = true);

		/// <summary>
		/// Compares two strings.
		/// </summary>
		/// <param name="str1">The first string.</param>
		/// <param name="str2">The second string (as C++ string).</param>
		/// <param name="caseSensitive">True if lower and upper case are to be differentiated; False otherwise</param>
		/// <returns>
		/// 0.. Both C strings are equal<para/>
		/// &lt;0.. The first character that does not match has a lower value in str1 than in str2<para/>
		/// &gt;0.. The first character that does not match has a higher value in str1 than in str2
		/// </returns>
		int Strcmp(const char* str1, const std::string str2, bool caseSensitive = true);

		/// <summary>
		/// Compares two strings.
		/// </summary>
		/// <param name="str1">The first string (as C++ string).</param>
		/// <param name="str2">The second string .</param>
		/// <param name="caseSensitive">True if lower and upper case are to be differentiated; False otherwise</param>
		/// <returns>
		/// 0.. Both C strings are equal<para/>
		/// &lt;0.. The first character that does not match has a lower value in str1 than in str2<para/>
		/// &gt;0.. The first character that does not match has a higher value in str1 than in str2
		/// </returns>
		int Strcmp(const std::string str1, const char* str2, bool caseSensitive = true);

		/// <summary>
		/// Trims a C++ string at the left side, i.e. removing all whitespace on that side
		/// </summary>
		/// <param name="str">String to trim</param>
		/// <returns>Trimmed string</returns>
		std::string TrimLeft(const std::string str);

		/// <summary>
		/// Trims a C++ string at the right side, i.e. removing all whitespace on that side
		/// </summary>
		/// <param name="str">String to trim</param>
		/// <returns>Trimmed string</returns>
		std::string TrimRight(const std::string str);

		/// <summary>
		/// Trims a C++ string on both sides, i.e. removing all whitespace on these sides
		/// </summary>
		/// <param name="str">String to trim</param>
		/// <returns>Trimmed string</returns>
		std::string Trim(const std::string str);

		/// <summary>
		/// Splits a C++ string according to the delimiter characters
		/// </summary>
		/// <param name="string">C++ string to split</param>
		/// <param name="delimiterCharacters">String containing all delimiter characters</param>
		/// <param name="combineSuccessiveDelimiters">True to treat successive delimiter characters as one character; False otherwise</param>
		/// <returns>Vector containg all the split C++ strings</returns>
		std::vector<std::string> Split(const std::string string, const char* delimiterCharacters, bool combineSuccessiveDelimiters);

		/// <summary>
		/// Splits a C++ string according to the delimiter characters
		/// </summary>
		/// <param name="string">C++ string to split</param>
		/// <param name="delimiterCharacter">Delimiter character</param>
		/// <param name="combineSuccessiveDelimiters">True to treat successive delimiter characters as one character; False otherwise</param>
		/// <returns>Vector containg all the split C++ strings</returns>
		std::vector<std::string> Split(const std::string string, const char delimiterCharacter, bool combineSuccessiveDelimiters);

		/// <summary>
		/// Checks if the given C++ string is an integer.
		/// This consists of a check of the correct string format as well as a boundary check
		/// </summary>
		/// <typeparam name="Type">Integer type</typeparam>
		/// <param name="str">The C++ string to check</param>
		/// <returns>True if the C++ string is an integer; False otherwise.</returns>
		template<typename Type>
		bool IsInteger(const std::string str)
		{
			return CString::IsInteger<Type>(str.c_str());
		}

		/// <summary>
		/// Checks if the given C++ string is a floating point number.
		/// </summary>
		/// <param name="str">The C++ string to check</param>
		/// <returns>True if the C++ string is a floating point number; False otherwise.</returns>
		bool IsFloatingPoint(const std::string str);
	}
}