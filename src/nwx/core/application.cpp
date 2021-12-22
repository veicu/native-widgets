/**

    The application.

*/


#include "application.hpp"


namespace nwx
{
namespace core
{


/**
    Constructor.
*/
application::application() : m_instance_resource()
{
    init();
}

/**
    Destructor.
*/
application::~application()
{
    // ...
}

/**
    The single instance.
*/
application* application::instance()
{
    return s_self;
}

/**
    Get application handle
*/
instance_resource application::resource()
{
    return s_self->m_instance_resource;
}

/**
    Execute the message loop.
*/
int application::exec()
{
    return message_loop();
}

/**

*/
void application::init()
{
    s_self = this;

    ::CoInitialize( NULL );

    m_instance_resource.handle( ::GetModuleHandle( NULL ) );

    //INITCOMMONCONTROLSEX icce;
    //icce.dwSize = sizeof( INITCOMMONCONTROLSEX );
    //icce.dwICC = 0 | ICC_WIN95_CLASSES | ICC_BAR_CLASSES | ICC_COOL_CLASSES;
    //::InitCommonControlsEx( &icce );
}

/**
    Message loop;
*/
int application::message_loop()
{
    MSG msg;
    while( ::GetMessage( &msg, NULL, 0, 0 ) )
    {
        ::TranslateMessage( &msg );
        ::DispatchMessage( &msg );
    }
    return static_cast<int>( msg.wParam );
}


//
// The static stuff.
//

application* application::s_self = 0;


}
}
