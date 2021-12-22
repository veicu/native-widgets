/**

    Wrapper for COM BSTR ( basic string or binary string ).

*/


#ifndef NWX_CORE_BASIC_STRING
#define NWX_CORE_BASIC_STRING


#include <string>
#include "use_windows.hpp"


namespace nwx
{
    namespace core
    {
        class basic_string
        {
        public:
            basic_string( const std::string& utf8_str );
            ~basic_string();

            operator BSTR () const;
            BSTR* operator & ();

        private:
            BSTR m_bstr;
        };
    }
}


#endif // NWX_CORE_BASIC_STRING
