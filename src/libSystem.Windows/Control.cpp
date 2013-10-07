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

#include <System/Windows/Controls/Control.h>
#include <System/Int32.h>
#include <System/Windows/Media/SolidColorBrush.h>
#include <System/Type.h>

namespace System
{
	namespace Windows
	{
		namespace Controls
		{
			const Type ControlTypeInfo("Control", "System::Windows::Controls::Control", TypeCode::Object);

			Control::Control()
				: Background(null), BorderBrush(null), BorderThickness(3), Foreground(new SolidColorBrush(Color::White)), Padding(0), TabIndex(Int32::MaxValue)
			{
			}

			Control::~Control()
			{
				delete Background;
				delete BorderBrush;
				delete Foreground;
			}

			void Control::OnGotFocus(RoutedEventArgs* e)
			{
				GotFocus(this, e);
			}

			void Control::OnKeyDown(KeyEventArgs* e)
			{
				KeyDown(this, e);
			}

			void Control::OnKeyUp(KeyEventArgs* e)
			{
				KeyUp(this, e);
			}

			void Control::OnLostFocus(RoutedEventArgs* e)
			{
				LostFocus(this, e);
			}

			void Control::OnMouseEnter(MouseEventArgs* e)
			{
				MouseEnter(this, e);
			}

			void Control::OnMouseLeave(MouseEventArgs* e)
			{
				MouseEnter(this, e);
			}

			void Control::OnMouseMove(MouseEventArgs* e)
			{
				MouseMove(this, e);
			}

			bool Control::Focus()
			{
				//! TODO: implement

				return true;
			}

			const Type& Control::GetType()
			{
				return ControlTypeInfo;
			}

			bool Control::operator ==(const Control& right) const
			{
				return Object::ReferenceEquals(*this, right);
			}

			bool Control::operator !=(const Control& right) const
			{
				return !Object::ReferenceEquals(*this, right);
			}
		}
	}
}
