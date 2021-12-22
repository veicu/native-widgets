#include "frame.hpp"
#include "painter.hpp"

#include <nwx/gui/window_private.hpp>


namespace nwx
{
namespace gdi
{


/**
    Constructor.
*/
frame::frame( nwx::gui::window* parent ) : control( parent ),
    m_border_color(),
    m_background_color(),
    m_draw_border( false )
{
    initialize();
}

/**
    Constructor.
*/
frame::frame( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height ),
    m_border_color(),
    m_background_color(),
    m_draw_border( false )
{
    initialize();
}

/**

*/
void frame::border_color(nwx::gui::color c )
{
    m_border_color = c;
    m_draw_border = true;
}

/**

*/
void frame::background_color(nwx::gui::color c )
{
    m_background_color = c;
}

/**

*/
void frame::initialize()
{
    //do_paint( true );

    nwx::gui::window_info wi;
    wi.class_name = "NWX_GDI_Frame";
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE;

    d->register_class( wi );
    d->create_window( wi );
    use_default_font();
}

/**

*/
void frame::on_paint()
{
    painter p( this );

    if( m_draw_border )
    {
        p.pen( m_border_color );
        p.brush( m_background_color );
        p.draw_rect( 0, 0, width(), height() );
    }
    else
    {
        p.no_pen();
        p.brush( m_background_color );
        p.fill_rect( 0, 0, width(), height() );
    }
}


}
}
