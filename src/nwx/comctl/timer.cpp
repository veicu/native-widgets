/**

    ...

*/


#include "timer.hpp"
#include <nwx/core/use_windows.hpp>


namespace nwx
{


VOID CALLBACK TimerProc
(
    HWND hwnd,
    UINT uMsg,
    UINT_PTR idEvent,
    DWORD dwTime
)
{
    int brk = 1;
}

class timer_private
{
public:
    timer_private() : id( 0 )
    {
        // ...
    }

    UINT id;
};

timer::timer( int timeout ) : d( 0 ), m_timeout_time( timeout )
{
    d = new timer_private();

    d->id = ::SetTimer
    (
        NULL,
        NULL,
        m_timeout_time,
        TimerProc
    );
}

timer::~timer()
{
    ::KillTimer
    (
        NULL,
        d->id
    );

    d->id = 0;

    delete d;
    d = 0;
}


}
