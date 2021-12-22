/**

    ...

*/


#include "widget.hpp"


namespace nwx
{
namespace gdiplus
{


/**
    Constructor.
*/
widget::widget( widget* parent ) : m_parent( parent )
{
    // nothing else to do ...
}

/**
    Constructor.
*/
widget::widget( widget* parent, int x, int y, int width, int height ) : m_parent( parent ), m_x( x ), m_y( y ), m_width( width ), m_height( height )
{
    // nothing else to do ...
}

/**
    Destructor.
*/
widget::~widget()
{

}

/**
    Get x position.
*/
int widget::x() const
{
    return m_x;
}

/**
    Get y position.
*/
int widget::y() const
{
    return m_y;
}

/**
    Get width.
*/
int widget::width() const
{
    return m_width;
}

/**
    Get height.
*/
int widget::height() const
{
    return m_height;
}

/**
    Set x position.
*/
void widget::x( int x )
{
    m_x = x;
}

/**
    Set x position.
*/
void widget::y( int y )
{
    m_y = y;
}

/**
    Set width.
*/
void widget::width( int width )
{
    m_width = width;
}

/**
    Set height.
*/
void widget::height( int height )
{
    m_height = height;
}

/**

*/
void widget::position( int x, int y )
{
    m_x = x;
    m_y = y;
}

/**

*/
void widget::dimension( int width, int height )
{
    m_width = width;
    m_height = height;
}

/**

*/
void widget::geometry( int x, int y, int width, int height )
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
}

/**

*/
void widget::draw( HDC device )
{

}

/**
    Get parent widget.
*/
widget* widget::parent()
{
    return m_parent;
}


}
}
