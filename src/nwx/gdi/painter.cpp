#include "painter.hpp"
#include <nwx/gui/widget.hpp>
#include <nwx/gui/window_private.hpp>
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>


using namespace nwx::gdi;


class nwx::gdi::painter_private
{
public:
    painter_private(): ps(), hdc( NULL ), hfont(NULL), original( NULL ), hdc_window( NULL ), do_double_buffer( false ), hdc_mem( NULL ), hbitmap_mem( NULL ), original_mem( NULL )
    {
    
    }

    ~painter_private()
    {
    
    }

    PAINTSTRUCT ps;
    HDC hdc;
    HFONT hfont;
    HGDIOBJ original;

    HDC hdc_window;

    bool do_double_buffer;
    HDC hdc_mem;
    HBITMAP hbitmap_mem;
    HGDIOBJ original_mem;
};

/**
    Constructor.
*/
painter::painter( nwx::gui::widget* w, bool double_buffer /* = false */ ) : m_widget( w ), d( 0 ),
m_pen_color(),
m_brush_color(),
m_text_color()
{
    d = new painter_private();
    d->hdc_window = ::BeginPaint( m_widget->d->window_resource, &d->ps );

    d->hdc = d->hdc_window;

    if( double_buffer )
    {
        d->hdc_mem = ::CreateCompatibleDC( NULL );
        d->hbitmap_mem = ::CreateCompatibleBitmap( d->hdc_window, m_widget->width(), m_widget->height() );
        d->original_mem = ::SelectObject( d->hdc_mem, d->hbitmap_mem );
        ::BitBlt(d->hdc_mem,0,0,m_widget->width(), m_widget->height(), NULL, NULL, NULL, BLACKNESS );
        d->hdc = d->hdc_mem;
        d->do_double_buffer = true;
    }

    // Saving the original gdi object
    d->original = ::SelectObject( d->hdc, ::GetStockObject( DC_PEN ) );
    ::SelectObject( d->hdc, ::GetStockObject( DC_BRUSH ) );
    //::SelectObject( d->hdc, ::GetStockObject( NULL_BRUSH ) );
}

/**
    Destructor.
*/
painter::~painter()
{
    if( d->do_double_buffer )
    {
        ::BitBlt( d->hdc_window, 0, 0, m_widget->width(), m_widget->height(), d->hdc_mem, 0, 0, SRCCOPY );
        ::SelectObject( d->hdc_mem, d->original_mem );
        ::DeleteObject( d->hbitmap_mem );
        ::DeleteDC( d->hdc_mem );
        //::DeleteDC( hdc );
        //::InvalidateRect( m_widget->resource().handle(), NULL, TRUE );
    }

    // Restoring the original gdi object
    ::SelectObject( d->hdc_window, d->original );
    ::EndPaint( m_widget->d->window_resource, &d->ps );
    delete d;
}


void painter::use_double_buffer()
{
    //d->hdc_mem = ::CreateCompatibleDC( d->hdc_window );
    d->hdc_mem = ::CreateCompatibleDC( NULL );
    d->hbitmap_mem = ::CreateCompatibleBitmap( d->hdc_window, m_widget->width(), m_widget->height() );
    //d->hbitmap_mem = ::CreateBitmap( m_widget->width(), m_widget->height(), 1, 24, NULL );
    d->original_mem = ::SelectObject( d->hdc_mem, d->hbitmap_mem );
    ::BitBlt(d->hdc_mem,0,0,m_widget->width(), m_widget->height(), NULL, NULL, NULL, BLACKNESS);
    d->hdc = d->hdc_mem;
    d->do_double_buffer = true;
}

/**

*/
void painter::draw_rect( int x, int y, int width, int height )
{
    ::Rectangle( d->hdc, x, y, x + width, y + height );
}

/**

*/
void painter::fill_rect( int x, int y, int width, int height )
{
    ::Rectangle( d->hdc, x, y, x + width + 1, y + height + 1 );
}

/**

*/
void painter::draw_text( const std::string& text, int x, int y, int width, int height )
{
    HFONT hFont, hOldFont;

    RECT rect;
    rect.left = x;
    rect.right = x + width;
    rect.top = y;
    rect.bottom = y + height;

    //::SetBkColor( hdc, RGB(0,188,242) );
    ::SetBkMode( d->hdc, TRANSPARENT);

    if( d->hfont )
    {
        hFont = d->hfont;
    }
    else
    {
        // Retrieve a handle to the variable stock font
        hFont = (HFONT)::GetStockObject( ANSI_VAR_FONT );
    }

    // Select the font into the specified device context
    if(hOldFont = (HFONT)::SelectObject( d->hdc, hFont))
    {
        nwx::core::wstring ws( text );
        //::TextOut( d->hdc, 0, 0, ws.lpcwstr(), ws.lengthandle() );
        ::DrawText( d->hdc, ws.lpcwstr(), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );

        // Restore the original font
        ::SelectObject(d->hdc, hOldFont);
    }
}

void painter::draw_text_plus( const std::string& text, int x, int y, int width, int height )
{
/*
    nwx::nwx::str::wide_string ws( text );

    Gdiplus::Graphics gr( d->hdc );
    //Gdiplus::Font font(&Gdiplus::FontFamily(L"Arial"), 12);
    Gdiplus::Font font( d->hdc, d->hfont );
    Gdiplus::LinearGradientBrush brushandle(Gdiplus::Rect(0,0,100,100), Gdiplus::Color::Red, Gdiplus::Color::Yellow, Gdiplus::LinearGradientModeHorizontal);
    gr.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);
    Gdiplus::Status st = gr.DrawString(ws.lpcwstr(), -1, &font, Gdiplus::PointF(0, 0), &brush);
    //st == Ok
*/
}

/**

*/
void painter::no_pen()
{
    ::SelectObject( d->hdc, ::GetStockObject( NULL_PEN ) );
}

/**

*/
void painter::pen( const nwx::gui::color& c )
{
    m_pen_color = c;

    ::SetDCPenColor( d->hdc, RGB( m_pen_color.red(), m_pen_color.green(), m_pen_color.blue() ) );
}

/**

*/
void painter::no_brush()
{
    ::SelectObject( d->hdc, ::GetStockObject( NULL_BRUSH ) );
}

/**

*/
void painter::brush( const nwx::gui::color& c )
{
    m_brush_color = c;

    ::SetDCBrushColor( d->hdc, RGB( m_brush_color.red(), m_brush_color.green(), m_brush_color.blue() ) );
}

/**

*/
void painter::text_color( const nwx::gui::color& c )
{
    m_text_color = c;

    ::SetTextColor( d->hdc, RGB( m_text_color.red(), m_text_color.green(), m_text_color.blue() ) );
}

/**

*/
void painter::font(nwx::gui::font* f )
{
    d->hfont = f->resource();
}
