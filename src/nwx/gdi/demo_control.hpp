#ifndef NWX_GDI_DEMO_CONTROL
#define NWX_GDI_DEMO_CONTROL


#include "control.hpp"
#include <nwx/core/signal.hpp>
#include <string>


namespace nwx
{
    namespace gdi
    {
        class demo_control : public control
        {
        public:
            demo_control( nwx::gui::window* parent );
            demo_control( nwx::gui::window* parent, int x, int y, int width, int height );
            demo_control( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            nwx::core::void_signal clicked;

        protected:
            virtual void on_paint();
            virtual void on_mouse_down();
            virtual void on_mouse_up();
            virtual void on_mouse_enter();
            virtual void on_mouse_leave();

        private:
            void initialize();

            std::string m_text;
            bool m_click;
        };
    }
}


#endif // NWX_GDI_DEMO_CONTROL
