#include "demo_control.hpp"
#include "painter.hpp"
#include <nwx/core/wstring.hpp>
#include <nwx/gui/window_private.hpp>


using namespace nwx::gdi;


demo_control::demo_control( nwx::gui::window* parent ) : control( parent )
{
    initialize();
}

demo_control::demo_control( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height )
{
    initialize();
}

demo_control::demo_control( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height ) : control( parent, x, y, width, height ), m_text( txt )
{
    initialize();
}

void demo_control::text( const std::string& txt )
{
    m_text = txt;
    update();
}

std::string demo_control::text() const
{
    return m_text;
}

void demo_control::initialize()
{
    m_click = false;

    nwx::gui::window_info wi;
    wi.class_name = "NWX_GDI_DemoControl";
    //wi.register_class_style = CS_DBLCLKS /*| CS_GLOBALCLASS | CS_HREDRAW | CS_VREDRAW*/;
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE;

    //wi.background_red = 255;
    //wi.background_green = 128;
    //wi.background_blue = 64;

    d->register_class( wi );
    d->create_window( wi );
    use_default_font();

    m_erase_background = true;
}

void demo_control::on_paint()
{
    painter p( this );
    //p.use_double_buffer();

    if( false /*mouse_over()*/ )
    {
        p.pen(nwx::gui::color( 30, 117, 187 ) );
        p.brush(nwx::gui::color( 30, 117, 187 ) );
    }
    else
    {
        p.pen(nwx::gui::color( 30, 117, 187 ) );
        p.brush( nwx::gui::color( 0, 188, 242 ) );
    }

    if( m_click )
    {
        p.pen(nwx::gui::color( 0, 0, 0 ) );
    }

    p.draw_rect( 0, 0, width(), height() );
    p.text_color(nwx::gui::color( 255, 0, 0 ) );
    p.draw_text( m_text, 0, 0, width(), height() );
}

void demo_control::on_mouse_down()
{
    m_click = true;
    update();
}

void demo_control::on_mouse_up()
{
    if( m_click )
    {
        m_click = false;
        update();
        clicked();
    }
}

void demo_control::on_mouse_enter()
{
    update();
}

void demo_control::on_mouse_leave()
{
    update();
}
