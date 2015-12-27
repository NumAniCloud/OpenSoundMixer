using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace osm
{
	public class Sound
	{
		private IntPtr unmanagedPtr_;

		internal IntPtr UnmanagedPtr
		{
			get { return unmanagedPtr_; }
		}

		public bool IsLoopingMode
		{
			get
			{
				var result = PInvoke.Osm_Sound_GetIsLoopingMode(unmanagedPtr_);
				return result;
			}
			set { PInvoke.Osm_Sound_SetIsLoopingMode(unmanagedPtr_, value); }
		}

		internal Sound(IntPtr ptr)
		{
			unmanagedPtr_ = ptr;
		}

		~Sound()
		{
			PInvoke.Osm_Sound_Release(unmanagedPtr_);
		}
	}
}
