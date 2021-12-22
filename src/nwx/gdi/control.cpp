#include "control.hpp"
#include <nwx/gui/window_private.hpp>
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace gdi
{


/**
    Constructor.
*/
control::control( nwx::gui::window* parent ) : widget( parent )
{
    // ...
}

/**
    Constructor.
*/
control::control( nwx::gui::window* parent, int x, int y, int width, int height ) : widget( parent, x, y, width, height )
{
    // ...
}

/**
    Redraw the whole widget.
*/
void control::update()
{
    ::InvalidateRect( d->window_resource, NULL, TRUE );
}


}
}
