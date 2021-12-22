#include <nwx/core/application.hpp>
#include <nwx/core/signal.hpp>

#include <nwx/gui/main_window.hpp>
#include <nwx/gui/color.hpp>
#include <nwx/gui/font.hpp>

#include <nwx/comctl/button.hpp>
#include <nwx/comctl/label.hpp>
#include <nwx/comctl/edit.hpp>
#include <nwx/comctl/combo_box.hpp>
#include <nwx/comctl/radio_button.hpp>

#include <nwx/gdi/demo_control.hpp>
#include <nwx/gdi/frame.hpp>
#include <nwx/gdi/progress_bar.hpp>
#include <nwx/gdi/label.hpp>

#include <nwx/comctl/file_dialog.hpp>
#include <nwx/comctl/timer.hpp>
#include <nwx/comctl/use_visual_styles.hpp>

#include <sstream>


class my_main_window : public nwx::gui::main_window
{
public:

    my_main_window() : nwx::gui::main_window( "Example Window", 25, 25, 250, 350 )
    {
        m_commctrl_button_1       = new nwx::comctl::button( this, "B1", 5, 10, 100, 25 );
        m_commctrl_button_2       = new nwx::comctl::button( this, "B2", 110, 10, 100, 25 );
        m_commctrl_button_3       = new nwx::comctl::button( this, "...", 215, 10, 25, 25 );
        m_commctrl_label_1        = new nwx::comctl::label( this, "L1", 5, 45, 115, 15 );
        m_commctrl_radio_button_1 = new nwx::comctl::radio_button( this, "RB1", 125, 45, 115, 15 );
        m_commctrl_label_2        = new nwx::comctl::label( this, "L2", 5, 70, 235, 25 );
        m_commctrl_edit_1         = new nwx::comctl::edit( this, 5, 110, 235, 80 );
        m_commctrl_combo_box_1    = new nwx::comctl::combo_box( this, 5, 200, 235, 200 ); // heigth inclusive popup?

        m_cc1 = new nwx::gdi::demo_control( this, "Hello", 5, 235, 115, 30 );
        m_cc2 = new nwx::gdi::demo_control( this, "World", 125, 235, 115, 30 );

        //m_gdi_frame_1        = new nwx::gdi::frame( this, 0, 270, 250, 75 );
        m_gdi_progress_bar_1 = new nwx::gdi::progress_bar( this, 5, 280, 240, 10 );
        m_gdi_progress_bar_2 = new nwx::gdi::progress_bar( this, 5, 295, 240, 10 );
        m_gdi_label_1        = new nwx::gdi::label( this, "Hello 123", 0, 310, 250, 25 );

        //m_gdi_frame_1->border_color( nwx::gui::color(250, 0, 0 ) );
        //m_gdi_frame_1->background_color( nwx::gui::color(60, 70, 80 ) );

        //DWORD sys_color = ::GetSysColor( COLOR_3DFACE );
        //m_gdi_frame_1->background_color( nwx::gui::color(GetRValue( sys_color ), GetGValue( sys_color ), GetBValue( sys_color ) ) );

        m_gdi_progress_bar_1->minimum( -100 );
        m_gdi_progress_bar_1->maximum( 100 );
        m_gdi_progress_bar_1->value( 90 );

        m_gdi_progress_bar_2->minimum( 0 );
        m_gdi_progress_bar_2->maximum( 100 );
        m_gdi_progress_bar_2->value( 50 );

        m_commctrl_combo_box_1->add_item( "Audi" );
        m_commctrl_combo_box_1->add_item( "BMW" );
        m_commctrl_combo_box_1->add_item( "Mercedes" );
        m_commctrl_combo_box_1->add_item( "VW" );

        m_connection = m_commctrl_button_1->clicked.connect( std::bind( &my_main_window::on_b1_clicked, this ) );
        //m_connection.disconnect();
        //m_commctrl_button_1->clicked();

        m_commctrl_button_2->clicked.connect( std::bind( &my_main_window::on_b2_clicked, this ) );
        m_commctrl_button_3->clicked.connect( std::bind( &my_main_window::on_b3_clicked, this ) );
        m_commctrl_combo_box_1->selection_changed.connect( std::bind( &my_main_window::on_cb1_selection_changed, this, std::placeholders::_1 ) );
        m_cc1->clicked.connect( std::bind( &my_main_window::on_cc1_clicked, this ) );
        m_cc2->clicked.connect( std::bind( &my_main_window::on_cc2_clicked, this ) );

        //nwx::gui::font::pointer f1 = nwx::gui::font::bold_font( "Tahoma", 20 );
        //nwx::gui::font::pointer f2 = nwx::gui::font::bold_italic_font( "SegoeUI", 24, nwx::gui::font::quality::cleartype );

        nwx::gui::font* f1 = nwx::gui::font::bold_font( "Tahoma", 20 );
        nwx::gui::font* f2 = nwx::gui::font::bold_italic_font( "SegoeUI", 24, nwx::gui::font::quality::cleartype );

        m_commctrl_button_1->font( f1 );
        m_commctrl_label_2->font( f2 );
        //m_gdi_label_1->font( nwx::font::create( "Tahoma", 13 ) );

        m_gdi_label_1->font( f2 );
        m_gdi_label_1->foreground_color( nwx::gui::color( 255, 255, 255 ) );
        m_gdi_label_1->background_color( nwx::gui::color( 128, 128, 128 ) );

        //m_cc1->font( f1 );

        //m_commctrl_button_1->enable( false );

        //m_timer = new nwx::timer( 5000 );
    }

private:

    void on_b1_clicked()
    {
        m_gdi_label_1->text("ABC");
        //std::string s = m_commctrl_edit_1->text();
        //m_commctrl_label_1->text( s );
        //m_gdi_frame_1->hide();
        
        //delete m_gdi_label_1;
        //m_gdi_label_1 = 0;
    }

    void on_b2_clicked()
    {
        if( m_commctrl_button_1->enabled() )
        {
            m_commctrl_button_1->enable( false );
        }
        else
        {
            m_commctrl_button_1->enable( true );
        }
    }

    void on_b3_clicked()
    {
        //m_gdi_progress_bar_1->value( m_gdi_progress_bar_1->value() + 1 );

        //position( x() + 100, y()+ 100 );

        //get_existing_directory();
    }

    void on_cb1_selection_changed( int index )
    {
        std::stringstream ss;
        ss << "selected: " << index << std::endl;
        m_commctrl_label_2->text( ss.str() );
    }

    void on_cc1_clicked()
    {
        std::string s1 = "clicked";
        std::string s2 = "...";
        //m_cc1->text( s1 );
        //m_cc2->text( s2 );
    }

    void on_cc2_clicked()
    {
        std::string s1 = "...";
        std::string s2 = "clicked";
        //m_cc1->text( s1 );
        //m_cc2->text( s2 );
    }

    nwx::comctl::button* m_commctrl_button_1;
    nwx::comctl::button* m_commctrl_button_2;
    nwx::comctl::button* m_commctrl_button_3;
    nwx::comctl::label* m_commctrl_label_1;
    nwx::comctl::label* m_commctrl_label_2;
    nwx::comctl::radio_button* m_commctrl_radio_button_1;
    nwx::comctl::edit* m_commctrl_edit_1;
    nwx::comctl::combo_box* m_commctrl_combo_box_1;
    nwx::gdi::demo_control* m_cc1;
    nwx::gdi::demo_control* m_cc2;
    nwx::gdi::frame* m_gdi_frame_1;
    nwx::gdi::progress_bar* m_gdi_progress_bar_1;
    nwx::gdi::progress_bar* m_gdi_progress_bar_2;
    nwx::gdi::label* m_gdi_label_1;

    nwx::timer* m_timer;

    nwx::core::signal_connection m_connection;
};


int main( int argc, char *argv[] )
{
    nwx::core::application app;

    my_main_window mw;

    mw.show();
    mw.update();

    return app.exec();
}
