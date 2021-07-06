#pragma once
#include <Windows.h>
#include <string>

using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> >;

//路径末尾不包含反斜杠(\\)
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);