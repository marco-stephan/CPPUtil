#include "Boolean.h"

const char* Util::Conversion::Boolean::ToCString(const bool boolean)
{
	return boolean ? "true" : "false";
}

int Util::Conversion::Boolean::ToInt(const bool boolean)
{
	return static_cast<int>(boolean);
}