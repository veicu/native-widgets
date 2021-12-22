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

#include <nwx/comctl/file_dialog.hpp>
#include <nwx/comctl/timer.hpp>
#include <nwx/comctl/use_visual_styles.hpp>

#include <sstream>


class my_main_window : public nwx::gui::main_window
{
public:

    my_main_window() : nwx::gui::main_window( "Example Window", 25, 25, 250, 350 )
    {
        m_button_1       = new nwx::comctl::button( this, "B1", 5, 10, 100, 25 );
        m_button_2       = new nwx::comctl::button( this, "B2", 110, 10, 100, 25 );
        m_button_3       = new nwx::comctl::button( this, "...", 215, 10, 25, 25 );
        m_label_1        = new nwx::comctl::label( this, "L1", 5, 45, 115, 15 );
        m_radio_button_1 = new nwx::comctl::radio_button( this, "RB1", 125, 45, 115, 15 );
        m_label_2        = new nwx::comctl::label( this, "L2", 5, 70, 235, 25 );
        m_edit_1         = new nwx::comctl::edit( this, 5, 110, 235, 80 );
        m_combo_box_1    = new nwx::comctl::combo_box( this, 5, 200, 235, 200 ); // heigth inclusive popup?

        m_combo_box_1->add_item( "Audi" );
        m_combo_box_1->add_item( "BMW" );
        m_combo_box_1->add_item( "Mercedes" );
        m_combo_box_1->add_item( "VW" );

        m_button_1->clicked.connect( [this](){ on_b1_clicked(); } );
        m_button_2->clicked.connect( [this](){ on_b2_clicked(); } );
        m_button_3->clicked.connect( [this](){ on_b3_clicked(); } );
        m_combo_box_1->selection_changed.connect( [this]( int index ){ on_cb1_selection_changed( index ); } );

        nwx::gui::font* f1 = nwx::gui::font::bold_font( "Tahoma", 20 );
        nwx::gui::font* f2 = nwx::gui::font::bold_italic_font( "SegoeUI", 24, nwx::gui::font::quality::cleartype );

        m_button_1->font( f1 );
        m_label_2->font( f2 );
    }

private:

    void on_b1_clicked()
    {
        if( m_button_2->enabled() )
        {
            m_button_2->enable( false );
        }
        else
        {
            m_button_2->enable( true );
        }
    }

    void on_b2_clicked()
    {
        if( m_button_1->enabled() )
        {
            m_button_1->enable( false );
        }
        else
        {
            m_button_1->enable( true );
        }
    }

    void on_b3_clicked()
    {
        pos( x() + 10, y()+ 10 );
    }

    void on_cb1_selection_changed( int index )
    {
        std::stringstream ss;
        ss << "selected: " << index << std::endl;
        m_label_2->text( ss.str() );
    }

    nwx::comctl::button*       m_button_1;
    nwx::comctl::button*       m_button_2;
    nwx::comctl::button*       m_button_3;
    nwx::comctl::label*        m_label_1;
    nwx::comctl::label*        m_label_2;
    nwx::comctl::radio_button* m_radio_button_1;
    nwx::comctl::edit*         m_edit_1;
    nwx::comctl::combo_box*    m_combo_box_1;
};


int main( int argc, char *argv[] )
{
    nwx::core::application app;

    my_main_window mw;

    mw.show();
    mw.update();

    return app.exec();
}
