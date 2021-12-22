/**

    ...

*/


#include "widget.hpp"


namespace nwx
{
namespace gui
{


/**
    Constructor.
*/
widget::widget( window* parent ) : window( parent )
{
    // nothing else to do ...
}

/**
    Constructor.
*/
widget::widget( window* parent, int x, int y, int width, int height ) : window( parent, x, y, width, height )
{
    // nothing else to do ...
}

/**
    Destructor.
*/
widget::~widget()
{
    // ???
}

/**
    Add child widget.
*/
void widget::add_child( widget* child )
{
    //m_children.push_back( child );
}


}
}
