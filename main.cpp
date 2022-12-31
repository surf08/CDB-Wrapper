#include <string>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

int main(int argc, char *argv[])
{
	char path[MAX_PATH];
	std::string fullpath;
	GetModuleFileNameA(NULL, path, MAX_PATH);
	PathRemoveFileSpecA(path);
	fullpath.append("\"").append(path).append("\\bin\\cdb.exe").append("\" ");
	if (argc == 1)
		fullpath.append("-?");
	else
	{
		fullpath.append("-abin\\ext.dll ");
		for (int i = 1; i < argc; i++)
			fullpath.append(argv[i]).append(" ");
		fullpath.pop_back();
	}
	system(fullpath.c_str());
	return 0;
}