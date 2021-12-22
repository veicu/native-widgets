#ifndef NWX_GDI_FRAME
#define NWX_GDI_FRAME


#include "control.hpp"
#include <nwx/gui/color.hpp>


namespace nwx
{
    namespace gdi
    {
        class frame : public control
        {
        public:
            frame( nwx::gui::window* parent );
            frame( nwx::gui::window* parent, int x, int y, int width, int height );

            void border_color( nwx::gui::color c );
            void background_color( nwx::gui::color c );

        protected:
            virtual void on_paint();

        private:
            void initialize();

            nwx::gui::color m_border_color;
            nwx::gui::color m_background_color;
            bool m_draw_border;
        };
    }
}


#endif // NWX_GDI_FRAME
