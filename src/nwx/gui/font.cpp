/**

    Font.

*/


#include "font.hpp"
#include <nwx/core/wstring.hpp>


namespace nwx
{
namespace gui
{


/**

*/
//font::pointer font::create( const std::string& family, int height, bool bold /*= false*/, bool italic /*= false*/, bool underline /*= false*/, bool strike_out /*= false*/, quality::type quality /*= quality::normal*/ )
//{
//    return pointer( new font( family, height, bold, italic, underline, strike_out, quality ) );
//}

/**

*/
font* font::bold_font( const std::string& family, int height, quality::type quality /*= quality::normal*/ )
{
    return new font( family, height, true, false, false, false, quality );
}

/**

*/
font* font::bold_italic_font( const std::string& family, int height, quality::type quality /*= quality::normal*/ )
{
    return new font( family, height, true, true, false, false, quality );
}

/**
    Constructor.
*/
font::font( const std::string& family, int height, bool bold, bool italic, bool underline, bool strike_out, quality::type quality ) : m_font_resource()
{
    nwx::core::wstring w_family( family );

    DWORD output_quality = DEFAULT_QUALITY;

    switch( quality )
    {
    case quality::cleartype:
        output_quality = CLEARTYPE_QUALITY;
        break;
    case quality::antialiased:
        output_quality = ANTIALIASED_QUALITY;
        break;
    default:
        break;
    }

    m_font_resource.handle
    (
        ::CreateFont
        (
            height,
            0,
            0,
            0,
            bold ? FW_BOLD : FW_NORMAL,
            italic ? TRUE : FALSE,
            underline ? TRUE : FALSE,
            strike_out ? TRUE : FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            output_quality,
            VARIABLE_PITCH,
            w_family.lpcwstr()
        )
    );
}

/**
    Destructor.
*/
font::~font()
{
    if( m_font_resource.handle() )
    {
        ::DeleteObject( m_font_resource.handle() );
        m_font_resource.handle( NULL );
    }
}

/**

*/
nwx::core::font_resource::handle_type font::resource() const
{
    return m_font_resource.handle();
}


}
}
