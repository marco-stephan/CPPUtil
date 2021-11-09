#include "String.h"

int CPPUtil::String::Strcmp(const std::string str1, const std::string str2, bool caseSensitive)
{
	return CString::Strcmp(str1.c_str(), str2.c_str(), caseSensitive);
}

int CPPUtil::String::Strcmp(const char* str1, const std::string str2, bool caseSensitive)
{
	return CString::Strcmp(str1, str2.c_str(), caseSensitive);
}

int CPPUtil::String::Strcmp(const std::string str1, const char* str2, bool caseSensitive)
{
	return CString::Strcmp(str1.c_str(), str2, caseSensitive);
}

std::string CPPUtil::String::TrimLeft(const std::string str)
{
	size_t firstNonWhitespacePosition = str.find_first_not_of(CString::WHITESPACE_CHARACTERS);

	if (firstNonWhitespacePosition == std::string::npos)
	{
		// str is either empty or only contains whitespaces
		return std::string("");
	}

	return str.substr(firstNonWhitespacePosition, std::string::npos);
}

std::string CPPUtil::String::TrimRight(const std::string str)
{
	size_t lastNonWhitespacePosition = str.find_last_not_of(CString::WHITESPACE_CHARACTERS);

	if (lastNonWhitespacePosition == std::string::npos)
	{
		// str is either empty or only contains whitespaces
		return std::string("");
	}

	return str.substr(0, lastNonWhitespacePosition + 1);
}

std::string CPPUtil::String::Trim(const std::string str)
{
	return TrimLeft(TrimRight(str));
}

std::vector<std::string> CPPUtil::String::Split(const std::string string, const char* delimiterCharaters, bool combineSuccessiveDelimiters)
{
	std::vector<std::string> result;

	// Split the string
	size_t stringIndex = 0;

	do
	{
		size_t delimiterIndex = string.find_first_of(delimiterCharaters, stringIndex);

		// Check if end has been reached
		if (delimiterIndex == std::string::npos)
		{
			result.push_back(string.substr(stringIndex));
			break;
		}

		result.push_back(string.substr(stringIndex, delimiterIndex - stringIndex));

		if (combineSuccessiveDelimiters)
		{
			stringIndex = string.find_first_not_of(delimiterCharaters, delimiterIndex);

			// Check if there are any characters left
			if (stringIndex == std::string::npos)
			{
				// Append the empty string
				result.push_back(std::string(""));
				break;
			}
		}
		else
		{
			stringIndex = delimiterIndex + 1;
		}
	}
	while (true);

	return result;
}

bool CPPUtil::String::IsFloatingPoint(const std::string str)
{
	return CString::IsFloatingPoint(str.c_str());
}