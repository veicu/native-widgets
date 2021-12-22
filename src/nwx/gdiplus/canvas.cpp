/**

    ...

*/


#include "canvas.hpp"
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>
#include <nwx/core/use_gdiplus.hpp>


namespace nwx
{
namespace gdiplus
{


class canvas_private
{
public:
    canvas_private() : hdc_memory( 0 )
    {
        hdc_memory = ::CreateCompatibleDC( NULL );
    }

    ~canvas_private()
    {
        ::DeleteDC( hdc_memory );
        ::DeleteObject( dib_section_buffer );
        dib_section_buffer_pixels = nullptr;
    }

    HDC device()
    {
        return hdc_memory;
    }

    void create_dc()
    {
        hdc_memory = ::CreateCompatibleDC( NULL );
        ::SelectObject( hdc_memory, dib_section_buffer );
    }

    void delete_dc()
    {
        ::DeleteDC( hdc_memory );
    }

    void resize( int width_, int height_ )
    {
        width = width_;
        height = height_;

        bla();
        //bla2();
    }

    void bla()
    {
        //HBITMAP dib_section_buffer;
        //LPDWORD dib_section_buffer_pixels;

        BITMAPV4HEADER bh = {sizeof(BITMAPV4HEADER)};
        bh.bV4Width = (LONG) width;
        bh.bV4Height = -(LONG) height; // Top-down DIB
        bh.bV4Planes = 1;
        bh.bV4BitCount = 32;
        bh.bV4V4Compression = BI_BITFIELDS;
        bh.bV4RedMask = 0x00FF0000;
        bh.bV4GreenMask = 0x0000FF00;
        bh.bV4BlueMask = 0x000000FF;
        bh.bV4AlphaMask = 0xFF000000;

        dib_section_buffer = ::CreateDIBSection
        (
            nullptr,
            (BITMAPINFO*)&bh,
            DIB_RGB_COLORS,
            (void**)&dib_section_buffer_pixels,
            nullptr,
            0
        );

        ::SelectObject( hdc_memory, dib_section_buffer );
    }

    void bla2()
    {
        gdi_bitmap = new Gdiplus::Bitmap( width, height, width * 4, PixelFormat32bppPARGB, (BYTE*)dib_section_buffer_pixels );
        gdi_graphics = new Gdiplus::Graphics( gdi_bitmap );
    }

    Gdiplus::Graphics* gdi_graphics;
    Gdiplus::Bitmap* gdi_bitmap;

private:
    HDC hdc_memory;
    HBITMAP dib_section_buffer;
    LPDWORD dib_section_buffer_pixels;

    int width;
    int height;
};


/**

*/
canvas::canvas( int width, int height )
{
    d = new canvas_private();
    d->resize( width, height );
}

/**

*/
canvas::~canvas()
{
    delete d;
}

/**

*/
void canvas::resize( int width, int height )
{
    d->resize( width, height );
}

/**

*/
HDC canvas::device()
{
    return d->device();
}

void canvas::create_dc()
{
    d->create_dc();
}

void canvas::delete_dc()
{
    d->delete_dc();
}

void canvas::clear()
{
    d->gdi_graphics->Clear( Gdiplus::Color( 0, 0, 0, 0 ) );
}

void canvas::fill_rectangle( int x, int y, int width, int height, const nwx::gui::color& color )
{
    //Gdiplus::Graphics gr( device );
    //Gdiplus::SolidBrush brush( Gdiplus::Color( 128, m_background_color.red(), m_background_color.green(), m_background_color.blue() ) );
    Gdiplus::SolidBrush brush( Gdiplus::Color( color.alpha(), color.red(), color.green(), color.blue() ) );
    d->gdi_graphics->FillRectangle( &brush, x, y, width, height );
}

void canvas::draw_text( int x, int y, const nwx::gui::color& color, const std::string& text )
{
    nwx::core::wstring ws( text );

    //Gdiplus::Graphics gr( device );

    const Gdiplus::FontFamily font_family( L"Calibri", NULL );
    Gdiplus::Font font_1( &font_family, 48.00, Gdiplus::FontStyleBold, Gdiplus::UnitPixel );

    //Gdiplus::LinearGradientBrush brush(Gdiplus::Rect( 0, 0, width(), height() ), Gdiplus::Color::Red, Gdiplus::Color::Yellow, Gdiplus::LinearGradientModeHorizontal);
    Gdiplus::SolidBrush brush( Gdiplus::Color( color.alpha(), color.red(), color.green(), color.blue() ) );

    d->gdi_graphics->SetTextRenderingHint( Gdiplus::TextRenderingHintAntiAlias );
    Gdiplus::Status st = d->gdi_graphics->DrawString( ws.lpcwstr(), -1, &font_1, Gdiplus::PointF( x, y ), &brush );
}


}
}
