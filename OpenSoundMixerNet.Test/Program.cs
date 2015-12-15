using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace OpenSoundMixerNet.Test
{
	class Program
	{
		static void Main(string[] args)
		{
			var manager = new osm.Manager();
			if(manager.Initialize())
			{
				Console.WriteLine("Initialize succeeded.");
			}
			else
			{
				Console.WriteLine("Initialize failed.");
				return;
			}

			var sound = manager.CreateSound("bgm1.ogg");
			sound.IsLoopingMode = true;
			var playback = manager.Play(sound);

			Thread.Sleep(7000);
			playback.Stop();
			Console.WriteLine("Stopped");

			manager.Dispose();
			Console.ReadKey();
		}
	}
}
