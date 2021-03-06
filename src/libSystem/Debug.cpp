// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//* Redistributions of source code must retain the above copyright 
//notice, this list of conditions and the following disclaimer.
//* Redistributions in binary form must reproduce the above copyright 
//notice, this list of conditions and the following disclaimer in the 
//documentation and/or other materials provided with the distribution.
//* Neither the name of the copyright holder nor the names of any 
//contributors may be used to endorse or promote products derived from 
//this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include <System/Diagnostics/Debug.h>
#include <System/String.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if ENABLE_XBOX
#include <xboxkrnl/xboxkrnl.h>
#else
// TODO: include Linux' debug header
#endif

namespace System
{
	namespace Diagnostics
	{
		void Debug::Assert(bool condition)
		{
#if DEBUG
			if (condition)
			{
#endif
				return;
#if DEBUG
			}

			// TODO: implement
#endif
		}

		void Debug::Assert(bool condition, const String& message)
		{
#if DEBUG
			if (condition)
			{
#endif
				return;
#if DEBUG
			}

			// TODO: implement
#endif
		}

		void Debug::WriteLine(const String& format, ...)
		{
#if !DEBUG
			return;
#else
			if (String::IsNullOrEmpty(format))
			{
				return;
			}

			va_list args;
			va_start(args, format);

			int count = vsnprintf(NULL, 0, format, args);

			char* res = (char*)malloc(count + 1);

			vsnprintf(res, count + 1, format, args);

			va_end(args);

			DbgPrint(res);

			free(res);
#endif
		}
	}
}
