#pragma once
#include <cstdint>

extern "C"
{
	__declspec(dllexport) void* Osm_Manager_Create();
	__declspec(dllexport) bool Osm_Manager_Initialize(void* self);
	__declspec(dllexport) void Osm_Manager_Finalize(void* self);
	__declspec(dllexport) int Osm_Manager_Release(void* self);

	__declspec(dllexport) void* Osm_Manager_CreateSound(void* self, void* data, int32_t size, bool isDecompressed);
	__declspec(dllexport) int32_t Osm_Manager_Play(void* self, void* sound);
	__declspec(dllexport) void Osm_Manager_Stop(void* self, int32_t id);
	__declspec(dllexport) bool Osm_Manager_IsPlaying(void* self, int32_t id);

	__declspec(dllexport) void Osm_Manager_Pause(void* self, int32_t id);
	__declspec(dllexport) void Osm_Manager_Resume(void* self, int32_t id);
	__declspec(dllexport) void Osm_Manager_SetVolume(void* self, int32_t id, float volume);
	__declspec(dllexport) void Osm_Manager_FadeIn(void* self, int32_t id, float second);
	__declspec(dllexport) void Osm_Manager_FadeOut(void* self, int32_t id, float second);
	__declspec(dllexport) void Osm_Manager_Fade(void* self, int32_t id, float second, float targetVolume);

	__declspec(dllexport) bool Osm_Sound_GetIsLoopingMode(void* self);
	__declspec(dllexport) void Osm_Sound_SetIsLoopingMode(void* self, bool isLoopingMode);
	__declspec(dllexport) int Osm_Sound_Release(void* self);
}