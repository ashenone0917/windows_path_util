#include "path_util.h"
#include <iostream>
class temp {
public:
	temp() = default;
	~temp() {
		std::cout << "123456" << std::endl;
	}
};
int main()
{
	std::shared_ptr<temp> t = std::make_shared<temp>();
	t = std::make_shared<temp>();
	auto current = GetPathFromCommandLine(std::wstring(L"C:\\Windows\\system32\\svchost.exe -k netsvcs"));
	std::wcout << current << std::endl;
	return 0;
}