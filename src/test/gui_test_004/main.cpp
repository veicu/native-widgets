#include <nwx/core/application.hpp>

#include <nwx/system/monitor.hpp>
#include <nwx/system/memory.hpp>

#include <nwx/gdiplus/main_window.hpp>
#include <nwx/gdiplus/label.hpp>
#include <nwx/gdiplus/frame.hpp>
#include <nwx/gdiplus/canvas.hpp>

#include <nwx/gui/color.hpp>

#include <sstream>


class my_main_window : public nwx::gdiplus::main_window
{
public:
    my_main_window() : nwx::gdiplus::main_window( "Example Window", 0, 0, 300, 150, nwx::gdiplus::main_window::window_type::normal_top_level/*_no_focus*/ )
    {
        my_text = "Memory";

        nwx::system::monitor moni;
        geometry( moni.work_right() - width(), 0, width(), moni.work_bottom() );
        
        m_fxfr1 = new nwx::gdiplus::frame( 0, 0, 0, 300, 10 );
        m_fxlb1 = new nwx::gdiplus::label( 0, 15, 50, 300, 50 );
        m_fxlb2 = new nwx::gdiplus::label( 0, 15, 100, 150, 50 );
        m_fxlb3 = new nwx::gdiplus::label( 0, 15, 150, 150, 25 );

        m_fxfr1->background_color( nwx::gui::color( 255, 0, 0 ) );

        m_fxlb1->text( "Temperature" );

        m_fxlb2->text( my_text );

        std::ostringstream oss;
        oss << 4; //nwx::system::memory();
        oss << "GB";
        m_fxlb3->text( oss.str() );


        //cv()->clear();
        //cv()->fill_rectangle( 0, 0, width(), height(), nwx::gui::color( 128, 0, 0, 128 ) );
        draw2();

        //z_order( nwx::gui::window::z_order::topmost );
    }

    void draw2()
    {
        draw( device() );

        m_fxfr1->draw( device() );
        m_fxlb1->draw( device() );
        m_fxlb2->draw( device() );
        m_fxlb3->draw( device() );
    }

    virtual void on_mouse_down()
    {
        cv()->clear();
        cv()->fill_rectangle( 0, 0, width(), height(), nwx::gui::color( 255, 255, 0, 0 ) );

        //int brk = 1;
        //my_text = "BLUP";
        //m_fxlb2->text( my_text );
        //draw2();

        update();
    }

    virtual void on_mouse_up()
    {
        cv()->clear();
        cv()->fill_rectangle( 0, 0, width(), height(), nwx::gui::color( 128, 0, 0, 0 ) );

        //int brk = 1;
        //my_text = "BLA";
        //m_fxlb2->text( my_text );
        //draw2();

        update();
    }

private:
    nwx::gdiplus::frame* m_fxfr1;
    nwx::gdiplus::label* m_fxlb1;
    nwx::gdiplus::label* m_fxlb2;
    nwx::gdiplus::label* m_fxlb3;

    std::string my_text;
};


int main( int argc, char *argv[] )
{
    nwx::core::application app;

    my_main_window mw;

    mw.show();
    mw.update();

    return app.exec();
}
