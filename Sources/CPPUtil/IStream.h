#pragma once

#include <istream>
#include <string>

namespace CPPUtil
{
	/// <summary>
	/// A namespace containing input stream utilities.
	/// </summary>
	namespace IStream
	{
		/// <summary>
		/// Reads a single line from an input stream
		/// </summary>
		/// <param name="inputStream">Input file to read from</param>
		/// <param name="line">Read line</param>
		/// <param name="platformIndependentLineEndings">True if the line endings are to be handled platform independently, false if the platform's line endings are expected</param>
		/// <returns>Input stream</returns>
		std::istream& GetLine(std::istream& inputStream, std::string& line, bool platformIndependentLineEndings);
	}
}