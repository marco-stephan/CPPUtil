#include "CStringUtil.h"

#include <algorithm>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <queue>
#include <sstream>
#include <string>
#include "Utilities/IStreamUtil.h"

int Util::CString::Strcmp(const char* str1, const char* str2, bool caseSensitive)
{
	if (caseSensitive)
	{
		return strcmp(str1, str2);
	}

#if defined(_WIN32)
	return _stricmp(str1, str2);
#elif defined(__linux__)
	return strcasecmp(str1, str2);
#endif // defined(__linux__)
}

size_t Util::CString::Strlen(const char* str)
{
	return strlen(str);
}

char* Util::CString::Strcat(const std::vector<const char*>& strings)
{
	// Calculate the length of all strings
	size_t* stringLengths = new size_t[strings.size()];
	size_t combinedStringLength = 0;

	for (size_t i = 0; i < strings.size(); i++)
	{
		size_t currentStringLength = Strlen(strings[i]);

		combinedStringLength += currentStringLength;
		stringLengths[i] = currentStringLength;
	}

	// Allocate memory for the result
	char* result = new char[combinedStringLength + 1];

	// Copy all strings into the result
	size_t resultIndex = 0;

	for (size_t i = 0; i < strings.size(); i++)
	{
		memcpy(result + resultIndex, strings[i], sizeof(char) * stringLengths[i]);
		resultIndex += stringLengths[i];
	}

	delete[] stringLengths;

	// Append termination sign
	result[resultIndex] = '\0';

	return result;
}

char* Util::CString::Strcpy(const char* str)
{
	if (!str)
	{
		return NULL;
	}

	return Strcpy(str, strlen(str));
}

char* Util::CString::Strcpy(const char* str, size_t length)
{
	if (!str)
	{
		return NULL;
	}

	// Allocate memory for the new C string
	char* result = new char[length + 1];

	// Copy the content and append termination symbol
	memcpy(result, str, sizeof(char) * length);
	result[length] = '\0';

	return result;
}

char* Util::CString::ReadFile(const char* filePath)
{
	// Open file
	std::ifstream file(filePath);

	// Check if opened
	if (!file.is_open())
	{
		return nullptr;
	}

	// Contains the file's lines as dynamically allocated C strings
	std::deque<const char*> lineStrings;
	bool firstLine = true;

	// Read line by line
	std::string line;

	while (IStreamUtil::GetLine(file, line, true))
	{
		if (!firstLine)
		{
			lineStrings.push_back(Strcpy("\n"));
		}

		// Push line content to queue
		lineStrings.push_back(Strcpy(line.c_str()));

		firstLine = false;
	}

	// Create result
	char* result = Strcat({lineStrings.begin(), lineStrings.end()});

	// Deallocate line strings
	for (const char* lineString : lineStrings)
	{
		delete[] lineString;
	}

	// Return the file's content
	return result;
}

char* Util::CString::TimeStamp(const char* timeStampFormat)
{
	// Get local time
	std::tm localTime{};
	std::time_t time = std::time(0);

#ifdef _WIN32
	localtime_s(&localTime, &time);
#elif __linux__
	localtime_r(&time, &localTime);
#endif

	// Create time stamp string stream
	std::stringstream timeStampStringStream;

	timeStampStringStream << std::put_time(&localTime, timeStampFormat);

	return Strcpy(timeStampStringStream.str().c_str());
}

bool Util::CString::IsUnsignedInteger(const char* str)
{
	return IsSignedInteger(str) && str[0] != '-';
}

bool Util::CString::IsSignedInteger(const char* str)
{
	size_t strLength = Strlen(str);

	// Check for an empty string
	if (strLength == 0)
	{
		return false;
	}

	for (size_t i = 0; i < strLength; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			// Allow "+" or "-" as the first sign
			if (i != 0 || (str[i] != '+' && str[i] != '-'))
			{
				return false;
			}
		}
	}

	return true;
}

bool Util::CString::IsFloatingPoint(const char* str)
{
	size_t strLength = Strlen(str);
	bool decimalSeparatorFound = false;

	// Check for an empty C string
	if (strLength == 0)
	{
		return false;
	}

	for (size_t i = 0; i < strLength; i++)
	{
		// Check for a decimal separator
		if (str[i] == '.')
		{
			// Make sure only one separator exists
			if (decimalSeparatorFound)
			{
				return false;
			}

			decimalSeparatorFound = true;
		}
		else if (str[i] < '0' || str[i] > '9')
		{
			// Check if the first sign is "-" or "+"
			if (i != 0 || (str[i] != '-' && str[i] != '+'))
			{
				return false;
			}
		}
	}

	return true;
}