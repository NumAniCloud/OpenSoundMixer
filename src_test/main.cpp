#include <windows.h>
#include <iostream>
#include <exception>
#include <cstdint>
#include <vector>

HINSTANCE hDll;
void*(*Osm_Manager_Create)();
bool(*Osm_Manager_Initialize)(void*);
void(*Osm_Manager_Finalize)(void*);
int(*Osm_Manager_Release)(void*);
void*(*Osm_Manager_CreateSound)(void*, void*, int32_t, bool);
int32_t(*Osm_Manager_Play)(void*, void*);
void(*Osm_Manager_Stop)(void*, int32_t);
int(*Osm_Sound_Release)(void*);

void CheckDllFunction(void* function)
{
	if (!function)
	{
		throw 1;
	}
}

void LoadDll()
{
	hDll = ::LoadLibraryEx("OpenSoundMixer.dll", NULL, 0);
	if (!hDll) throw 0;

	Osm_Manager_Create = (void*(*)())(::GetProcAddress(hDll, "Osm_Manager_Create"));
	if (!Osm_Manager_Create) throw 1;

	Osm_Manager_Initialize = (bool(*)(void*))(::GetProcAddress(hDll, "Osm_Manager_Initialize"));
	if (!Osm_Manager_Initialize) throw 1;

	Osm_Manager_Finalize = (void(*)(void*))(::GetProcAddress(hDll, "Osm_Manager_Finalize"));
	if (!Osm_Manager_Finalize) throw 1;

	Osm_Manager_Release = (int(*)(void*))(::GetProcAddress(hDll, "Osm_Manager_Release"));
	if (!Osm_Manager_Release) throw 1;

	Osm_Manager_CreateSound = (void*(*)(void*, void*, int32_t, bool))(::GetProcAddress(hDll, "Osm_Manager_CreateSound"));
	if (!Osm_Manager_CreateSound) throw 1;

	Osm_Manager_Play = (int32_t(*)(void*, void*))(::GetProcAddress(hDll, "Osm_Manager_Play"));
	if (!Osm_Manager_Play) throw 1;

	Osm_Manager_Stop = (void(*)(void*, int32_t))(::GetProcAddress(hDll, "Osm_Manager_Stop"));
	if (!Osm_Manager_Stop) throw 1;

	Osm_Sound_Release = (int(*)(void*))(::GetProcAddress(hDll, "Osm_Sound_Release"));
	if (!Osm_Sound_Release) throw 1;
}

std::wstring ToWide(const char* pText);
void GetDirectoryName(char* dst, char* src);

void Run()
{
	void* manager = Osm_Manager_Create();
	if (Osm_Manager_Initialize(manager))
	{
		printf("initialize succeeded\n");
	}
	else
	{
		printf("initialize failure\n");
		return;
	}

	void* sound = nullptr;

	{
		FILE* fp = nullptr;
		fopen_s(&fp, "bgm1.ogg", "rb");

		if (fp == nullptr)
		{
			return;
		}

		fseek(fp, 0, SEEK_END);
		auto size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		std::vector<uint8_t> data;
		data.resize(size);
		fread(data.data(), size, 1, fp);
		fclose(fp);

		sound = Osm_Manager_CreateSound(manager, data.data(), data.size(), true);
	}

	auto id = Osm_Manager_Play(manager, sound);

	Sleep(2000);
	Osm_Manager_Stop(manager, id);

	Osm_Manager_Finalize(manager);
	Osm_Sound_Release(sound);
	Osm_Manager_Release(manager);
}

void main(int argc, char **argv)
{
	char current_path[MAX_PATH + 1];
	GetDirectoryName(current_path, argv[0]);
	SetCurrentDirectoryA(current_path);

	try
	{
		LoadDll();
	}
	catch (int e)
	{
		if (e == 0)
		{
			printf("dll load error\n");
		}
		else if (e == 1)
		{
			printf("function load error\n");
			::FreeLibrary(hDll);
		}
		getchar();
		return;
	}

	Run();
	::FreeLibrary(hDll);
	getchar();
}

void GetDirectoryName(char* dst, char* src)
{
	auto Src = std::string(src);
	int pos = 0;
	int last = 0;
	while (Src.c_str()[pos] != 0)
	{
		dst[pos] = Src.c_str()[pos];

		if (Src.c_str()[pos] == L'\\' || Src.c_str()[pos] == L'/')
		{
			last = pos;
		}

		pos++;
	}

	dst[pos] = 0;
	dst[last] = 0;
}