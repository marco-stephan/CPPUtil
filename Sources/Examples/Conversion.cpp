#include <CPPUtil/Conversion/Boolean.h>
#include <CPPUtil/Conversion/CString.h>
#include <CPPUtil/Conversion/Integer.h>
#include <CPPUtil/Conversion/String.h>

int main(int argc, char* argv[])
{
	const char* cString;
	wchar_t* wString;
	bool boolean;
	int integer;
	float floating;

	// Boolean -> CString
	cString = CPPUtil::Conversion::Boolean::ToCString(true); // cString = "true"
	cString = CPPUtil::Conversion::Boolean::ToCString(false); // cString = "false"

	// Boolean -> Integer
	integer = CPPUtil::Conversion::Boolean::ToInt(true); // integer = 1
	integer = CPPUtil::Conversion::Boolean::ToInt(false); // integer = 0

	// CString -> Integer
	integer = CPPUtil::Conversion::CString::ToInteger<int>("123"); // integer = 123
	integer = CPPUtil::Conversion::CString::ToInteger<int>("-42"); // integer = -42

	// CString -> Floating Point
	floating = CPPUtil::Conversion::CString::ToFloatingPoint<float>("123.74"); // floating = 123.74f
	floating = CPPUtil::Conversion::CString::ToFloatingPoint<float>("-42.1"); // floating = -42.1f

	// CString -> Wide string
	wString = CPPUtil::Conversion::CString::ToWideCString("Hello World!"); // wString = L"Hello World!"

	// Integer -> Boolean
	boolean = CPPUtil::Conversion::Integer::ToBool(0); // boolean = false
	boolean = CPPUtil::Conversion::Integer::ToBool(1); // boolean = true
	boolean = CPPUtil::Conversion::Integer::ToBool(42); // boolean = true

	// Integer -> CString
	cString = CPPUtil::Conversion::Integer::ToCString(0); // cString = "0"
	delete[] cString;
	cString = CPPUtil::Conversion::Integer::ToCString(-42); // cString = "-42"
	delete[] cString;

	// String -> Integer
	integer = CPPUtil::Conversion::String::ToInteger<int>(std::string("123")); // integer = 123
	integer = CPPUtil::Conversion::String::ToInteger<int>(std::string("-42")); // integer = -42

	// String -> Floating Point
	floating = CPPUtil::Conversion::String::ToFloatingPoint<float>(std::string("123.74")); // floating = 123.74f
	floating = CPPUtil::Conversion::String::ToFloatingPoint<float>(std::string("-42.1")); // floating = -42.1f

	return 0;
}