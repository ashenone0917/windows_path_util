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

//·��ĩβ��������б��(\\)
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);