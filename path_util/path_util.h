#pragma once
#include <Windows.h>
#include <string>
using tstring = std::basic_string<TCHAR>;

//·��ĩβ��������б��(\\)
tstring GetCurrentProcessPath();

tstring GetUserDesktop();

tstring GetPublicDesktop();

tstring GetCurrentProcessName();

tstring GetPathFromCommandLine(const tstring& command_line);