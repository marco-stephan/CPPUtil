#pragma once

namespace Util
{
	/// <summary>
	/// A namespace containing utilities to convert between datatypes.
	/// </summary>
	namespace Conversion
	{
		/// <summary>
		/// Contains functions to convert booleans.
		/// </summary>
		namespace Boolean
		{
			/// <summary>
			/// Converts a boolean to a constant C string
			/// </summary>
			/// <param name="boolean">The boolean to convert.</param>
			/// <returns>The converted C string.</returns>
			const char* ToCString(const bool boolean);

			/// <summary>
			/// Converts a boolean to an integer
			/// </summary>
			/// <param name="boolean">The boolean to convert.</param>
			/// <returns>1 if boolean is true; 0 otherwise</returns>
			int ToInt(const bool boolean);
		}
	}
}
