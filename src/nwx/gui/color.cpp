/**

    Definition of class color.

*/


#include "color.hpp"


namespace nwx
{
namespace gui
{


/**
    Standard constructor.
*/
color::color() : m_red( 0 ), m_green( 0 ), m_blue( 0 ), m_alpha( 255 )
{
    // ...
}

/**
    Extended constructor.
*/
color::color( unsigned char red, unsigned char green, unsigned char blue ) : m_red( red ), m_green( green ), m_blue( blue ), m_alpha( 255 )
{
    // ...
}

/**
    Extended constructor.
*/
color::color( unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue ) : m_red( red ), m_green( green ), m_blue( blue ), m_alpha( alpha )
{
    // ...
}

/**
    Destructor.
*/
color::~color() = default;


/**
    Copy constructor.
*/
color::color( const color& other ) : m_red( other.m_red ), m_green( other.m_green ), m_blue( other.m_blue ), m_alpha( other.m_alpha )
{
    // ...
}


/**
    Assignment operator.
*/
color& color::operator=( const color& other )
{
    if( this != &other )
    {
        m_red   = other.m_red;
        m_green = other.m_green;
        m_blue  = other.m_blue;
        m_alpha = other.m_alpha;
    }

    return *this;
}

/**
    Get red color component.
*/
unsigned char color::red() const
{
    return m_red;
}

/**
    Get green color component.
*/
unsigned char color::green() const
{
    return m_green;
}

/**
    Get blue color component.
*/
unsigned char color::blue() const
{
    return m_blue;
}

/**
    Get alpha color component.
*/
unsigned char color::alpha() const
{
    return m_alpha;
}

/**
    Set red color component.
*/
void color::red( unsigned char red )
{
    m_red = red;
}

/**
    Set green color component.
*/
void color::green( unsigned char green )
{
    m_green = green;
}

/**
    Set blue color component.
*/
void color::blue( unsigned char blue )
{
    m_blue = blue;
}

/**
    Set alpha color component.
*/
void color::alpha( unsigned char alpha )
{
    m_alpha = alpha;
}

/**
    Set color by red, green and blue values.
*/
void color::rgb( unsigned char red, unsigned char green, unsigned char blue )
{
    m_red   = red;
    m_green = green;
    m_blue  = blue;
}

/**
    Set color by red, green, blue and alpha values.
*/
void color::rgba( unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha )
{
    m_red   = red;
    m_green = green;
    m_blue  = blue;
    m_alpha = alpha;
}


}
}
