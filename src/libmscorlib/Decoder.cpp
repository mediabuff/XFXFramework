// Copyright (C) 2010-2012, XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
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

#include <System/Array.h>
#include <System/Text/Decoder.h>

#if DEBUG
#include <stdio.h>
#endif

namespace System
{
	namespace Text
	{
		void Decoder::Convert(byte* bytes, int byteCount, char* chars, int charCount, bool flush, out int bytesUsed, out int charsUsed, out bool completed)
		{
			CheckArguments(chars, charCount, bytes, byteCount);

			bytesUsed = byteCount;
			while (true) {
				charsUsed = GetCharCount (bytes, bytesUsed, flush);
				if (charsUsed <= charCount)
					break;
				flush = false;
				bytesUsed >>= 1;
			}
			completed = bytesUsed == byteCount;
			charsUsed = GetChars(bytes, bytesUsed, chars, charCount, flush);
		}

		void Decoder::Convert(byte bytes[], int byteIndex, int byteCount, char chars[], int charIndex, int charCount, bool flush, int bytesUsed, int charsUsed, bool completed)
		{
			CheckArguments (bytes, byteIndex, byteCount);
			CheckArguments (chars, charIndex);
			if (charCount < 0 || Array::Length(chars) < charIndex + charCount)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "charCount");
#endif
				return;
			}

			bytesUsed = byteCount;
			while (true)
			{
				charsUsed = GetCharCount (bytes, byteIndex, bytesUsed, flush);
				if (charsUsed <= charCount)
					break;
				flush = false;
				bytesUsed >>= 1;
			}
			completed = bytesUsed == byteCount;
			charsUsed = GetChars(bytes, byteIndex, bytesUsed, chars, charIndex, flush);
		}

		int Decoder::GetCharCount(byte bytes[], int index, int count, bool flush)
		{
			if (flush)
				Reset();
			return GetCharCount(bytes, index, count);
		}

		int Decoder::GetCharCount(byte* bytes, int count, bool flush)
		{
			if (bytes == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "bytes");
#endif
				return -1;
			}
			if (count < 0)
		    {
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\": %s\n", __FUNCTION__, __LINE__, __FILE__, "count", "Non-negative number required.");
#endif
				return -1;
		    }
		    byte *buffer = new byte[count];
		    for (int i = 0; i < count; i++)
		    {
		        buffer[i] = bytes[i];
		    }
		    return GetCharCount(buffer, 0, count, flush);
		}

		int Decoder::GetChars(byte bytes[], int byteIndex, int byteCount, char chars[], int charIndex, bool flush)
		{
			CheckArguments(bytes, byteIndex, byteCount);
			CheckArguments(chars, charIndex);
	
			if (flush)
				Reset();
			return GetChars(bytes, byteIndex, byteCount, chars, charIndex);
		}

		void Decoder::CheckArguments(char chars[], int charIndex)
		{
			if (chars == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "chars");
#endif
				return;
			}
			if (charIndex < 0 || Array::Length(chars) <= charIndex)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "charIndex");
#endif
				return;
			}
		}

		void Decoder::CheckArguments(byte bytes[], int byteIndex, int byteCount)
		{
			if (bytes == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "bytes");
#endif
				return;
			}
			if (byteIndex < 0 || Array::Length(bytes) <= byteIndex)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "byteIndex");
#endif
				return;
			}
			if (byteCount < 0 || Array::Length(bytes) < byteIndex + byteCount)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "byteCount");
#endif
				return;
			}
		}

		void Decoder::CheckArguments(char* chars, int charCount, byte* bytes, int byteCount)
		{
			if (chars == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "chars");
#endif
				return;
			}
			if (bytes == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "bytes");
#endif
				return;
			}
			if (charCount < 0)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "charCount");
#endif
				return;
			}
			if (byteCount < 0)
			{
#if DEBUG
				printf("ARGUMENT_OUT_OF_RANGE in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "byteCount");
#endif
				return;
			}
		}

		void Decoder::Reset()
		{
		}
	}
}
