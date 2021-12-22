/**

    The signal types.

*/


#ifndef NWX_CORE_SIGNAL
#define NWX_CORE_SIGNAL


#include <boost/signals2/signal.hpp>


namespace nwx
{
    namespace core
    {
        using boost::signals2::signal;

        using void_signal = signal<void ()>;
        using int_signal  = signal<void (int)>;

        using signal_connection = boost::signals2::connection;
    }
}


#endif // NWX_CORE_SIGNAL
