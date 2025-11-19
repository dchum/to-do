#include "cui_window_main.h"

#include "cui_label.h"
#include "cui_slider.h"
#include "cui_lib.h"
#include "cui_radio.h"

cui::Message msgLabelName("</B>Kanban: task traker</B>");
cui::Message msgLabelSupport("</B>F1<!B>: Help  </B>F2<!B>: New task  </B>F10<!B>: Menu  < >: column  ^v: task  Enter: actions");
cui::Message msgLabelDescription("-------------------------------------------------------------------------~\
TASK: (!) something blalblablalblablalblablalbla~blalblablalblablalbla~\
Due: 07.11         Status: DONE~\
Tags: #build #ci~\
Description: Set up GitLab CI pipeline for build and tests.");

cui::Message msgLabelBACKLOG ("<C></B>BACKLOG</B>");
cui::Message msgLabelPROGRESS("<C></B>IN PROGRESS</B>");
cui::Message msgLabelDONE    ("<C></B>DONE</B>");

cui::Message msgSliderHello_("<C>progress");
cui::Message msgSliderText_(" ");

cui::Message msgRadioBACKLOG("<A Choice~B Choice~C Choice~D Choice~E Choice~");
cui::Message msgRadioPROGRESS("A Choice~B Choice~C Choice~D Choice~E Choice~");
cui::Message msgRadioDONE ("A Choice~B Choice~C Choice~D Choice~E Choice~");

cui::Message msgHello_(
R"(                                                           ~
</B>__________ ________              ________  ________       ~
</B>|\___   ___\\   __  \            |\   ___ \|\   __  \     ~
</B>\|___ \  \_\ \  \|\  \  _________\ \  \_|\ \ \  \|\  \    ~
</B>     \ \  \ \ \  \\\  \|\_________\ \  \ \\ \ \  \\\  \   ~
</B>      \ \  \ \ \  \\\  \|_________|\ \  \_\\ \ \  \\\  \  ~
</B>       \ \__\ \ \_______\           \ \_______\ \_______\ ~
</B>        \|__|  \|_______|            \|_______|\|_______| ~
                                        To-Do CLI v0.1.0 | Created by: @dchum )"//FIXME - вынести номер версии в отдельный макрос
);

cui::WindowMain::WindowMain(Widget *parent)
    :WidgetBox(parent)
{
    AddChild<CUISlider> (40, 0, msgSliderHello_, msgSliderText_, 50);
    AddChild<CUILabel>  (msgLabelName,        0,   0, false, false );
    // AddChild( BuilderWidgetsCollection<WidgetBox>::Create(this).release() );
    
    // auto w = BuilderWidgetsCollection<WidgetBox>::Create(this);
    // auto l = new CUILabel(w.get(), msgLabelDescription, 0,  50, false, false);
    // l->draw();
    // w->draw();
    // w->AddChild<CUILabel>(msgLabelDescription, 0,  50, false, false);
    AddChild<CUILabel> (msgLabelDescription, 0,  50, false, false);
    
    AddChild<CUILabel> (msgLabelSupport,     0, 100, false, false);
    AddChild<CUIRadio> ( 2, 20, 10, 30, msgLabelBACKLOG, msgRadioBACKLOG, 5);
    AddChild<CUIRadio> (35, 20, 10, 30, msgLabelPROGRESS, msgRadioPROGRESS, 5);
    AddChild<CUIRadio> (70, 20, 10, 30, msgLabelDONE, msgRadioDONE, 5);
    AddChild<CUILabel> (msgHello_,  50, 70, false, false);
}