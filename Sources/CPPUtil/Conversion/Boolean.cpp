#include "Boolean.h"

const char* CPPUtil::Conversion::Boolean::ToCString(const bool boolean)
{
	return boolean ? "true" : "false";
}

int CPPUtil::Conversion::Boolean::ToInt(const bool boolean)
{
	return static_cast<int>(boolean);
}