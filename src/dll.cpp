#include "dll.h"
#include "OpenSoundMixer.h"

#pragma comment(lib, "x86/Debug/libogg_static.lib")
#pragma comment(lib, "x86/Debug/libvorbis_static.lib")
#pragma comment(lib, "x86/Debug/libvorbisfile_static.lib")

using namespace osm;

bool Osm_Manager_Initialize(void* self)
{
	Manager* instance = (Manager*)self;
	return instance->Initialize();
}

void Osm_Manager_Finalize(void* self)
{
	Manager* instance = (Manager*)self;
	instance->Finalize();
}

void* Osm_Manager_Create() 
{
	return (void*)osm::Manager::Create();
}

void* Osm_Manager_CreateSound(void* self, void* data, int32_t size, bool isDecompressed)
{
	Manager* instance = (Manager*)self;
	return (void*)instance->CreateSound(data, size, isDecompressed);
}

int32_t Osm_Manager_Play(void* self, void* sound)
{
	Manager* instance = (Manager*)self;
	return instance->Play((Sound*)sound);
}

void Osm_Manager_Stop(void* self, int32_t id)
{
	Manager* instance = (Manager*)self;
	instance->Stop(id);
}

int Osm_Manager_Release(void* self)
{
	Manager* instance = (Manager*)self;
	return instance->Release();
}

int Osm_Sound_Release(void* self)
{
	Sound* instance = (Sound*)self;
	return instance->Release();
}
