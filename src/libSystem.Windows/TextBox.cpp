// Copyright (C) XFX Team
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

#include <System/Windows/Controls/TextBox.h>
#include <System/Windows/Media/SolidColorBrush.h>
#include <System/Type.h>

namespace System
{
	namespace Windows
	{
		namespace Controls
		{
			const Type TextBoxTypeInfo("TextBox", "System::Windows::Controls::TextBox", TypeCode::Object);

			TextBox::TextBox()
				: _text(String::Empty)
			{
				Background = new SolidColorBrush(Color::Gray);
				Foreground = new SolidColorBrush(Color::Black);
			}

			String TextBox::getSelectedText() const
			{
				return _text.SubString(selectionStart, selectionLength);
			}

			String TextBox::getText() const
			{
				return _text;
			}

			void TextBox::setText(const String& value)
			{
				_text = value;
			}

			const Type& TextBox::GetType()
			{
				return TextBoxTypeInfo;
			}

			void TextBox::Select(const int start, const int length)
			{
				selectionStart = start;
				selectionLength = length;
			}

			void TextBox::SelectAll()
			{
				Select(0, _text.Length);
			}

			const String TextBox::ToString() const
			{
				return _text;
			}
		}
	}
}
