#include <gtest/gtest.h>

#include <sstream>
#include "CPPUtil/IStream.h"

namespace CPPUtil_Test
{
	class IStream_Test : public ::testing::Test
	{
	protected:

		const std::vector<std::string> STRING_LINE_ENDINGS = {
			"\r\n", // Windows
			"\n", // UNIX
			"\r" // Mac
		};

		const std::vector<std::string> STRING_LINES = {
			"This is the initial line.",
			"Now, the second line started. The following line is empty:",
			"",
			"This right here is the last line."
		};

	public:

		virtual void SetUp() override
		{
		}

		virtual void TearDown() override
		{
		}
	};

	TEST_F(IStream_Test, GetLine)
	{
		for (auto lineEnding : STRING_LINE_ENDINGS)
		{
			// Build complete string stream
			// Note that line endings are only platform dependant for file streams
			// However, for this test, using a string stream is fine also
			std::stringstream stringStream;

			for (auto stringLine : STRING_LINES)
			{
				stringStream << stringLine << lineEnding;
			}

			// Now read all lines of the stream and expect the lines exactly (regardless of line ending)
			std::string readLine;
			size_t lineCounter = 0;

			while (CPPUtil::IStream::GetLine(stringStream, readLine, true))
			{
				ASSERT_EQ(readLine, STRING_LINES[lineCounter]) << "Line: " << lineCounter;

				lineCounter++;
			}
		}
	}
}