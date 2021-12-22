#include <nwx/gui/main_window.hpp>
#include <nwx/comctl/edit.hpp>
#include <nwx/comctl/button.hpp>


class main_window : public nwx::gui::main_window
{
public:

    main_window();

private:

    void create_widgets();
    void connect_signals();
    void set_style();

    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_b0_clicked();

    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_div_clicked();

    void on_calc_clicked();
    void on_clear_clicked();

    void append_number( const std::string& n );

    nwx::comctl::edit* m_edit;

    nwx::comctl::button* m_b1;
    nwx::comctl::button* m_b2;
    nwx::comctl::button* m_b3;
    nwx::comctl::button* m_b4;
    nwx::comctl::button* m_b5;
    nwx::comctl::button* m_b6;
    nwx::comctl::button* m_b7;
    nwx::comctl::button* m_b8;
    nwx::comctl::button* m_b9;
    nwx::comctl::button* m_b0;

    nwx::comctl::button* m_add;
    nwx::comctl::button* m_sub;
    nwx::comctl::button* m_mul;
    nwx::comctl::button* m_div;

    nwx::comctl::button* m_comma;

    nwx::comctl::button* m_calc;
    nwx::comctl::button* m_clear;

    std::string m_string;
};
