#include "cui_window_setting.h"

#include "cui_lib.h"
#include "cui_radio.h"
#include "cui_label.h"

namespace cui
{
cui::Message msgHelp("</B>F1<!B>: Help  </B>F2<!B>: New task  </B>F10<!B>: Menu  < >: column  ^v: task  Enter: actions");
cui::Message msgRadio1("Dark~Light");
cui::Message msgRadio2("Enabled~Disabled");
cui::Message msgRadio3("Vim~Emacs~Classic");
cui::Message msgRadio4("Yes~No");
cui::Message msgRadio5("Board~Welcome");
cui::Message msgRadio1Title(" ");

cui::Message msgRadioName1("Theme: ");
cui::Message msgRadioName2("Auto-save:  ");
cui::Message msgRadioName3("Key mode: ");
cui::Message msgRadioName4("how estimates: ");
cui::Message msgRadioName5("Startup screen: ");


cui::WindowSetting::WindowSetting(Widget *parent)
    : Window(parent)
{
}

void cui::WindowSetting::init(void)
{
    this->ShowBorder(false);
    auto wdgtBox = dynamic_cast<WidgetBox*> (AddChild<WidgetBox>(0, 0, 50, 50) );
    wdgtBox->ShowBorder(true);
    
    wdgtBox->AddChild<CUILabel>( msgHelp, 0, 100, true, false );

    wdgtBox->AddChild<CUIRadio>( 25, 2+2,  5, 20, msgRadio1Title, msgRadio1, msgRadio1.count(),  '#', NONE, A_REVERSE, 1,   false);
    wdgtBox->AddChild<CUIRadio>( 25, 15+7,  10, 20, msgRadio1Title, msgRadio2, msgRadio2.count(),  '#', NONE, A_REVERSE, 1, false);
    wdgtBox->AddChild<CUIRadio>( 25, 34+6, 5, 23, msgRadio1Title, msgRadio3, msgRadio3.count(),  '#', NONE, A_REVERSE, 1,   false);
    wdgtBox->AddChild<CUIRadio>( 25, 55+6, 5, 19, msgRadio1Title, msgRadio4, msgRadio4.count(),  '#', NONE, A_REVERSE, 1,   false);
    wdgtBox->AddChild<CUIRadio>( 25, 73+6, 10, 20, msgRadio1Title, msgRadio5, msgRadio5.count(),  '#', NONE, A_REVERSE, 1,   false);

    wdgtBox->AddChild<CUILabel>( msgRadioName1, 5, 4+4,  false, false);
    wdgtBox->AddChild<CUILabel>( msgRadioName2, 5, 4+15, false, false);
    wdgtBox->AddChild<CUILabel>( msgRadioName3, 5, 4+34, false, false);
    wdgtBox->AddChild<CUILabel>( msgRadioName4, 5, 4+54, false, false);
    wdgtBox->AddChild<CUILabel>( msgRadioName5, 5, 4+73, false, false);
}

}//namespace cui

