/**

    Definition of class window_private.

*/


#include "window_private.hpp"
#include <nwx/core/application.hpp>
#include <nwx/core/wstring.hpp>


namespace nwx
{
namespace gui
{


/**
    Constructor.
*/
window::window_private::window_private( window* parent ) : m_window( parent )
{
    // nothing to do ...
}

window::window_private::~window_private()
{
    m_window = nullptr;
}

/**
    Get window pointer.
*/
window* window::window_private::from_resource( HWND win_res )
{
    window* w = 0;
    w = ( window* ) ::GetProp( win_res, L"NWX_WIDGET_POINTER" );
    return w;
}

/**
    The global message handling procedure.
*/
LRESULT CALLBACK  window::window_private::wnd_proc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    window* w = from_resource( hwnd );
    if( w )
    {
        LRESULT result = w->d->v_wnd_proc( message, wParam, lParam );
        if( result )
        {
            return result;
        }
    }

    switch( message )
    {
    case WM_NCACTIVATE:
    {
        int a = 1;
        break;
    }

    case WM_ACTIVATE:
    {
        int b = 1;
        break;
    }

    case WM_NCPAINT:
    {
        int brk = 1;
        break;
    }
    }

    return ::DefWindowProc( hwnd, message, wParam, lParam );
}

/**
    The window type specific message handling procedure.
*/
LRESULT window::window_private::v_wnd_proc( UINT message, WPARAM wParam, LPARAM lParam )
{
    LRESULT result = FALSE;

    switch( message )
    {

        //case WM_ERASEBKGND:
        //    if( m_erase_background )
        //    {
        //        result = TRUE;
        //    }
        //break;

    case WM_PAINT:
        //if( m_do_paint )
        //{

        m_window->on_paint();
        
        //}
        break;

        //case WM_CTLCOLORSTATIC:
        //{
        //    HDC hdcStatic = (HDC) wParam;
        //    SetTextColor(hdcStatic, RGB(255,255,255));
        //    //SetBkColor(hdcStatic, RGB(230,230,230));
        //    SetBkMode(hdcStatic, TRANSPARENT);

        //    //HBRUSH hBrush = CreateSolidBrushandle(RGB(125,125,125));

        //    lResult = (INT_PTR)hBrush;
        //    ret = true;
        //}
        //break;

        //case WM_LBUTTONDOWN:
        //    hdc = GetDC(hwnd);
        //    wchar_t str[50];
        //    //wsprintf(str,L"%i|%i|%i|%i",hwnd,message,wParam,lParam);
        //    wsprintf(str,L"%i|%i|%i|%i|%i",hwnd,message,wParam,LOWORD(lParam),HIWORD(lParam)); 
        //    TextOut (hdc, 20, 20, str, wcslen(str));
        //    ReleaseDC(hwnd,hdc);
        //    return 0;

        //case WM_CREATE: // this won't work here since WIDGET_POINTER is set after CreateWindowEx via SetProp()
        //    on_create();
        //    //result = 0;
        //    break;

    case WM_COMMAND:
    {
        HWND child_hwnd = HWND( lParam );

        //nwx::core::window_resource child_window_resource( child_hwnd );
        window* w = from_resource( child_hwnd );

        //if( w->m_do_command )
        //{
        w->on_command
            (
                LOWORD( wParam ), // id
                HIWORD( wParam )  // code
                );
        result = TRUE;
        //}
    }
    break;


    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    {
        //MouseEvent
        //    ev(this,                           // window
        //    Point(&MAKEPOINTS(lParam)),               // pt
        //    1,                           // clicks
        //    wParam,                       // flags
        //    message == WM_LBUTTONDOWN ? MouseButton::Left:  // button
        //    message == WM_RBUTTONDOWN ? MouseButton::Right:
        //    message == WM_MBUTTONDOWN ? MouseButton::Middle:
        //    MouseButton::None);

        //onMouseDown(ev);
        m_window->on_mouse_down();
    }
    break;

    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    {
        //MouseEvent
        //    ev(this,                         // window
        //    Point(&MAKEPOINTS(lParam)),             // pt
        //    1,                             // clicks
        //    wParam,                     // flags
        //    message == WM_LBUTTONUP ? MouseButton::Left:  // button
        //    message == WM_RBUTTONUP ? MouseButton::Right:
        //    message == WM_MBUTTONUP ? MouseButton::Middle:
        //    MouseButton::None);

        //onMouseUp(ev);
        m_window->on_mouse_up();
    }
    break;


    //case WM_LBUTTONDBLCLK:
    //case WM_MBUTTONDBLCLK:
    //case WM_RBUTTONDBLCLK:
    //    {
    //        if( on_double_click() )
    //        {
    //            lResult = TRUE;
    //            ret = true;
    //        }
    //    }
    //    break;

    case WM_MOUSEMOVE:
    {
        /*
        // Retrieve mouse screen position
        int x = (short)LOWORD(lParam);
        int y = (short)HIWORD(lParam);

        // Check to see if the left button is held down:
        bool leftButtonDown = wParam & MK_LBUTTON;

        // Check if right button down:
        bool rightButtonDown = wParam & MK_RBUTTON;
        */

        //MouseEvent
        //    ev(this,                    // window
        //    Point(&MAKEPOINTS(lParam)),            // pt
        //    0,                        // clicks
        //    wParam,                    // flags
        //    MouseButton::None);                // button

        //if (!m_mouse_over)
        {
            //m_mouse_over = true;
            m_window->on_mouse_enter();

            TRACKMOUSEEVENT tme;
            tme.cbSize = sizeof( TRACKMOUSEEVENT );
            tme.dwFlags = TME_LEAVE;// | TME_HOVER
            tme.hwndTrack = window_resource;
            ::TrackMouseEvent( &tme );
        }

        //onMouseMove(ev);
        break;
    }


    //case WM_MOUSEHOVER:
    //    {
    //        on_mouse_enter();
    //    }
    //    break;

    case WM_MOUSELEAVE:
    {
        //m_mouse_over = false;
        m_window->on_mouse_leave();
    }
    break;

    case WM_DESTROY:
        if( !m_window->m_parent ) // ignore message for child windows
        {
            ::PostQuitMessage( 0 ); // generate the WM_QUIT message, so message loop can end
        }
        break;

    default:
        break;
    }

    return result;
}

/**
    Get parent window handle.
*/
HWND window::window_private::parent_window_resource() const
{
    if( m_window->m_parent )
    {
        return m_window->m_parent->d->window_resource;
    }

    return NULL;
}

/**
    Native class register.
*/
void window::window_private::register_class( const window_info& info )
{
    nwx::core::wstring class_name( info.class_name );

    WNDCLASSEX wcex;

    if( !::GetClassInfoEx( nwx::core::application::resource().handle(), class_name.lpcwstr(), &wcex) ) // register class only one time
    {
        HBRUSH background_brush = NULL;
        if( info.background.alpha() == 0 )
        {
            //background_brush = (HBRUSH) ::GetStockObject( NULL_BRUSH );
        }
        else
        {
            background_brush = ::CreateSolidBrush( RGB( info.background.red(), info.background.green(), info.background.blue() ) );
        }

        wcex.cbSize        = sizeof( WNDCLASSEX );
        wcex.style         = info.register_class_style;                        // CS_ = "class style"
        wcex.lpfnWndProc   = window::window_private::wnd_proc;
        wcex.cbClsExtra    = 0;
        wcex.cbWndExtra    = 0;                                                //T::getWndExtra();
        wcex.hInstance     = nwx::core::application::resource().handle();
        wcex.hIcon         = NULL;                                             //LoadIcon(hInstance, IDI_GFC)
        wcex.hCursor       = ::LoadCursor( NULL, IDC_ARROW );                  //(HCURSOR)NULL
        wcex.hbrBackground = background_brush;
        wcex.lpszMenuName  = (LPCTSTR)NULL;
        wcex.lpszClassName = class_name.lpcwstr();
        wcex.hIconSm       = NULL;                                             //LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL)

        if( ::RegisterClassEx( &wcex ) == 0 )
        {
            int brk = 1;
            //throw RegisterException(String("Error registering class \"") +
            //String(class_name) + "\"");
        }
    }
}

/**
    Native window creation.
*/
void window::window_private::create_window( const window_info& info )
{
    nwx::core::wstring class_name( info.class_name );
    nwx::core::wstring window_name( info.window_name );

    HWND hwnd = ::CreateWindowEx
    (
        info.create_window_ext_style, // style.extended
        class_name.lpcwstr(),
        window_name.lpcwstr(),
        info.create_window_reg_style, // style.regular
        m_window->m_x,                // initial x position
        m_window->m_y,                // initial y position
        m_window->m_width,            // initial x size
        m_window->m_height,           // initial y size
        parent_window_resource(),
        (HMENU)NULL,
        nwx::core::application::resource().handle(),
        0
    );

    //unsigned long error_code = ::GetLastError();

    ::SetProp( hwnd, L"NWX_WIDGET_POINTER", m_window );

    window_resource = hwnd;
}


/**
    Adjust the size of the window based on the desired client area size and the window style.
*/
void window::window_private::adjust_window_rect( window_info& info )
{
    RECT rect;
    rect.left   = m_window->m_x;
    rect.top    = m_window->m_y;
    rect.right  = m_window->m_x + m_window->m_width;
    rect.bottom = m_window->m_y + m_window->m_height;

    if( ::AdjustWindowRectEx( &rect, info.create_window_reg_style, FALSE, info.create_window_ext_style ) )
    {
        m_window->m_width  = rect.right - rect.left;
        m_window->m_height = rect.bottom - rect.top;
    }
}


}
}
