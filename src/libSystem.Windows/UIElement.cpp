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

#include <System/Windows/UIElement.h>
#include <System/Windows/Size.h>
#include <System/Type.h>

namespace System
{
	namespace Windows
	{
		const DependencyProperty<Visibility_t> UIElement::VisibilityProperty = DependencyProperty<Visibility_t>::Register("Visibility", UIElement::GetType());

		const Type UIElementTypeInfo("UIElement", "System::Windows::UIElement", TypeCode::Object);

		Visibility_t UIElement::getVisibility() const
		{
			return GetValue(VisibilityProperty);
		}

		void UIElement::setVisibility(const Visibility_t value)
		{
			SetValue(VisibilityProperty, value);
		}

		void UIElement::Arrange(const Rect finalRect)
		{
		}

		const Type& UIElement::GetType()
		{
			return UIElementTypeInfo;
		}

		void UIElement::InvalidateArrange()
		{
		}

		void UIElement::InvalidateMeasure()
		{
		}

		void UIElement::Measure(const Size availableSize)
		{
		}

		void UIElement::UpdateLayout()
		{
		}

		bool UIElement::operator !=(const UIElement& right) const
		{
			return Object::ReferenceEquals(*this, right);
		}

		bool UIElement::operator ==(const UIElement& right) const
		{
			return !Object::ReferenceEquals(*this, right);
		}
	}
}
