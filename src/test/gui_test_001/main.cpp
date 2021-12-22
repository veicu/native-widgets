#include <nwx/core/application.hpp>
#include <nwx/gui/window.hpp>
#include <nwx/gui/window_private.hpp>


class my_main_window : public nwx::gui::window
{
public:
    my_main_window() : nwx::gui::window( 0, 25, 25, 250, 350 )
    {
        nwx::gui::window_info wi;
        wi.class_name = "MyMainWindow";
        wi.window_name = "BLA";
        wi.register_class_style = CS_DBLCLKS;

        wi.create_window_reg_style = WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN;
        wi.create_window_ext_style = WS_EX_CONTROLPARENT;

        DWORD sys_color = ::GetSysColor( COLOR_3DFACE );
        wi.background.red( GetRValue( sys_color ) );
        wi.background.green( GetGValue( sys_color ) );
        wi.background.blue( GetBValue( sys_color ) );

        d->register_class( wi );
        d->create_window( wi );
        use_default_font();
    }
};


int main( int argc, char* argv[] )
{
    nwx::core::application app;

    my_main_window mw;
    mw.show();

    return app.exec();
}
