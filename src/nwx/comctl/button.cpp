/**

    ...

*/


#include "button.hpp"
#include <nwx/gui/window_private.hpp>
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace comctl
{


/**
    Constructor.
*/
button::button( nwx::gui::window* parent ) : control( parent )
{
    initialize();
}

/**
    Constructor.
*/
button::button( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height )
{
    initialize();
}

/**
    Constructor.
*/
button::button( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height ) : control( parent, x, y, width, height ), m_text( txt )
{
    initialize();
}

/**

*/
void button::text( const std::string& txt )
{
    m_text = txt;

    nwx::core::wstring ws( m_text );
    ::SetWindowText( d->window_resource, ws.lpcwstr() );
}

/**

*/
std::string button::text() const
{
    return m_text;
}

/**

*/
void button::on_command( int /*id*/, int /*code*/ )
{
    clicked();
}

/**

*/
void button::initialize()
{
    //do_command( true );

    nwx::gui::window_info wi;
    wi.class_name = "Button";
    wi.window_name = m_text;
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON /* | BS_DEFPUSHBUTTON */;

    d->create_window( wi );
    use_default_font();
}


}
}
