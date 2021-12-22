/**

    Definition for class wstring.

*/


#include "wstring.hpp"
#include "use_windows.hpp"


namespace nwx
{
namespace core
{


/**
    Constructor.
*/
wstring::wstring( const std::string& utf8_str ) : m_wchar_data()
{
    const int len_w = ::MultiByteToWideChar( CP_UTF8, 0, utf8_str.data(), int( utf8_str.size() ), NULL, 0 );
    m_wchar_data.resize( size_t( len_w + 1 ), wchar_t( 0 ) ); // + 1 for zero termination
                      ::MultiByteToWideChar( CP_UTF8, 0, utf8_str.data(), int( utf8_str.size() ), &m_wchar_data[0], len_w );
}

/**
    Constructor.
*/
wstring::wstring( const wchar_t* wchar_str ) : m_wchar_data( wchar_str )
{
    m_wchar_data += wchar_t( 0 );
}

/**
    Constructor.
*/
wstring::wstring( size_t num_chars ) : m_wchar_data( num_chars + 1, wchar_t( 0 ) )
{

}

/**
    Destructor.
*/
wstring::~wstring() = default;


/**
    LPWSTR - Long Pointer to (NULL terminated) Wide String.
*/
wchar_t* wstring::lpwstr()
{
    return &m_wchar_data[0];

    // in C++17
    //return m_wchar_data.data();
}

/**
    LPCWSTR - Long Pointer to (NULL terminated) Constant Wide String.
*/
const wchar_t* wstring::lpcwstr()
{
    return m_wchar_data.data();
}

/**

*/
std::string wstring::utf8()
{
    const int len_s = ::WideCharToMultiByte( CP_UTF8, 0, m_wchar_data.data(), int( m_wchar_data.size() - 1 ), NULL, 0, NULL, NULL );
    std::string str( len_s, 0 );
                      ::WideCharToMultiByte( CP_UTF8, 0, m_wchar_data.data(), int( m_wchar_data.size() - 1 ), &str[0], len_s, NULL, NULL );
    return str;
}

/**

*/
size_t wstring::size() const
{
    return m_wchar_data.size();
}


/**
    Convert a wide Unicode character string to an UTF8 std::string.
*/
std::string wstring::utf8_encode( const wchar_t* wstr )
{
    int size_needed = ::WideCharToMultiByte( CP_UTF8, 0, wstr, int( wcslen( wstr ) ), NULL, 0, NULL, NULL );
    std::string str( size_needed, 0 );
    if( size_needed > 0 )
    {
        ::WideCharToMultiByte( CP_UTF8, 0, wstr, int( wcslen( wstr ) ), &str[0], size_needed, NULL, NULL );
    }
    return str;
}

/**
    Convert a wide Unicode std::wstring to an UTF8 std::string.
*/
std::string wstring::utf8_encode( const std::wstring& wstr )
{
    int size_needed = ::WideCharToMultiByte( CP_UTF8, 0, &wstr[0], int( wstr.size() ), NULL, 0, NULL, NULL );
    std::string str( size_needed, 0 );
    if( size_needed > 0 )
    {
        ::WideCharToMultiByte( CP_UTF8, 0, &wstr[0], int( wstr.size() ), &str[0], size_needed, NULL, NULL );
    }
    return str;
}


}
}
