#include <iostream>
#include <memory>
#include <signal.h>
#include <assert.h>

#include "cui_widget_box.h"
#include "cui_screen.h"
#include "cui_lib.h"
#include "cui_label.h"
#include "cui_entry.h"
#include "cui_slider.h"
#include "cui_dialog.h"
#include "cui_radio.h"
#include "cui_window_hello.h"

using namespace std;
using namespace cui;

void handle_resize(int sig) {
    endwin();
    refresh();
    resize_term(0, 0);  // перечитать размеры
    clear();
    refresh();
}

int main( )
{
    CUIScreen screen;
    WindowHello wndHello{&screen};

    // initscr();
    // cbreak();
    // noecho();
    // keypad(stdscr, TRUE);


    // signal(SIGWINCH, handle_resize);


    // while ( 1 )
    // {
    //     // cerr << LINES <<" "<< COLS;
    //     // mvprintw(LINES / 2, (COLS - 25) / 2, "Размер: %d x %d", LINES, COLS);
    //     // mvprintw(LINES - 1, 0, "Нажмите 'q' для выхода");
    //     // int ch = getch();
    //     // if (ch == 'q') break;
    // }
    // endwin();
    // mvprintw(LINES / 2, (COLS - 25) / 2, "Размер: %d x %d", LINES, COLS);
    // mvprintw(LINES - 1, 0, "Нажмите 'q' для выхода");

    wndHello.draw();
    // Message msg_label("<C></U>Dialog Widget Demo| | | | | | | | | | | | | | | | |<C>The dialog widget allows the programmer to create|<C>a popup dialog box with buttons." 
    //                 "The dialog box|<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>|<R>and even be right justified.|"
    //                 "<L>and left.|gfgdfgdfgdfg");

    // WidgetBox wdgt_box1(&screen);
    // const int id_parent1 = wdgt_box1.get_id();

    // auto lb1 = new CUILabel (&wdgt_box1, msg_label,240, 20, true, true);

    // assert( id_parent1 == lb1->getParent()->get_id() );

    // WidgetBox wdgt_box2(&screen);
    // const int id_parent2 = wdgt_box2.get_id();

    // lb1->SetParent(&wdgt_box2);
    // assert( id_parent2 == lb1->getParent()->get_id() );

    // std:: cout << wdgt_box.get_id() << endl;

    // wdgt_box.draw();
    // auto it = wdgt_box.CreateIterator();
    // for ( it->Begin(); !it->IsDone(); it->Next())
    // {
    //     it->CurrentValue().draw();
    // }


//     std::cout << screen.width() << " " << screen.height();
//     WidgetBox* wdgt_box = new WidgetBox(&screen);

//     Message msg_button("The dialog widget allows the programmer to create|<C>a popup dialog box with buttons." 
//                     "The dialog box|<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>|<R>and even be right justified.|"
//                     "<L>and left.|gfgdfgdfgdfg");
//     // // Message msg_entry_1("<C>Enter a\n<C>directory name#1");
//     // // Message msg_entry_2("<C>Enter a\n<C>directory name#2");

//     Message buttn("</B/2>Ok|</B16>Cancel|</B16>Hello");
//     Message sld_mes("<C></U>Enter a value:");
//     Message sld_lb("</B>Current Value:");

//     Message radio(" fdssfdsfdsf");
//     Message list("Choice A|Choice B|Choice C|Choice D|Choice E|Choice F");


//     CUILabel* lb    = new CUILabel (wdgt_box, msg_label, 0, 43, true, true); 
// //    auto t = lb->CreateIterator();
//   //  t->CurrentValue();
//      CUILabel* lb_   = new CUILabel (wdgt_box, msg_label,240, 20, true, true); 
//      CUIDialog * dl  = new CUIDialog(wdgt_box, msg_button, buttn, 0, 0);
//      CUIEntry* entr  = new CUIEntry (wdgt_box, msg_button, buttn, 70, 0, 40);
//      CUISlider* sldr = new CUISlider(wdgt_box, 50, 10, sld_mes, sld_lb, 50);
//      CUIRadio* rd    = new CUIRadio (wdgt_box, 60, 10, 10, 7, radio, list, list.count(), 35, 9001, 262144, 1, 1, 0);

//     wdgt_box->draw();

    pause();

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
     * ----------------------------------------------------------------------------------
     * 
     * for ( auto& wdgt : wdgt_box.children() )
     * {
     *      wdgt->draw(); //OK
     * }
     * 
     * for ( auto& wdgt : lb )
     * {
     *      wdgt->draw(); //WRONG!!!
     * }
     * 
     * 
     */
    
}
