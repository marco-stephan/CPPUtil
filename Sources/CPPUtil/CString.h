#pragma once

#include <cctype>
#include <stddef.h>
#include <vector>
#include "Conversion/Integer.h"
#include "Math/Basics.h"

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing C string utilities.
	/// </summary>
	namespace CString
	{
		// C string containg all charaters that are considered whitespace
		constexpr static const char* WHITESPACE_CHARACTERS = " \t\n\v\f\r";

		/// <summary>
		/// Compares two C strings.
		/// </summary>
		/// <param name="str1">The first C string.</param>
		/// <param name="str2">The second C string.</param>
		/// <param name="caseSensitive">True if lower and upper case are to be differentiated; False otherwise</param>
		/// <returns>
		/// 0.. Both C strings are equal<para/>
		/// &lt;0.. The first character that does not match has a lower value in str1 than in str2<para/>
		/// &gt;0.. The first character that does not match has a higher value in str1 than in str2
		/// </returns>
		int Strcmp(const char* str1, const char* str2, bool caseSensitive = true);

		/// <summary>
		/// Calculates the length of the given C string excluding the termination character.
		/// </summary>
		/// <param name="str">The C string.</param>
		/// <returns>The length of the C string excluding the termination sign.</returns>
		size_t Strlen(const char* str);

		/// <summary>
		/// Concatenates an arbitrary number of C strings.
		/// </summary>
		/// <param name="strings">Vector containing all C strings to concatenate</param>
		/// <returns>
		/// A C string containing all given strings in succession. An empty C string if the vector did not contain any strings.
		/// The C string is dynamically allocated and must be freed using delete[]. NULL if str is NULL.
		/// </returns>
		char* Strcat(const std::vector<const char*>& strings);

		/// <summary>
		/// Copies the content of a C string.
		/// </summary>
		/// <param name="str">The C string to copy the content from. May be NULL</param>
		/// <returns>A copy of the C string. The C string is dynamically allocated and must be freed using delete[]. NULL if str is NULL.</returns>
		char* Strcpy(const char* str);

		/// <summary>
		/// Creates a copy substring of a C string with the given length.
		/// </summary>
		/// <param name="str">The C string to copy the substring from. May be NULL</param>
		/// <param name="length">The length of the substring. If str is NULL, this value is ignored</param>
		/// <returns>A copy of the substring. The C string is dynamically allocated and must be freed using delete[]. NULL if str is NULL.</returns>
		char* Strcpy(const char* str, size_t length);

		/// <summary>
		/// Find the position of the first occurrence of a substring in a string.
		/// </summary>
		/// <param name="string">The string to search in</param>
		/// <param name="substring">The substring to search for.</param>
		/// <param name="index">The starting position of the substring. Only set if substring was found. May be NULL</param>
		/// <returns>True if the substring was found; False otherwise</returns>
		bool Strpos(const char* string, const char* substring, size_t* index);

		/// <summary>
		/// Calculates the Levenshtein distance between the given strings
		/// </summary>
		/// <param name="str1">First string</param>
		/// <param name="str2">Second string</param>
		/// <param name="caseSensitive">True if lower and upper case are to be differentiated; False otherwise</param>
		/// <returns>Levenshtein distance between both strings.</returns>
		size_t Levenshtein(const char* str1, const char* str2, bool caseSensitive = true);

		/// <summary>
		/// Reads a file and returns its content as a C string
		/// </summary>
		/// <param name="filePath">Path to the file to read the content from</param>
		/// <returns>Content of the file. The C string is dynamically allocated and must be freed using delete[]. NULL if the file could not be opened.</returns>
		char* ReadFile(const char* filePath);

		/// <summary>
		/// Returns the current time stamp in the specified format as a C string
		/// </summary>
		/// <param name="timeStampFormat">Format of the time stamp as a C string. See https://en.cppreference.com/w/cpp/io/manip/put_time </param>
		/// <returns>The time stamp. The C string is dynamically allocated and must be freed using delete[].</returns>
		char* TimeStamp(const char* timeStampFormat);

		/// <summary>
		/// Checks if the given string is an integer.
		/// This consists of a check of the correct string format as well as a boundary check
		/// </summary>
		/// <typeparam name="Type">Integer type</typeparam>
		/// <param name="str">The string to check</param>
		/// <returns>True if the string is an integer; False otherwise.</returns>
		template<typename Type>
		bool IsInteger(const char* str)
		{
			size_t strLength = Strlen(str);

			// Check for an empty string
			if (strLength == 0)
			{
				return false;
			}

			bool hasSign = false;
			bool positive = true;

			// Account for a possible sign
			if (str[0] == '+' || str[0] == '-')
			{
				hasSign = true;

				if (str[0] == '-')
				{
					positive = false;
				}

				if constexpr (std::is_unsigned_v<Type>)
				{
					if (positive == false)
					{
						// Negative sign but unsigned type
						return false;
					}
				}
			}

			// Determine boundary to use
			const char* boundaryString = Conversion::Integer::ToCString(positive ? std::numeric_limits<Type>::max() : std::numeric_limits<Type>::min());
			const char* unsignedBoundaryString = (boundaryString[0] != '-' ? boundaryString : &boundaryString[1]);
			size_t unsignedBoundaryStringLength = Strlen(unsignedBoundaryString);

			// Remove sign from str
			const char* unsignedStr = (!hasSign ? str : &str[1]);
			size_t unsignedStrLength = (!hasSign ? strLength : strLength - 1);

			// Check if boundary exceeded for sure
			bool isInteger = unsignedStrLength > 0 && (unsignedStrLength <= unsignedBoundaryStringLength);

			if (isInteger)
			{
				// Holds whether the boundary may still be exceeded
				bool boundaryPotentiallyExceeded = (unsignedStrLength == unsignedBoundaryStringLength);

				// Handle all characters beyong sign
				for (size_t i = 0; i < unsignedStrLength; i++)
				{
					const char& unsignedStrChar = unsignedStr[i];

					// Character must be digit
					if (!isdigit(unsignedStrChar))
					{
						// No integer
						isInteger = false;
						break;
					}

					// Boundary check
					if (boundaryPotentiallyExceeded)
					{
						const char& unsignedBoundaryStringChar = unsignedBoundaryString[i];

						// String > boundary
						if (unsignedBoundaryStringChar < unsignedStrChar)
						{
							// No integer
							isInteger = false;
							break;
						}

						// Boundary > String
						if (unsignedBoundaryStringChar > unsignedStrChar)
						{
							boundaryPotentiallyExceeded = false;
						}
					}
				}
			}

			delete[] boundaryString;

			return isInteger;
		}

		/// <summary>
		/// Checks if the given C string is a floating point number.
		/// </summary>
		/// <param name="str">The C string to check</param>
		/// <returns>True if the C string is a floating point number; False otherwise.</returns>
		bool IsFloatingPoint(const char* str);
	}
}