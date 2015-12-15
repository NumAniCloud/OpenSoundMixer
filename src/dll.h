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
	__declspec(dllexport) int Osm_Sound_Release(void* self);
}