#include "String.h"

float CPPUtil::Conversion::String::ToFloat(const std::string str)
{
	return CString::ToFloat(str.c_str());
}

double CPPUtil::Conversion::String::ToDouble(const std::string str)
{
	return CString::ToDouble(str.c_str());
}