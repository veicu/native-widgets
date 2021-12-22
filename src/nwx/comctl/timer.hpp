#ifndef TIMER
#define TIMER


#include <nwx/core/signal.hpp>


namespace nwx
{
    class timer_private;

    class timer
    {
    public:
        timer( int timeout );
        ~timer();

        nwx::core::void_signal timeout;

    private:
        timer_private* d;

        int m_timeout_time;
    };
}


#endif
