#pragma once
#include <Windows.h>
#include <string>
#ifdef _UNICODE
#define tstring std::wstring
#define to_tstring to_wstring
#elif 
#define tstring std::string
#define to_tstring to_string
#endif // _UNICODE

tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();