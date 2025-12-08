#include <iostream>
#include <memory>
#include <signal.h>
#include <assert.h>
#include <time.h>

#include "cui_widget_box.h"
#include "cui_screen.h"
#include "cui_lib.h"
#include "cui_label.h"
#include "cui_entry.h"
#include "cui_slider.h"
#include "cui_dialog.h"
#include "cui_radio.h"
#include "cui_window_main.h"
#include "cui_window_start.h"
#include "cui_border.h"
#include "cui_window_setting.h"
#include "cui_application.h"

using namespace std;
using namespace cui;


int main( )
{
    CUIApplication app;
    
    // CUIScreen screen;
    // auto wndMain = new WindowMain(&screen);//;BuilderWidgetsCollection<WindowMain>::Create(&screen);
    // auto wdgtBox = BuilderWidgetsCollection<WidgetBox>::Create(&screen);
    // wdgtBox->ShowBorder(true);
    // wdgtBox->draw();
    // wndMain->init();

    app.exec();
    // while ( 1 )
    // {
    //     // screen.draw();
    //     struct  timespec ts = {0, 1000};
    //     nanosleep(&ts, NULL);
    // }

    // int i = 0;
    // auto it = wndMain->CreateIterator();
    // for ( it.get()->Begin(); !it.get()->IsDone(); it.get()->Next())
    // {
    //     // std::cerr << i++ << " " << it->CurrentValue().get_id() << std::endl;
    //     // it->CurrentValue().draw();
    //     // struct timespec t{3, 0};
    //     // nanosleep(&t, NULL);
    //     // cin >> i;
    // }

    // std::cout << screen.width() << " " << screen.height();
    // WidgetBox* wdgt_box = new WidgetBox(&screen);

    // Message msg_label("<C></U>Dialog Widget Demo^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^<C>The dialog widget allows the programmer to create^<C>a popup dialog box with buttons." 
    //                 "The dialog box^<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>^<R>and even be right justified.^"
    //                 "<L>and left.^gfgdfgdfgdfg");
    // Message msg_button("The dialog widget allows the programmer to create^<C>a popup dialog box with buttons." 
    //                 "The dialog box^<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>^<R>and even be right justified.^"
    //                 "<L>and left.^gfgdfgdfgdfg");
    // // Message msg_entry_1("<C>Enter a\n<C>directory name#1");
    // // Message msg_entry_2("<C>Enter a\n<C>directory name#2");

    // Message buttn("</B/2>Ok^</B16>Cancel^</B16>Hello");
    // Message sld_mes("<C></U>Enter a value:");
    // Message sld_lb("</B>Current Value:");

    // Message radio(" fdssfdsfdsf");
    // Message list("Choicfdsfsdfsdfsdfdsfsd^e A^Choice B^Choice C^Choice D^Choice E^Choice F");


    // CUILabel* lb    = new CUILabel (wdgt_box, msg_label, 0, 50, true, true); 
    // auto t = lb->CreateIterator();
    // t->CurrentValue();
    // CUILabel* lb_   = new CUILabel (wdgt_box, msg_label,0, 50, true, true); 
    // CUIDialog * dl  = new CUIDialog(wdgt_box, msg_button, buttn, 0, 50);
    // CUIEntry* entr  = new CUIEntry (wdgt_box, msg_button, buttn, 0, 50, 40);
    // CUISlider* sldr = new CUISlider(wdgt_box, 0, 50, sld_mes, sld_lb, 50);
    // CUIRadio* rd    = new CUIRadio (wdgt_box, 0, 50, 20, 20, radio, list, list.count(), 35, 9001, 262144, 1, 1, 0);

    // wdgt_box->AddChild<CUILabel>( msg_label, 50, 15, false, false ) ;
    // wdgt_box->AddChild<CUILabel>( msg_label, 70, 30, false, false ) ;

    // int i = 0;
    // auto it = wdgt_box->CreateIterator();
    // for ( it.get()->Begin(); !it.get()->IsDone(); it.get()->Next())
    //     std::cout << i++ << std::endl;

    // wdgt_box->draw();


    // auto wndStart = new WindowStart(&screen);
    // wndStart->draw();

    // std::cin>>x;

    // delete wdgt_box;

    /**
     * 
     * 1)
     * CUILabel* lb = new CUILabel(screen, msg_label, 10, 30, true, true); 
     * wdgt_box.AddChild(lb);
     * 
     * 2)
     * CUILabel* lb = new CUILabel(wdgt_box, msg_label, 10, 30, true, true);
     * 
     */
    
}