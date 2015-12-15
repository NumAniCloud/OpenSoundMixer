using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace osm
{
	public class Playback
	{
		private Manager manager { get; set; }
		private int id { get; set; }

		public bool IsPlaying
		{
			get { return manager.IsPlaying(id); }
		}

		internal Playback(Manager manager, int id)
		{
			this.manager = manager;
			this.id = id;
		}

		public void Stop()
		{
			manager.Stop(id);
		}

		public void Pause()
		{
			manager.Pause(id);
		}

		public void Resume()
		{
			manager.Resume(id);
		}

		public void SetVolume(float volume)
		{
			manager.SetVolume(id, volume);
		}

		public void FadeIn(float second)
		{
			manager.FadeIn(id, second);
		}

		public void FadeOut(float second)
		{
			manager.FadeOut(id, second);
		}

		public void Fade(float second, float targetVolume)
		{
			manager.Fade(id, second, targetVolume);
		}
	}
}
