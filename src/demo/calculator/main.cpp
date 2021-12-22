#include <nwx/core/application.hpp>
#include "main_window.hpp"


int main( int argc, char *argv[] )
{
    nwx::core::application app;

    main_window mw;

    mw.show();
    mw.update();

    return app.exec();
}
