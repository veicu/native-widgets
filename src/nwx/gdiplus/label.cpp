/**

    ...

*/


#include "label.hpp"
#include <nwx/core/wstring.hpp>

#include <gdiplus.h>


namespace nwx
{
namespace gdiplus
{


label::label( widget* parent ) : widget( parent )
{

}

label::label( widget* parent, int x, int y, int width, int height ) : widget( parent, x, y, width, height )
{

}

label::label( widget* parent, const std::string& txt, int x, int y, int width, int height ) : widget( parent, x, y, width, height ), m_text( txt )
{

}

void label::text( const std::string& txt )
{
    m_text = txt;

    //nwx::str::wide_string ws( m_text );
    //::SetWindowText( handle().h(), ws.lpcwstr() );
}

std::string label::text() const
{
    return m_text;
}

void label::draw( HDC device )
{
    nwx::core::wstring ws( m_text );

    Gdiplus::Graphics g( device );

    const Gdiplus::FontFamily font_family( L"Calibri", NULL );
    Gdiplus::Font font( &font_family, 48.00, Gdiplus::FontStyleBold, Gdiplus::UnitPixel );

    //Gdiplus::LinearGradientBrush brush(Gdiplus::Rect( 0, 0, width(), height() ), Gdiplus::Color::Red, Gdiplus::Color::Yellow, Gdiplus::LinearGradientModeHorizontal);
    Gdiplus::SolidBrush brush( Gdiplus::Color( 255, 0, 151, 251 ) );

    g.SetTextRenderingHint( Gdiplus::TextRenderingHintAntiAlias );
    Gdiplus::Status st = g.DrawString( ws.lpcwstr(), -1, &font, Gdiplus::PointF( x(), y() ), &brush );

    //const Gdiplus::FontFamily font_family( L"Calibri", NULL );
    //Gdiplus::Font font_1( &font_family, 48.00, Gdiplus::FontStyleBold, Gdiplus::UnitPixel );
    //Gdiplus::Font font_2( &font_family, 20.00, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel );
    //Gdiplus::SolidBrush oBrush( Gdiplus::Color( 128, 255, 255, 255 ) );
    //g.SetTextRenderingHint( Gdiplus::TextRenderingHintAntiAlias );

    //g.DrawString( L"17:27", -1, &font_1, Gdiplus::PointF( 0.0, 300.0 ), &oBrush );
    //g.DrawString( L"Tuesday", -1, &font_2, Gdiplus::PointF( 6.0, 350.0 ), &oBrush );
    //g.DrawString( L"14. October 2021", -1, &font_2, Gdiplus::PointF( 6.0, 370.0 ), &oBrush );
}


}
}
