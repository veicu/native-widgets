/**

    Definition of class window.

*/


#include "window.hpp"
#include "window_private.hpp"
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace gui
{


/**
    Constructor.
*/
window::window( window* parent ) : window( parent, 0, 0, 0, 0 ) {}


/**
    Constructor.
*/
window::window( window* parent, int x, int y, int width, int height ) : m_erase_background( false ), m_parent( parent ), m_x( x ), m_y( y ), m_width( width ), m_height( height ), d( nullptr )
{
    d = std::make_unique<window_private>( this );
}

/**
    Destructor.
*/
window::~window()
{
    if( m_parent )
    {
        ::DestroyWindow( d->window_resource ); // destroys the window and sendes WM_DESTROY
    }
}

/**
    Get x position.
*/
int window::x() const
{
    return m_x;
}

/**
    Get y position.
*/
int window::y() const
{
    return m_y;
}

/**
    Get width.
*/
int window::width() const
{
    return m_width;
}

/**
    Get height.
*/
int window::height() const
{
    return m_height;
}

/**
    Set x position.
*/
void window::x( int x )
{
    m_x = x;
}

/**
    Set x position.
*/
void window::y( int y )
{
    m_y = y;
}

/**
    Set width.
*/
void window::width( int width )
{
    m_width = width;
}

/**
    Set height.
*/
void window::height( int height )
{
    m_height = height;
}

/**
    Set position.
*/
void window::pos( int x, int y )
{
    m_x = x;
    m_y = y;
    ::SetWindowPos( d->window_resource, NULL, m_x, m_y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}

/**
    Set size.
*/
void window::size( int width, int height )
{
    m_width = width;
    m_height = height;
    ::SetWindowPos( d->window_resource, NULL, 0, 0, m_width, m_height, SWP_NOMOVE | SWP_NOZORDER );
}

/**
    Set geometry.
*/
void window::geometry( int x, int y, int width, int height )
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    ::SetWindowPos( d->window_resource, NULL, m_x, m_y, m_width, m_height, SWP_NOZORDER );
}

/**
    Show window.
*/
void window::show()
{
    ::ShowWindow( d->window_resource, SW_SHOWNORMAL );
}

/**
    Hide window.
*/
void window::hide()
{
    ::ShowWindow( d->window_resource, SW_HIDE );
}

/**
    Update window
*/
void window::update()
{
    ::UpdateWindow( d->window_resource );
}

/**

*/
void window::z_order( z_order_type z )
{
    HWND inset_after = HWND_NOTOPMOST;
    switch (z)
    {
    case z_order_type::bottom:
        inset_after = HWND_BOTTOM;
        break;
    case z_order_type::top:
        inset_after = HWND_TOP;
        break;
    case z_order_type::topmost:
        inset_after = HWND_TOPMOST;
        break;
    default:
        break;
    }

    ::SetWindowPos( d->window_resource, inset_after, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
}

/**
    Set enable state.
*/
void window::enable( bool state )
{
    ::EnableWindow( d->window_resource, state ? TRUE : FALSE );
}

/**
    Get enable state.
*/
bool window::enabled()
{
    //assert(::IsWindow(m_window_resource));
    return ::IsWindowEnabled( d->window_resource ) != FALSE;
}

/**
    Widget should use the default font.
*/
void window::use_default_font()
{
    HFONT defaultFont;
    defaultFont = (HFONT)::GetStockObject( DEFAULT_GUI_FONT );
    ::SendMessage( d->window_resource, WM_SETFONT, WPARAM( defaultFont ), TRUE );
}

/**
    Event
*/
void window::on_create()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_paint()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_command( int /*id*/, int /*code*/ )
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_mouse_down()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_mouse_up()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_double_click()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_mouse_enter()
{
    // nothing to do in base class ...
}

/**
    Event
*/
void window::on_mouse_leave()
{
    // nothing to do in base class ...
}


}
}
