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

//路径末尾不包含反斜杠(\\)
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);