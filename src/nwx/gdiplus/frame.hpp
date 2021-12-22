/**

    ...

*/


#ifndef NWX_GDIPLUS_FRAME
#define NWX_GDIPLUS_FRAME


#include "widget.hpp"
#include <nwx/gui/color.hpp>
#include <string>


namespace nwx
{
    namespace gdiplus
    {
        class frame : public widget
        {
        public:
            frame( widget* parent );
            frame( widget* parent, int x, int y, int width, int height );
            frame( widget* parent, const std::string& txt, int x, int y, int width, int height );

            void border_color( nwx::gui::color c );
            void background_color( nwx::gui::color c );

            virtual void draw( HDC device );

        private:
            nwx::gui::color m_border_color;
            nwx::gui::color m_background_color;
            bool m_draw_border;
        };
    }
}


#endif // NWX_GDIPLUS_FRAME
