#ifndef NWX_GDI_CONTROL
#define NWX_GDI_CONTROL


#include <nwx/gui/widget.hpp>


namespace nwx
{
    namespace gdi
    {
        /**
            Use this class as base to indicate that it is a custom GDI control.
        */
        class control : public nwx::gui::widget
        {
        public:

            control( nwx::gui::window* parent );
            control( nwx::gui::window* parent, int x, int y, int width, int height );

            //
            //
            //

            void update();
        };
    }
}

#endif // NWX_GDI_CONTROL
