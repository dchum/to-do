#include "cui_entry.h"

#include <stdexcept>

#include "cui_screen.h"

cui::CUIEntry::CUIEntry(Widget *parent, Message &title, Message &label, int x, int y, int fieldWidth, bool box, bool shadow)
    :Widget(parent, std::make_unique<RelativeSurface>(x, y, parent->width(), parent->height())),
    entry_(nullptr)
{
    auto size = GetSurface()->ComputeSize(parent->width(), parent->height());
    entry_ = newCDKEntry (parent->screen(), size.x, size.y,
            *(title.get_msg()), *(label.get_msg()),
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

// void cui::CUIEntry::activate(unsigned int* key)
// {
//     entry_->obj.hasFocus = 1;
//     activateCDKEntry (entry_, key);
// }
