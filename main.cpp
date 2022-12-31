#include <string>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

int main(int argc, char *argv[])
{
	char path[MAX_PATH];
	std::string fullPath;
	GetModuleFileNameA(NULL, path, MAX_PATH);
	PathRemoveFileSpecA(path);
	fullPath.append("\"").append(path).append("\\bin\\cdb.exe").append("\" ");
	if (argc == 1)
		fullPath.append("-?");
	else
	{
		fullPath.append("-abin\\ext.dll ");
		for (int i = 1; i < argc; i++)
			fullPath.append(argv[i]).append(" ");
		fullPath.pop_back();
	}
	system(fullPath.c_str());
	return 0;
}