/**

Definition for class basic_string.

*/


#include "basic_string.hpp"
#include <assert.h>


namespace nwx
{
namespace core
{


/**
    Constructor.
*/
basic_string::basic_string( const std::string& utf8_str ) : m_bstr( NULL )
{
#if defined(_WIN32)
    int size_needed = ::MultiByteToWideChar( CP_UTF8, 0, &utf8_str[0], int( utf8_str.size() ), NULL, 0 );
    if( size_needed > 0 )
    {
        m_bstr = ::SysAllocStringLen( NULL, size_needed );
        assert( m_bstr != NULL);
        ::MultiByteToWideChar( CP_UTF8, 0, &utf8_str[0], int( utf8_str.size() ), m_bstr, size_needed );
    }
#else // !defined(_WIN32)
#error basic_string not implemented on this platform
#endif // defined(_WIN32)
}

/**
    Destructor.
*/
basic_string::~basic_string()
{
    ::SysFreeString( m_bstr );
}

/**
    Data access.
*/
basic_string::operator BSTR () const
{
    return m_bstr;
}

/**
    Data access.
*/
BSTR* basic_string::operator & ()
{
    return &m_bstr;
}


}
}
