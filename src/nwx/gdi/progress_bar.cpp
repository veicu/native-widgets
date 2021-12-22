#include "progress_bar.hpp"
#include "painter.hpp"

#include <nwx/core/wstring.hpp>
#include <nwx/gui/window_private.hpp>


namespace nwx
{
namespace gdi
{


/**
    Constructor.
*/
progress_bar::progress_bar( nwx::gui::window* parent ) : control( parent ),
    m_min( 0 ),
    m_max( 0 ),
    m_value( 0 ),
    m_pixel_width( 0 )
{
    initialize();
}

/**
    Constructor.
*/
progress_bar::progress_bar( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height ),
    m_min( 0 ),
    m_max( 0 ),
    m_value( 0 ),
    m_pixel_width( 0 )
{
    initialize();
}

/**
    Constructor.
*/
progress_bar::progress_bar( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height ) : control( parent, x, y, width, height ),
    m_min( 0 ),
    m_max( 0 ),
    m_value( 0 ),
    m_pixel_width( 0 )
{
    initialize();
}

/**

*/
void progress_bar::minimum( double min )
{
    m_min = min;
}

/**

*/
double progress_bar::minimum() const
{
    return m_min;
}

/**

*/
void progress_bar::maximum( double max )
{
    m_max = max;
}

/**

*/
double progress_bar::maximum() const
{
    return m_max;
}

/**

*/
void progress_bar::value( double value )
{
    m_value = value;

    double delta = m_max - m_min;
    double norm_value = value - m_min;

    if( value < m_min )
    {
        norm_value = 0;
    }
    else if( value > m_max )
    {
        norm_value = delta;
    }

    m_pixel_width = int( ( double( width() ) / delta ) * norm_value );
    update();
}

/**

*/
double progress_bar::value() const
{
    return m_value;
}

/**

*/
void progress_bar::initialize()
{
    //do_paint( true );

    nwx::gui::window_info wi;
    wi.class_name = "NWX_GDI_ProgressBar";
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE;

    d->register_class( wi );
    d->create_window( wi );
    use_default_font();
}

/**

*/
void progress_bar::on_paint()
{
    painter p( this );

    p.pen(nwx::gui::color( 31, 80, 115 ) );
    p.brush(nwx::gui::color( 32,77,109 ) );
    p.draw_rect( 0, 0 , width(), height() );

    p.pen(nwx::gui::color( 11, 126, 203 ) );
    p.brush(nwx::gui::color( 0, 151, 251 ) );
    p.draw_rect( 0, 0 , m_pixel_width, height() );
}


}
}
