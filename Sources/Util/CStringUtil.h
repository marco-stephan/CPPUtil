#pragma once

#include <stddef.h>
#include <vector>
#include <vector>

namespace Util
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
		/// Reads a file and returns its content as a C string
		/// </summary>
		/// <param name="filePath">Path to the file to read the content from</param>
		/// <returns>Content of the file. The C string is dynamically allocated and must be freed using delete[]. NULL if the file could not be opened.</returns>
		char* ReadFile(const char* filePath);

		/// <summary>
		/// Returns the current time stamp in the specified format as a C string
		/// </summary>
		/// <param name="timeStampFormat">Format of the time stamp as a C string. See https://en.cppreference.com/w/cpp/io/manip/put_time</param>
		/// <returns>The time stamp. The C string is dynamically allocated and must be freed using delete[].</returns>
		char* TimeStamp(const char* timeStampFormat);

		/// <summary>
		/// Checks if the given C string is an unsigned integer.
		/// </summary>
		/// <param name="str">The C string to check</param>
		/// <returns>True if the C string is an unsigned integer; False otherwise.</returns>
		bool IsUnsignedInteger(const char* str);

		/// <summary>
		/// Checks if the given C string is a signed integer.
		/// </summary>
		/// <param name="str">The C string to check</param>
		/// <returns>True if the C string is a signed integer; False otherwise.</returns>
		bool IsSignedInteger(const char* str);

		/// <summary>
		/// Checks if the given C string is a floating point number.
		/// </summary>
		/// <param name="str">The C string to check</param>
		/// <returns>True if the C string is a floating point number; False otherwise.</returns>
		bool IsFloatingPoint(const char* str);
}