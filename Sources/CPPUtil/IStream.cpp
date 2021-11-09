#include "IStream.h"

#include <string>

std::istream& CPPUtil::IStream::GetLine(std::istream& inputStream, std::string& line, bool platformIndependentLineEndings)
{
	if (!platformIndependentLineEndings)
	{
		// Just use default getline function
		return std::getline(inputStream, line);
	}

	// Line endings are to be handled platform independently
	// State of the input stream
	std::ios_base::iostate inputStreamState = std::ios::goodbit;

	// Whether the input stream changed in any way
	bool inputStreamChanged = false;

	// Create sentry of input stream
	std::istream::sentry sentry(inputStream, true);

	// Check if valid sentry
	if (sentry)
	{
		// Clear line string
		line.clear();

		// Read using a stream buffer object
		std::streambuf* streamBuffer = inputStream.rdbuf();

		// Read characters
		while (true)
		{
			try
			{
				int readCharacter = streamBuffer->sbumpc();

				if (std::streambuf::traits_type::eq_int_type(readCharacter, std::streambuf::traits_type::eof()))
				{
					// EOF reached
					inputStreamState |= std::ios::eofbit;

					break;
				}
				else
				{
					bool carriageReturn = std::streambuf::traits_type::eq_int_type(readCharacter, std::streambuf::traits_type::to_int_type('\r'));
					bool lineFeed = std::streambuf::traits_type::eq_int_type(readCharacter, std::streambuf::traits_type::to_int_type('\n'));

					if (carriageReturn || lineFeed)
					{
						// EOL reached
						inputStreamChanged = true;

						// Check if next character belongs to the EOL
						// If so, skip it
						if (carriageReturn && std::streambuf::traits_type::eq_int_type(streamBuffer->sgetc(), std::streambuf::traits_type::to_int_type('\n')))
						{
							streamBuffer->sbumpc();
						}

						break;
					}
					else if (line.max_size() <= line.size())
					{
						// Maximum size of the line reached
						// Cannot add any more characters
						inputStreamState |= std::ios::failbit;

						break;
					}
					else
					{
						// Add character
						line += std::streambuf::traits_type::to_char_type(readCharacter);
						inputStreamChanged = true;
					}
				}
			}
			catch (...)
			{
				inputStream.setstate(std::ios::badbit);
				throw;
			}
		}
	}

	if (!inputStreamChanged)
	{
		inputStreamState |= std::ios::failbit;
	}

	// Set state
	inputStream.setstate(inputStreamState);

	return inputStream;
}