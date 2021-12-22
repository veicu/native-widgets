/**

    ...

*/


#include "edit.hpp"
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
edit::edit( nwx::gui::window* parent ) : control( parent )
{
    initialize();
}

/**
    Constructor.
*/
edit::edit( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height )
{
    initialize();
}

/**

*/
void edit::text( const std::string& txt )
{
    nwx::core::wstring ws( txt );
    ::SetWindowText( d->window_resource, ws.lpcwstr() );
}

/**

*/
std::string edit::text()
{
    std::string txt;

    int len = ::GetWindowTextLength( d->window_resource );
    if(len > 0)
    {
        wchar_t* wchar;
        wchar = new wchar_t[ len + 1 ];
        ::GetWindowText( d->window_resource, wchar, len + 1 );
        txt = nwx::core::wstring::utf8_encode( wchar );
        delete[] wchar;
    }

    return txt;
}

/**

*/
void edit::initialize()
{
    nwx::gui::window_info wi;
    wi.class_name = "Edit";
    wi.create_window_ext_style = WS_EX_CLIENTEDGE;
    wi.create_window_reg_style = WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOVSCROLL | ES_MULTILINE;

    d->create_window( wi );
    use_default_font();
}


}
}
