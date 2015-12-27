#include "dll.h"
#include "OpenSoundMixer.h"

#ifdef DEBUG
#pragma comment(lib, "x86/Debug/libogg_static.lib")
#pragma comment(lib, "x86/Debug/libvorbis_static.lib")
#pragma comment(lib, "x86/Debug/libvorbisfile_static.lib")
#else
#pragma comment(lib, "x86/Release/libogg_static.lib")
#pragma comment(lib, "x86/Release/libvorbis_static.lib")
#pragma comment(lib, "x86/Release/libvorbisfile_static.lib")
#endif

using namespace osm;

Bool Osm_Manager_Initialize(void* self)
{
	Manager* instance = (Manager*)self;
	return instance->Initialize() ? 1 : 0;
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

void* Osm_Manager_CreateSound(void* self, void* data, int32_t size, Bool isDecompressed)
{
	Manager* instance = (Manager*)self;
	return (void*)instance->CreateSound(data, size, isDecompressed != 0);
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

Bool Osm_Manager_IsPlaying(void* self, int32_t id)
{
	Manager* instance = (Manager*)self;
	return instance->IsPlaying(id) ? 1 : 0;
}

void Osm_Manager_Pause(void* self, int32_t id)
{
	Manager* instance = (Manager*)self;
	instance->Pause(id);
}

void Osm_Manager_Resume(void* self, int32_t id)
{
	Manager* instance = (Manager*)self;
	instance->Resume(id);
}

void Osm_Manager_SetVolume(void* self, int32_t id, float volume)
{
	Manager* instance = (Manager*)self;
	instance->SetVolume(id, volume);
}

void Osm_Manager_FadeIn(void* self, int32_t id, float second)
{
	Manager* instance = (Manager*)self;
	instance->FadeIn(id, second);
}

void Osm_Manager_FadeOut(void* self, int32_t id, float second)
{
	Manager* instance = (Manager*)self;
	instance->FadeOut(id, second);
}

void Osm_Manager_Fade(void* self, int32_t id, float second, float targetVolume)
{
	Manager* instance = (Manager*)self;
	instance->Fade(id, second, targetVolume);
}

int Osm_Manager_Release(void* self)
{
	Manager* instance = (Manager*)self;
	return instance->Release();
}

Bool Osm_Sound_GetIsLoopingMode(void* self)
{
	Sound* instance = (Sound*)self;
	return instance->GetIsLoopingMode() ? 1 : 0;
}

void Osm_Sound_SetIsLoopingMode(void* self, Bool isLoopingMode)
{
	Sound* instance = (Sound*)self;
	instance->SetIsLoopingMode(isLoopingMode != 0);
}

int Osm_Sound_Release(void* self)
{
	Sound* instance = (Sound*)self;
	return instance->Release();
}