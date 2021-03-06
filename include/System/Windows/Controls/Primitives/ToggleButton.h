/*****************************************************************************
 *	ToggleButton.h															 *
 *																			 *
 *	System::Windows::Controls::Primitives::ToggleButton definition file 	 *
 *	Copyright (c) XFX Team. All rights reserved 							 *
 *****************************************************************************/
#ifndef _SYSTEM_WINDOWS_CONTROLS_PRIMITIVES_TOGGLEBUTTON_
#define _SYSTEM_WINDOWS_CONTROLS_PRIMITIVES_TOGGLEBUTTON_

#include <System/Windows/Controls/Primitives/ButtonBase.h>
#include <System/Nullable.h>

namespace System
{
	namespace Windows
	{
		namespace Controls
		{
			namespace Primitives
			{
				/**
				 * Base class for controls that can switch states, such as System::Windows::Controls::CheckBox and System::Windows::Controls::RadioButton.
				 */
				class ToggleButton : public ButtonBase
				{
				protected:
					void OnClick();
					void OnContentChanged(Object* oldContent, Object* newContent);
					virtual void OnToggle();

				public:
					Nullable<bool> IsChecked;
					bool IsThreeState;

					ToggleButton();
					virtual ~ToggleButton();

					static const Type& GetType();
					const String ToString() const;

					bool operator==(const ToggleButton& right) const;
					bool operator!=(const ToggleButton& right) const;

					RoutedEventHandler Checked;
					RoutedEventHandler Indeterminate;
					RoutedEventHandler Unchecked;
				};
			}
		}
	}
}

#endif //_SYSTEM_WINDOWS_CONTROLS_PRIMITIVES_TOGGLEBUTTON_
