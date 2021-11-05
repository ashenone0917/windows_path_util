#pragma once
#include <Windows.h>
#include <string>

using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> >;

//end not include '\\'
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);
