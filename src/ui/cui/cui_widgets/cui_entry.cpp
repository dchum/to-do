#include "cui_entry.h"

#include <stdexcept>

#include "cui_screen.h"

cui::CUIEntry::CUIEntry(CUIScreen& screen, Message &title, Message &label, int x, int y, int fieldWidth, bool box, bool shadow)
    :Widget(screen, std::make_unique<RelativeSurface>(x, y, screen.width(), screen.height())),
    entry_(nullptr)
{
    auto mes = CStringArray( title );
    auto lb  = CStringArray( label );

    entry_ = newCDKEntry (screen.get(), Widget::x0(), Widget::y0(),
            *(mes.data()), *( lb.data() ),
            A_NORMAL,   // сообщает, как будет выглядеть введенный символ 
            '.',        // разделитель
            vMIXED,     // вроде как отвечает за диапазон представимых символов
            fieldWidth, // ширина поля
            0,          // минимальное кол-во символов       
            256,        // максимальное кол-во символов
            box, shadow);

    if ( entry_ == nullptr )
        throw std::runtime_error("CUIEntry: Error new entry_");
}

cui::CUIEntry::~CUIEntry()
{
    destroyCDKEntry (entry_);
}

void cui::CUIEntry::draw(void)
{
    drawCDKEntry (entry_, ObjOf (entry_)->box);
}

void cui::CUIEntry::hide(void)
{
    eraseCDKEntry(entry_);
}

char* cui::CUIEntry::handle( uint* input )
{
    return activateCDKEntry (entry_, input);
}

void cui::CUIEntry::move( Alignment x, Alignment y )
{
    moveCDKEntry( entry_, static_cast<int>( x ), static_cast<int>( y ) , false, true );
}

// void cui::CUIEntry::activate(unsigned int* key)
// {
//     entry_->obj.hasFocus = 1;
//     activateCDKEntry (entry_, key);
// }