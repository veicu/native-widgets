/**

    ...

*/


#include "label.hpp"
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
label::label( nwx::gui::window* parent ) : control( parent )
{
    initialize();
}

/**
    Constructor.
*/
label::label( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height )
{
    initialize();
}

/**
    Constructor.
*/
label::label( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height ) : control( parent, x, y, width, height ), m_text( txt )
{
    initialize();
}

/**

*/
void label::text( const std::string& txt )
{
    m_text = txt;

    nwx::core::wstring ws( m_text );
    ::SetWindowText( d->window_resource, ws.lpcwstr() );
}

/**

*/
std::string label::text() const
{
    return m_text;
}

/**

*/
void label::initialize()
{
    nwx::gui::window_info wi;
    wi.class_name = "Static";
    wi.window_name = m_text;
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE /*| SS_NOTIFY*/ /*| SS_SIMPLE*/;

    d->create_window( wi );
    use_default_font();
}


}
}
