//==================================================================================================
//
//==================================================================================================

#include "console.hpp"
#include <nwx/core/conversion.hpp>
#include <windows.h>
#include <conio.h>
#include <iostream>

namespace nwx
{
namespace console
{

class console::console_impl
{
public:
    console_impl()
#if defined(_WIN32)
    :
    m_h_input( INVALID_HANDLE_VALUE ),
    m_h_output( INVALID_HANDLE_VALUE ),
    m_original_colors( 0 )
#endif
    {
#if defined(_WIN32)

        m_h_input  = ::GetStdHandle( STD_INPUT_HANDLE );
        m_h_output = ::GetStdHandle( STD_OUTPUT_HANDLE );

        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        ::GetConsoleScreenBufferInfo( m_h_output, &screen_buffer_info );
        m_original_colors = screen_buffer_info.wAttributes;

#endif
    }

    void pos( int x, int y )
    {
#if defined(_WIN32)

        COORD screen_coord = { nwx::core::to_int16( x ), nwx::core::to_int16( y ) };
        ::SetConsoleCursorPosition( m_h_output, screen_coord );

#endif
    }

    int width()
    {
#if defined(_WIN32)

        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        ::GetConsoleScreenBufferInfo( m_h_output, &screen_buffer_info );
        return nwx::core::to_int( screen_buffer_info.dwSize.X );

#endif
    }

    int height()
    {
#if defined(_WIN32)

        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        ::GetConsoleScreenBufferInfo( m_h_output, &screen_buffer_info );
        return nwx::core::to_int( screen_buffer_info.dwSize.Y );

#endif
    }

    void clear()
    {
#if defined(_WIN32)

        COORD screen_coord = { 0, 0 };
        DWORD chars_written = 0;
        DWORD console_size = 0;

        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        ::GetConsoleScreenBufferInfo( m_h_output, &screen_buffer_info );
        console_size = screen_buffer_info.dwSize.X * screen_buffer_info.dwSize.Y;

        ::FillConsoleOutputCharacter( m_h_output, TEXT( ' ' ), console_size, screen_coord, &chars_written );
        ::SetConsoleCursorPosition( m_h_output, screen_coord );

#endif
    }

    void color( color foreground )
    {
#if defined(_WIN32)

        const WORD bg_mask = 0x00F0;

        const WORD fg = fg_color( foreground );
        const WORD bg = bg_mask & m_original_colors;

        ::SetConsoleTextAttribute( m_h_output, fg | bg );

#endif
    }

    void color( nwx::console::color foreground, nwx::console::color background )
    {
#if defined(_WIN32)

        const WORD fg = fg_color( foreground );
        const WORD bg = bg_color( background );

        ::SetConsoleTextAttribute( m_h_output, fg | bg );

#endif
    }

    void color( int x, int y, int length, nwx::console::color foreground, nwx::console::color background )
    {
#if defined(_WIN32)

        const WORD fg = fg_color( foreground );
        const WORD bg = bg_color( background );
        COORD screen_coord = { nwx::core::to_int16( x ), nwx::core::to_int16( y ) };
        DWORD attributes_written = 0;

        ::FillConsoleOutputAttribute( m_h_output, fg | bg, length, screen_coord, &attributes_written );

#endif
    }

    void reset_color()
    {
#if defined(_WIN32)

        ::SetConsoleTextAttribute( m_h_output, m_original_colors );

#endif
    }

    int read()
    {
        return _getch();
    }

private:

#if defined(_WIN32)

    WORD fg_color( nwx::console::color foreground )
    {
        WORD fg = 0;

        switch( foreground )
        {
            case color::black:
                break;
            case color::dark_blue:
                fg = FOREGROUND_BLUE;
                break;
            case color::dark_green:
                fg = FOREGROUND_GREEN;
                break;
            case color::dark_cyan:
                fg = FOREGROUND_BLUE | FOREGROUND_GREEN;
                break;
            case color::dark_red:
                fg = FOREGROUND_RED;
                break;
            case color::dark_magenta:
                fg = FOREGROUND_BLUE | FOREGROUND_RED;
                break;
            case color::dark_yellow:
                fg = FOREGROUND_GREEN | FOREGROUND_RED;
                break;
            case color::gray:
                fg = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
                break;
            case color::dark_gray:
                fg = FOREGROUND_INTENSITY;
                break;
            case color::blue:
                fg = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
                break;
            case color::green:
                fg = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
                break;
            case color::cyan:
                fg = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
                break;
            case color::red:
                fg = FOREGROUND_RED | FOREGROUND_INTENSITY;
                break;
            case color::magenta:
                fg = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
                break;
            case color::yellow:
                fg = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
                break;
            case color::white:
                fg = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
                break;
            default:
                break;
        }

        return fg;
    }

    WORD bg_color( nwx::console::color background )
    {
        WORD bg = 0;

        switch( background )
        {
            case color::black:
                break;
            case color::dark_blue:
                bg = BACKGROUND_BLUE;
                break;
            case color::dark_green:
                bg = BACKGROUND_GREEN;
                break;
            case color::dark_cyan:
                bg = BACKGROUND_BLUE | BACKGROUND_GREEN;
                break;
            case color::dark_red:
                bg = BACKGROUND_RED;
                break;
            case color::dark_magenta:
                bg = BACKGROUND_BLUE | BACKGROUND_RED;
                break;
            case color::dark_yellow:
                bg = BACKGROUND_GREEN | BACKGROUND_RED;
                break;
            case color::gray:
                bg = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
                break;
            case color::dark_gray:
                bg = BACKGROUND_INTENSITY;
                break;
            case color::blue:
                bg = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
                break;
            case color::green:
                bg = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
                break;
            case color::cyan:
                bg = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
                break;
            case color::red:
                bg = BACKGROUND_RED | BACKGROUND_INTENSITY;
                break;
            case color::magenta:
                bg = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
                break;
            case color::yellow:
                bg = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
                break;
            case color::white:
                bg = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
                break;
            default:
                break;
        }

        return bg;
    }

    HANDLE m_h_input;
    HANDLE m_h_output;
    WORD   m_original_colors;

#endif
};

/**
    Constructor.
*/
coloring::coloring(std::shared_ptr<nwx::console::console> p_console, color p_foreground, color p_background) : console(p_console), foreground(p_foreground), background(p_background)
{
}

/**

*/
marking coloring::operator()(const std::string& s)
{
    return marking(console, foreground, background, s);
}

/**
    Constructor.
*/
marking::marking(std::shared_ptr<nwx::console::console> p_console, color p_foreground, color p_background, const std::string& p_text)
    : coloring( p_console, p_foreground, p_background )
    , text(p_text)
{
}

/**
    Constructor.
*/
console::console() : d( std::make_unique<console_impl>() )
{
}

/**
    Destructor.
*/
console::~console()
{
}

/**
    Set cursor position.
*/
void console::pos( int x, int y )
{
    d->pos( x, y );
}

/**
    Width of console.
*/
int console::width()
{
    return d->width();
}

/**
    Height of console.
*/
int console::height()
{
    return d->height();
}

/**
    Clear the screen.
*/
void console::clear()
{
    d->clear();
}

/**
    Set console colors.
*/
void console::set_color( color foreground )
{
    d->color( foreground );
}

/**
    Set console colors.
*/
void console::set_color( color foreground, color background )
{
    d->color( foreground, background );
}

/**
    Set console colors.
*/
void console::set_color( int x, int y, int length, color foreground, color background )
{
    d->color( x, y, length, foreground, background );
}

/**
    Reset console colors to original values.
*/
void console::reset_color()
{
    d->reset_color();
}

/**
    Read single key from console without echoing it.
*/
int console::read()
{
    return d->read();
}

/**

*/
coloring console::colorize( color p_foreground, color p_background )
{
    return coloring(shared_from_this(), p_foreground, p_background);
}

/**

*/
std::ostream& operator<<( std::ostream& os, const coloring& c )
{
    c.console->set_color(c.foreground, c.background);
    return os;
}

/**

*/
std::ostream& operator<<( std::ostream& os, const marking& m )
{
    m.console->set_color(m.foreground, m.background);
    os << m.text;
    m.console->reset_color();
    return os;
}

}
}
