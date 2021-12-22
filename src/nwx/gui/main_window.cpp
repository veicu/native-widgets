/**

    Definition of class main_window.

*/


#include "main_window.hpp"
#include "window_private.hpp"
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>


namespace
{
    /**

    */
    nwx::gui::color default_color()
    {
        DWORD sys_color = ::GetSysColor( COLOR_3DFACE );
        return nwx::gui::color( GetRValue( sys_color ), GetGValue( sys_color ), GetBValue( sys_color ) );
    }
}


namespace nwx
{
namespace gui
{


/**
    Standard constructor.
*/
main_window::main_window() : window( 0 )
{
    initialize( window_type::fixed, default_color() );
}

/**
    Extended constructor.
*/
main_window::main_window( int x, int y, int width, int height ) : window( 0, x, y, width, height )
{
    initialize( window_type::fixed, default_color() );
}

/**
    Extended constructor.
*/
main_window::main_window( const std::string& title, int x, int y, int width, int height, window_type wt /* = window_type::fixed */ ) : window( 0, x, y, width, height ), m_title( title )
{
    initialize( wt, default_color() );
}

/**
    Extended constructor.
*/
main_window::main_window( const std::string& title, int x, int y, int width, int height, window_type wt, color c ) : window( 0, x, y, width, height ), m_title( title )
{
    initialize( wt, c );
}

/**
    Set title.
*/
void main_window::title( const std::string& txt )
{
    m_title = txt;

    nwx::core::wstring ws( m_title );
    ::SetWindowText( d->window_resource, ws.lpcwstr() );
}

/**
    Get title.
*/
std::string main_window::title() const
{
    return m_title;
}

/**
    Constructor initialize method.
*/
void main_window::initialize( window_type wt, color c )
{
    window_info wi;
    wi.class_name = "NWXMainWindow";
    wi.window_name = m_title;
    wi.register_class_style = CS_DBLCLKS;

    switch( wt )
    {
    case window_type::normal:
        wi.create_window_reg_style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_CLIPCHILDREN;
        break;
    case window_type::fixed:
        wi.create_window_reg_style = WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN;
        break;
    case window_type::fixed_minimizable:
        wi.create_window_reg_style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN;
        break;
    case window_type::popup:
    case window_type::popup_top_level:
        wi.create_window_reg_style = WS_POPUP | WS_CLIPCHILDREN;
        break;
    default:
        break;
    }

    switch( wt )
    {
    case window_type::popup_top_level:
        wi.create_window_ext_style = WS_EX_APPWINDOW | WS_EX_CONTROLPARENT;
        break;
    default:
        wi.create_window_ext_style = WS_EX_CONTROLPARENT;
        break;
    }

    wi.background = c;

    d->adjust_window_rect( wi );
    d->register_class( wi );
    d->create_window( wi );

    use_default_font();
}





/*
fx_main_window::fx_main_window( const std::string& txt, int x, int y, int width, int height ) : main_window( txt, x, y, width, height, window_type::normal ), m_active( false )
{
    // ...
}

LRESULT fx_main_window::v_wnd_proc( UINT message, WPARAM wParam, LPARAM lParam )
{
    LRESULT result = FALSE;

    switch (message)
    {
//    case WM_NCACTIVATE:
//        return FALSE;
//    //    break;
//
//    case WM_ACTIVATE:
//        m_active = wParam != WA_INACTIVE;
////        paint_non_client_area( wParam );
////        return TRUE;
//        break;

    case WM_NCPAINT:
        paint_non_client_area( wParam );
        return FALSE;
        break;
    default:
        result = window::v_wnd_proc( message, wParam, lParam);
    }

    return result;
}

void fx_main_window::paint_non_client_area( WPARAM wParam )
{
    HDC hdc;
    RECT rect;
    HBRUSH b;
    HPEN pe;

    hdc=GetDCEx( resource().handle(),(HRGN)wParam,DCX_WINDOW|DCX_CACHE|DCX_INTERSECTRGN|DCX_LOCKWINDOWUPDATE);
    GetWindowRect(resource().handle(),&rect);
    //if( m_active )
    //{
        b=CreateSolidBrush(RGB(0,180,180));
    //}
    //else
    //{
    //    b=CreateSolidBrushandle(RGB(0,80,180));
    //}
    SelectObject(hdc,b);
    pe=CreatePen(PS_SOLID, 1, RGB(90, 90, 90));
    SelectObject(hdc,pe);
    Rectangle(hdc,0,0,(rect.right-rect.left),(rect.bottom-rect.top));
    DeleteObject(pe);
    DeleteObject(b);

    ReleaseDC(resource().handle(),hdc);
    RedrawWindow(resource().handle(),&rect,(HRGN)wParam,RDW_UPDATENOW);
}
*/


}
}
