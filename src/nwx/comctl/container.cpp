/**

    ...

*/


#include "container.hpp"


namespace nwx
{
namespace comctl
{


/**
    Constructor.
*/
container::container( nwx::gui::window* parent ) : widget( parent )
{
    // nothing else to do ...
}

/**
    Constructor.
*/
container::container( nwx::gui::window* parent, int x, int y, int width, int height ) : widget( parent, x, y, width, height )
{
    // nothing else to do ...
}

/**
    Destructor.
*/
container::~container()
{
    // destroy children ???
}

/**
    Add child widget.
*/
void container::add_child( nwx::gui::window* child )
{
    m_children.push_back( child );
}


}
}
