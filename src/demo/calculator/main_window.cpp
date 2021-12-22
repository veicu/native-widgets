#include "main_window.hpp"

#include <nwx/comctl/use_visual_styles.hpp>


main_window::main_window() : nwx::gui::main_window( "Calculator", 25, 25, 198, 178 )
{
    create_widgets();
    connect_signals();
    set_style();
}

void main_window::create_widgets()
{
    m_edit = new nwx::comctl::edit( this, 10, 10, 178, 20 );
    m_edit->enable( false );

    m_b1 = new nwx::comctl::button( this, "1", 10, 104, 34, 30 );
    m_b2 = new nwx::comctl::button( this, "2", 46, 104, 34, 30 );
    m_b3 = new nwx::comctl::button( this, "3", 82, 104, 34, 30 );

    m_b4 = new nwx::comctl::button( this, "4", 10, 72, 34, 30 );
    m_b5 = new nwx::comctl::button( this, "5", 46, 72, 34, 30 );
    m_b6 = new nwx::comctl::button( this, "6", 82, 72, 34, 30 );

    m_b7 = new nwx::comctl::button( this, "7", 10, 40, 34, 30 );
    m_b8 = new nwx::comctl::button( this, "8", 46, 40, 34, 30 );
    m_b9 = new nwx::comctl::button( this, "9", 82, 40, 34, 30 );

    m_b0 = new nwx::comctl::button( this, "0", 10, 136, 70, 30 );

    m_add = new nwx::comctl::button( this, "+", 118, 136, 34, 30 );
    m_sub = new nwx::comctl::button( this, "-", 118, 104, 34, 30 );
    m_mul = new nwx::comctl::button( this, "*", 118, 72, 34, 30 );
    m_div = new nwx::comctl::button( this, "/", 118, 40, 34, 30 );

    m_comma = new nwx::comctl::button( this, ",", 82, 136, 34, 30 );

    m_calc  = new nwx::comctl::button( this, "=", 154, 104, 34, 62 );
    m_clear = new nwx::comctl::button( this, "C", 154, 40, 34, 30 );
}

void main_window::connect_signals()
{
    m_b1->clicked.connect( [this](){ on_b1_clicked(); } );
    m_b2->clicked.connect( [this](){ on_b2_clicked(); } );
    m_b3->clicked.connect( [this](){ on_b3_clicked(); } );
    m_b4->clicked.connect( [this](){ on_b4_clicked(); } );
    m_b5->clicked.connect( [this](){ on_b5_clicked(); } );
    m_b6->clicked.connect( [this](){ on_b6_clicked(); } );
    m_b7->clicked.connect( [this](){ on_b7_clicked(); } );
    m_b8->clicked.connect( [this](){ on_b8_clicked(); } );
    m_b9->clicked.connect( [this](){ on_b9_clicked(); } );
    m_b0->clicked.connect( [this](){ on_b0_clicked(); } );

    m_add->clicked.connect( [this](){ on_add_clicked(); } );
    m_sub->clicked.connect( [this](){ on_sub_clicked(); } );
    m_mul->clicked.connect( [this](){ on_mul_clicked(); } );
    m_div->clicked.connect( [this](){ on_div_clicked(); } );

    m_calc->clicked.connect( [this](){ on_calc_clicked(); } );
    m_clear->clicked.connect( [this](){ on_clear_clicked(); } );
}

void main_window::set_style()
{
    //nwx::font::pointer f = nwx::font::bold_font( "Tahoma", 14 );

    //m_b1->font( f );
    //m_b2->font( f );
    //m_b3->font( f );
    //m_b4->font( f );
    //m_b5->font( f );
    //m_b6->font( f );
    //m_b7->font( f );
    //m_b8->font( f );
    //m_b9->font( f );
    //m_b0->font( f );

    //m_add->font( f );
    //m_sub->font( f );
    //m_mul->font( f );
    //m_div->font( f );
}

void main_window::on_b1_clicked()
{
    append_number( "1" );
}

void main_window::on_b2_clicked()
{
    append_number( "2" );
}

void main_window::on_b3_clicked()
{
    append_number( "3" );
}

void main_window::on_b4_clicked()
{
    append_number( "4" );
}

void main_window::on_b5_clicked()
{
    append_number( "5" );
}

void main_window::on_b6_clicked()
{
    append_number( "6" );
}

void main_window::on_b7_clicked()
{
    append_number( "7" );
}

void main_window::on_b8_clicked()
{
    append_number( "8" );
}

void main_window::on_b9_clicked()
{
    append_number( "9" );
}

void main_window::on_b0_clicked()
{
    append_number( "0" );
}

void main_window::on_add_clicked()
{
    // ...
}

void main_window::on_sub_clicked()
{
    // ...
}

void main_window::on_mul_clicked()
{
    // ...
}

void main_window::on_div_clicked()
{
    // ...
}

void main_window::on_calc_clicked()
{
    // ...
}

void main_window::on_clear_clicked()
{
    m_string = "";
    m_edit->text( m_string );
}

void main_window::append_number( const std::string& n )
{
    m_string.append( n );
    m_edit->text( m_string );
}
