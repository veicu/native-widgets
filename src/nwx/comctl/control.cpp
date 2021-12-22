/**

    ...

*/


#include "control.hpp"
#include <nwx/gui/window_private.hpp>


namespace nwx
{
namespace comctl
{


/**
    Constructor.
*/
control::control( nwx::gui::window* parent ) : nwx::gui::widget( parent ), m_font( 0 )
{
    // ...
}

/**
    Constructor.
*/
control::control( nwx::gui::window* parent, int x, int y, int width, int height ) : nwx::gui::widget( parent, x, y, width, height ), m_font( 0 )
{
    // ...
}

/**
    Sets the font of the widget.
*/
//void control::font( nwx::gui::font::pointer f )
//{
    //m_font = f;
    //::SendMessage( resource().handle(), WM_SETFONT, WPARAM( m_font->resource() ), TRUE );
//}

/**
    Sets the font of the widget.
*/
void control::font( nwx::gui::font* f )
{
    m_font = f;
    ::SendMessage( d->window_resource, WM_SETFONT, WPARAM( m_font->resource() ), TRUE );
}


}
}
