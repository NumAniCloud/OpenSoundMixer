using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace osm
{
	public class Manager
	{
		private IntPtr unmanagedPtr = new IntPtr(0);

		public Manager()
		{
			unmanagedPtr = PInvoke.Osm_Manager_Create();
		}

		~Manager()
		{
			PInvoke.Osm_Manager_Release(unmanagedPtr);
		}

		public bool Initialize()
		{
			return PInvoke.Osm_Manager_Initialize(unmanagedPtr);
		}

		public void Dispose()
		{
			PInvoke.Osm_Manager_Finalize(unmanagedPtr);
		}

		public Sound CreateSound(byte[] data, bool isDecompressed)
		{
			var sound = PInvoke.Osm_Manager_CreateSound(unmanagedPtr, data, data.Length, isDecompressed);
			return new Sound(sound);
		}

		public Sound CreateSound(string fileName)
		{
			Sound sound;
			using (var file = File.OpenRead(fileName))
			{
				byte[] data = new byte[file.Length];
				using (var reader = new BinaryReader(file))
				{
					reader.Read(data, 0, (int)file.Length);
				}
				sound = CreateSound(data, true);
			}
			return sound;
		}

		public Playback Play(Sound sound)
		{
			var id = PInvoke.Osm_Manager_Play(unmanagedPtr, sound.UnmanagedPtr);
            return new Playback(this, id);
		}


		internal void Stop(int id)
		{
			PInvoke.Osm_Manager_Stop(unmanagedPtr, id);
		}

		internal bool IsPlaying(int id)
		{
			return PInvoke.Osm_Manager_IsPlaying(unmanagedPtr, id);
		}

		internal void Pause(int id)
		{
			PInvoke.Osm_Manager_Pause(unmanagedPtr, id);
		}

		internal void Resume(int id)
		{
			PInvoke.Osm_Manager_Resume(unmanagedPtr, id);
		}

		internal void SetVolume(int id, float volume)
		{
			PInvoke.Osm_Manager_SetVolume(unmanagedPtr, id, volume);
		}

		internal void FadeIn(int id, float second)
		{
			PInvoke.Osm_Manager_FadeIn(unmanagedPtr, id, second);
		}

		internal void FadeOut(int id, float second)
		{
			PInvoke.Osm_Manager_FadeOut(unmanagedPtr, id, second);
		}

		internal void Fade(int id, float second, float targetVolume)
		{
			PInvoke.Osm_Manager_Fade(unmanagedPtr, id, second, targetVolume);
		}
	}
}
