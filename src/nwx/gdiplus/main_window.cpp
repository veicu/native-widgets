/**

    ...

*/


#include "main_window.hpp"
#include <nwx/gui/window_private.hpp>
#include <nwx/core/wstring.hpp>

#include <nwx/gui/window_info.hpp>

#include <nwx/core/use_windows.hpp>
#include <nwx/core/use_gdiplus.hpp>


namespace nwx
{
namespace gdiplus
{


class main_window_private
{
public:
    main_window_private()
    {

    }

    void startup_gdi_plus()
    {
        ::Gdiplus::GdiplusStartup( &m_gdi_plus_token, &m_gdi_plus_startup_input, nullptr );
    }

    void shutdown_gdi_plus()
    {
        ::Gdiplus::GdiplusShutdown( m_gdi_plus_token );
    }

private:
    ULONG_PTR m_gdi_plus_token;
    Gdiplus::GdiplusStartupInput m_gdi_plus_startup_input;
};


main_window::main_window( const std::string& txt, int x, int y, int width, int height, window_type wt ) : nwx::gui::window( 0, x, y, width, height ), m_text( txt ), m_canvas( width, height )
{
    initialize( wt );

    d = new main_window_private();
    d->startup_gdi_plus();
}

main_window::~main_window()
{
    d->shutdown_gdi_plus();
    delete d;
    d = 0;
}

void main_window::geometry( int x, int y, int width, int height )
{
    m_canvas.resize( width, height );
    window::geometry( x, y, width, height );
}

void main_window::text( const std::string& txt )
{
    m_text = txt;

    nwx::core::wstring ws( m_text );
    ::SetWindowText( nwx::gui::window::d->window_resource, ws.lpcwstr() );
}

std::string main_window::text() const
{
    return m_text;
}

void main_window::initialize( window_type wt )
{
    nwx::gui::window_info wi;
    wi.class_name = "NTWXMainWindow";
    wi.window_name = m_text;
    //wi.register_class_style = CS_DBLCLKS;

    wi.create_window_reg_style = WS_POPUP;
    //wi.create_window_ext_style = WS_EX_LAYERED;
    //wi.create_window_ext_style = WS_EX_TOOLWINDOW | WS_EX_LAYERED;

    switch( wt )
    {
    case window_type::normal:
        wi.create_window_ext_style = WS_EX_LAYERED;
        break;
    case window_type::normal_top_level:
        wi.create_window_ext_style = WS_EX_LAYERED | WS_EX_TOPMOST;
        break;
    case window_type::normal_top_level_no_focus:
        wi.create_window_ext_style = WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TRANSPARENT;
        break;
    case window_type::tool_window:
        wi.create_window_ext_style = WS_EX_LAYERED | WS_EX_TOOLWINDOW;
        break;
    case window_type::tool_window_top_level:
        wi.create_window_ext_style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;
        break;
    case window_type::tool_window_top_level_no_focus:
        wi.create_window_ext_style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_TRANSPARENT;
        break;
    default:
        break;
    }


    //wi.background.red( 0 );
    //wi.background.green( 0 );
    //wi.background.blue( 0 );

    nwx::gui::window::d->register_class( wi );
    nwx::gui::window::d->create_window( wi );
    use_default_font();
}

/**

*/
void main_window::update()
{
    BLENDFUNCTION blend = {0};
    blend.BlendOp = AC_SRC_OVER;
    blend.SourceConstantAlpha = 255;
    blend.AlphaFormat = AC_SRC_ALPHA;

    POINT ptPos = {x(), y()};
    SIZE sizeWnd = {width(), height()};
    POINT ptSrc = {0, 0};

    //HWND hwnd = resource().handle();
    HWND hwnd = nwx::gui::window::d->window_resource;
    //m_canvas.create_dc();
    if( !::UpdateLayeredWindow( hwnd, NULL, &ptPos, &sizeWnd, device(), &ptSrc, 0, &blend, ULW_ALPHA ) )
    {
        int brk = 1;
        //::RemoveWindowExStyle( WS_EX_LAYERED );
        //::AddWindowExStyle( WS_EX_LAYERED );
        //::UpdateLayeredWindow( hwnd, NULL, &ptPos, &sizeWnd, device(), &ptSrc, 0, &blend, ULW_ALPHA )
    }
    //m_canvas.delete_dc();
}

/**

*/
void main_window::draw( HDC device )
{
    Gdiplus::Graphics g( device );

    Gdiplus::SolidBrush blackBrush( Gdiplus::Color( 128, 0, 0, 0 ) );
    g.FillRectangle( &blackBrush, 0, 0, width(), height() );

    //const Gdiplus::FontFamily font_family( L"Calibri", NULL );
    //Gdiplus::Font font_1( &font_family, 48.00, Gdiplus::FontStyleBold, Gdiplus::UnitPixel );
    //Gdiplus::Font font_2( &font_family, 20.00, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel );
    //Gdiplus::SolidBrush oBrush( Gdiplus::Color( 128, 255, 255, 255 ) );
    //g.SetTextRenderingHint( Gdiplus::TextRenderingHintAntiAlias );

    //g.DrawString( L"17:27", -1, &font_1, Gdiplus::PointF( 0.0, 300.0 ), &oBrush );
    //g.DrawString( L"Tuesday", -1, &font_2, Gdiplus::PointF( 6.0, 350.0 ), &oBrush );
    //g.DrawString( L"14. October 2021", -1, &font_2, Gdiplus::PointF( 6.0, 370.0 ), &oBrush );
}

/**

*/
HDC main_window::device()
{
    return m_canvas.device();
}

void main_window::cv_clear()
{
    m_canvas.clear();
}


}
}
