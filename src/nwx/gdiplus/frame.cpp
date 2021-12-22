/**

    ...

*/


#include "frame.hpp"
#include <gdiplus.h>


namespace nwx
{
namespace gdiplus
{


frame::frame( widget* parent ) : widget( parent ),
    m_border_color(),
    m_background_color(),
    m_draw_border( false )
{

}

frame::frame( widget* parent, int x, int y, int width, int height ) : widget( parent, x, y, width, height ),
    m_border_color(),
    m_background_color(),
    m_draw_border( false )
{

}

frame::frame( widget* parent, const std::string& txt, int x, int y, int width, int height ) : widget( parent, x, y, width, height ),
    m_border_color(),
    m_background_color(),
    m_draw_border( false )
{

}

/**

*/
void frame::border_color( nwx::gui::color c )
{
    m_border_color = c;
    m_draw_border = true;
}

/**

*/
void frame::background_color( nwx::gui::color c )
{
    m_background_color = c;
}

void frame::draw( HDC device )
{
    Gdiplus::Graphics gr( device );
    //Gdiplus::SolidBrush brush( Gdiplus::Color( 128, m_background_color.red(), m_background_color.green(), m_background_color.blue() ) );
    Gdiplus::SolidBrush brush( Gdiplus::Color( 255, 0, 128, 255 ) );
    gr.FillRectangle( &brush, 0, 0, width(), height() );
}


}
}
