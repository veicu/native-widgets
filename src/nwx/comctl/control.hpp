/**

    Declaration of class control.

    Use this class as base to indicate that it is a build in (aka. common) control.

*/


#ifndef NWX_COMCTL_CONTROL
#define NWX_COMCTL_CONTROL


#include <nwx/gui/widget.hpp>
#include <nwx/gui/font.hpp>


namespace nwx
{
    namespace comctl
    {
        class control : public nwx::gui::widget
        {
        public:
            control( nwx::gui::window* parent );
            control( nwx::gui::window* parent, int x, int y, int width, int height );

            //
            // Style
            //

            //void font( nwx::gui::font::pointer f );
            void font( nwx::gui::font* f );

        private:
            nwx::gui::font* m_font;
        };
    }
}

#endif // NWX_COMCTL_CONTROL
