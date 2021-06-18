#include "path_util.h"
#include <shlobj_core.h>
#include <Shlwapi.h>

tstring GetCurrentProcessPath() {
	tstring ret{};
	ret.resize(MAX_PATH + 1);
	if (::GetModuleFileName(NULL, const_cast<WCHAR*>(ret.c_str()), MAX_PATH)) {
		ret = ret.substr(0, ret.find_last_of(L"\\"));
	}
	return std::move(ret);
}

template <typename T, size_t N>
char(&ArraySizeHelper(T(&array)[N]))[N];
#define SIZEOF_ARRAY(array)	(sizeof(ArraySizeHelper(array)))

HRESULT GetDisplayName(PCIDLIST_ABSOLUTE pidl, TCHAR* szDisplayName, UINT cchMax, DWORD uFlags)
{
	if (pidl == nullptr || szDisplayName == nullptr)
	{
		return E_FAIL;
	}

	IShellFolder* pShellFolder = nullptr;
	PCUITEMID_CHILD pidlRelative = nullptr;
	STRRET str;
	HRESULT hr;

	hr = SHBindToParent(pidl, IID_PPV_ARGS(&pShellFolder), &pidlRelative);

	if (SUCCEEDED(hr))
	{
		hr = pShellFolder->GetDisplayNameOf(pidlRelative, uFlags, &str);

		if (SUCCEEDED(hr))
		{
			hr = StrRetToBufW(&str, pidlRelative, szDisplayName, cchMax);
		}

		pShellFolder->Release();
	}

	return hr;
}

tstring GetUserDesktop() {
	PIDLIST_ABSOLUTE m_pidlDeskTop;
	tstring ret{};
	if (SUCCEEDED(SHGetFolderLocation(nullptr, CSIDL_DESKTOP, nullptr, 0, &m_pidlDeskTop)))
	{
		TCHAR szDesktopDisplayName[MAX_PATH];
		GetDisplayName(m_pidlDeskTop, szDesktopDisplayName, SIZEOF_ARRAY(szDesktopDisplayName), SHGDN_FORPARSING);
		ret = szDesktopDisplayName;
	}
	return std::move(ret);
}

tstring GetPublicDesktop() {
	PIDLIST_ABSOLUTE m_pidlDeskTop;
	tstring ret{};
	if (SUCCEEDED(SHGetFolderLocation(nullptr, CSIDL_COMMON_DESKTOPDIRECTORY, nullptr, 0, &m_pidlDeskTop)))
	{
		TCHAR szDesktopDisplayName[MAX_PATH];
		GetDisplayName(m_pidlDeskTop, szDesktopDisplayName, SIZEOF_ARRAY(szDesktopDisplayName), SHGDN_FORPARSING);
		ret = szDesktopDisplayName;
	}
	return std::move(ret);
}

tstring GetCurrentProcessName() {
	tstring ret{};
	ret.resize(MAX_PATH + 1);
	if (::GetModuleFileName(NULL, const_cast<WCHAR*>(ret.c_str()), MAX_PATH)) {
		ret = ret.substr(ret.find_last_of(L"\\") + 1, ret.length());
	}
	return std::move(ret);
}

tstring GetPathFromCommandLine(const tstring& command_line) {
	if (command_line.find(L"\"") != tstring::npos) {
		int argc = 0;
		auto commandlineargv = CommandLineToArgvW(command_line.c_str(), &argc);
		if (commandlineargv != NULL) return commandlineargv[0];
		return L"";
	}

	auto length = command_line.length();
	if (command_line[length - 1] == L'\\') return L"";

	int index1 = command_line.find_last_of(L"\\") + 1;
	auto substr = command_line.substr(index1, command_line.length());
	int index2 = substr.length();
	do
	{
		auto index3 = substr.find_last_of(L" ");
		if (index3 != tstring::npos) {
			substr = substr.substr(0, index3);
			index2 = index3;
		}
		else {
			break;
		}
	} while (true);

	return command_line.substr(0, index1 + index2);
}
