#include <iostream>
#include <memory>
#include <signal.h>
#include <assert.h>
#include <time.h>

#include "cui_screen.h"
#include "cui_lib.h"
#include "cui_label.h"
#include "cui_entry.h"
#include "cui_slider.h"
#include "cui_dialog.h"
#include "cui_scroll_list.h"
#include "cui_container.h"
#include "cui_window_start.h"
#include "cui_border.h"
#include "cui_window_setting.h"
#include "cui_application.h"
#include "cui_window_main.h"
#include "add_new_task.h"

using namespace std;
using namespace cui;

static Message buttn("</B/2>Ok^</B16>Cancel^</B16>Hello");
static Message msg_button("The dialog ");

int main( )
{
    // CUIApplication app;
    // app.exec();
    CUIScreen screen;
    Message scrlist(" ScrollList");
    Message list("A~B~C");

    CUIScrollList rd ( screen, 0, 0, Alignment::Right, 20, 20, scrlist, list, true, A_REVERSE, true, false );
    rd.draw();
    sleep(4);
    rd.addItem("hello");
    rd.draw();
    pause();

    // InputTextCommand command(screen);
    // CUILabel* lb_   = new CUILabel (&screen, msg_button, 0, 50, true, true); 
    // CUIEntry* entr2  = new CUIEntry (lb_, msg_button, buttn, 50, 0, 40);
    // command.Execute();
    // auto m = msg_button.tokens();
    // auto s = CStringArray( msg_button );
    // for ( auto & i : m )
    //     std::cout << i << std:: endl;

    // int x = s.size();
    // for ( int i = 0; i < x ; i++){
    //     std::cerr << s.data()[i];
    // }


    // CUIEntry* entr  = new CUIEntry (screen, msg_button, buttn, 50, 50, 40);
    // entr->draw();
    // auto wndMain = new WindowMain(screen);//;BuilderWidgetsCollection<WindowMain>::Create(&screen);
    // auto wdgtBox = BuilderWidgetsCollection<Container>::Create(&screen);
    // wdgtBox->ShowBorder(true);
    // wdgtBox->draw();
    // refreshCDKScreen ( screen.get() );
    // wndMain->init();
    // wndMain->draw();

    // wgetch( screen.get()->window);
    // screen.draw();

    // pause();

    // CDKSCREEN *cdkscreen = NULL;
    // CDKENTRY *directory  = NULL;
    // const char *title    = "<C>Enter a\n<C>directory name.";
    // const char *label    = "</U/5>Directory:<!U!5>";
    // char *info;
    // const char *mesg[10];
    // char temp[256];

    // cdkscreen = initCDKScreen (NULL);

    // /* Start CDK colors. */
    // initCDKColor ();

    // /* Create the entry field widget. */
    // directory = newCDKEntry (cdkscreen,
    //             'X',
    //             'Y',
    //             title, label, A_NORMAL, '.', vMIXED,
    //             40, 10, 256,
    //             'N',
    //             'S');

    // info = activateCDKEntry (directory, NULL);

    // CUIEntry* entr2  = new CUIEntry (&screen, msg_button, buttn, 0, 10, 40);
    // screen.draw();
    // screen.hide();
    // std::cin.clear();
    // std::cin >> x;
    // pause();
    // app.exec();
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
    // Container* wdgt_box = new Container(&screen);

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
    // CUIScrollList* rd    = new CUIScrollList (wdgt_box, 0, 50, 20, 20, radio, list, list.count(), 35, 9001, 262144, 1, 1, 0);

    // wdgt_box->AddChild<CUILabel>( msg_label, 50, 15, false, false ) ;
    // wdgt_box->AddChild<CUILabel>( msg_label, 70, 30, false, false ) ;

    // int i = 0;
    // auto it = wdgt_box->CreateIterator();
    // for ( it.get()->Begin(); !it.get()->IsDone(); it.get()->Next())
    //     std::cout << i++ << std::endl;

    // wdgt_box->draw();


    // auto wndStart = new WindowStart(&screen);
    // wndStart->draw();

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