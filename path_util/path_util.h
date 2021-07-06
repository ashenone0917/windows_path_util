#pragma once
#include <Windows.h>
#include <string>
using tstring = std::basic_string<TCHAR>;

//路径末尾不包含反斜杠(\\)
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);