using System;
using System.Runtime.InteropServices;

namespace osm
{
	internal static class PInvoke
	{
		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern IntPtr Osm_Manager_Create();

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		[return: MarshalAs(UnmanagedType.I1)]
		public static extern bool Osm_Manager_Initialize(IntPtr self);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_Finalize(IntPtr self);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int Osm_Manager_Release(IntPtr self);


		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern IntPtr Osm_Manager_CreateSound(
			IntPtr self,
			[MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)]byte[] data,
			int size,
			[MarshalAs(UnmanagedType.I1)]bool isDecompressed);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int Osm_Manager_Play(IntPtr self, IntPtr sound);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_Stop(IntPtr self, int id);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		[return: MarshalAs(UnmanagedType.I1)]
		public static extern bool Osm_Manager_IsPlaying(IntPtr self, int id);


		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_Pause(IntPtr self, int id);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_Resume(IntPtr self, int id);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_SetVolume(IntPtr self, int id, float volume);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_FadeIn(IntPtr self, int id, float second);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_FadeOut(IntPtr self, int id, float second);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Manager_Fade(IntPtr self, int id, float second, float targetVolume);


		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		[return: MarshalAs(UnmanagedType.I1)]
		public static extern bool Osm_Sound_GetIsLoopingMode(IntPtr self);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Osm_Sound_SetIsLoopingMode(
			IntPtr self,
			[MarshalAs(UnmanagedType.I1)]bool isLoopingMode);

		[DllImport("OpenSoundMixer_core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int Osm_Sound_Release(IntPtr self);
	}
}
