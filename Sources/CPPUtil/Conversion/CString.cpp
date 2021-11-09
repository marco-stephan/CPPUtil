#include "CString.h"

#include <stdlib.h>
#include <string>
#include "CPPUtil/CString.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // defined(_WIN32)

float CPPUtil::Conversion::CString::ToFloat(const char* str)
{
	return std::stof(str);
}

double CPPUtil::Conversion::CString::ToDouble(const char* str)
{
	return std::stod(str);
}

wchar_t* CPPUtil::Conversion::CString::ToWideCString(const char* str)
{
	// Get the length of the resulting wchar array
	size_t lengthOfResult = CPPUtil::CString::Strlen(str) + 1;

	// Create the array and copy data into it
	wchar_t* result = new wchar_t[lengthOfResult];

#if defined(_WIN32)
	MultiByteToWideChar(0, 0, str, -1, result, static_cast<int>(lengthOfResult));
#elif defined(__linux__)
	mbstowcs(result, str, lengthOfResult);
#endif // defined(__linux__)

	return result;
}