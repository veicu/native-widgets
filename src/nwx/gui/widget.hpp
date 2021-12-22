/**

    ...

*/


#ifndef NWX_GUI_WIDGET
#define NWX_GUI_WIDGET


#include "window.hpp"


namespace nwx
{
    namespace gdi
    {
        class painter;
    }

    namespace gui
    {

        class widget : public window
        {
        public:

            friend gdi::painter;

            widget( window* parent );
            widget( window* parent, int x, int y, int width, int height );

            virtual ~widget();

            //
            // Children
            //

            void add_child( widget* child );
        };
    }
}

#endif // NWX_GUI_WIDGET
