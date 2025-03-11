#pragma once
/*****************************************************************************************************************************
POS - пользовательская операционная система. Пафосное название, не более.
Раздел в проекте, хранящий общую информацию касающуюся всех остальных
разделом и обменов между ними. В отличие от библиотеки lib описывает конкретные
понятия.
****************************************************************************************************************************** */
#include <vector>
#include <memory>

#include <pos_widget.h>

namespace pos
{

enum class FRAME_KANBAB
{
    FRAME_INIT = 0,
    FRAME_BACKLOG,
    FRAME_IN_PROGRESS,
    FRAME_DONE,
};
    
    
/** черновик структуры для передачи всей информации о кадре
 * Кадр состоит из окон. Данная структура содержит описание
 * всех окон текущего кадра.
 */

class Window 
{
    
private:
    FRAME_KANBAB frame_;

    std::vector<std::shared_ptr<Widget>> window_;

public:
    Window(FRAME_KANBAB frame);
    Window(const Window&) = delete;

    Window& operator=(const Window&) = delete;

    ~Window() = default;

    void add_widget(std::shared_ptr<Widget> wdgt);

    void update ( void ) noexcept;

    const std::vector<std::shared_ptr<Widget>>& get_widgets( void ) const noexcept;

    const std::vector<std::shared_ptr<Widget>>& get_widgets( void ) noexcept;
};



}

