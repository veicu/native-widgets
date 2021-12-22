#include "label.hpp"
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
label::label( nwx::gui::window* parent ) : control( parent ),
    m_text(),
    m_foreground_color(),
    m_background_color(),
    m_font( nullptr )
{
    initialize();
}

/**
    Constructor.
*/
label::label( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height ),
    m_text(),
    m_foreground_color(),
    m_background_color(),
    m_font( nullptr )
{
    initialize();
}

/**
    Constructor.
*/
label::label( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height ) : control( parent, x, y, width, height ),
    m_text( txt ),
    m_foreground_color(),
    m_font( nullptr )
{
    initialize();
}

/**

*/
void label::text( const std::string& txt )
{
    m_text = txt;
    update();
}

/**

*/
std::string label::text() const
{
    return m_text;
}

/**

*/
void label::font(nwx::gui::font* f )
{
    m_font = f;
}

/**

*/
void label::foreground_color(nwx::gui::color c )
{
    m_foreground_color = c;
}

/**

*/
void label::background_color(nwx::gui::color c )
{
    m_background_color = c;
}

/**

*/
void label::initialize()
{
    //do_paint( true );

    nwx::gui::window_info wi;
    wi.class_name = "NWX_GDI_Label";
    //wi.create_window_ext_style = WS_EX_TRANSPARENT;
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE;

    wi.background.alpha( 0 );

    d->register_class( wi );
    d->create_window( wi );
    use_default_font();
}

/**

*/
void label::on_paint()
{
    painter p( this );

    if( m_font )
    {
        p.font( m_font );
    }

    p.no_pen();
    p.brush( m_background_color );
    p.fill_rect( 0, 0, width(), height() );

    p.text_color( m_foreground_color );
    p.draw_text( m_text, 0, 0, width(), height() );
}


}
}
