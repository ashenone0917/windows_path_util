#include "path_util.h"
#include <iostream>
int main()
{
	auto current = GetPathFromCommandLine(std::wstring(L"C:\Windows\system32\svchost.exe -k netsvcs"));
	std::wcout << current;
	return 0;
}