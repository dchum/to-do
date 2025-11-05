#pragma once

#include "cui_widget.h"
#include "cui_lib.h"

namespace cui
{
    class CUIBorder : public Widget
    {
    private:
        WINDOW *win_;
        bool top_, left_, right_, bottom_;

    public:
        CUIBorder() = delete;
        CUIBorder(Widget* parent, int x, int y, int width, int height,
                bool top = true, bool left = true, bool right = true, bool down = true);

        CUIBorder ( const CUIBorder& ) = delete;
        CUIBorder& operator=(const CUIBorder&) = delete;
        

        ~CUIBorder();

    public:
        void draw  ( void ) override;
        void hide  ( void ) override;

    public:
        void ShowBorder( bool is_show );
        void ShowBorder( bool top, bool left, bool right, bool bottom );

        // void activate( unsigned int* ) override;
    };
}