#ifndef NWX_GDI_LABEL
#define NWX_GDI_LABEL


#include "control.hpp"
#include <nwx/gui/font.hpp>
#include <nwx/gui/color.hpp>


namespace nwx
{
    namespace gdi
    {
        class label : public control
        {
        public:
            label( nwx::gui::window* parent );
            label( nwx::gui::window* parent, int x, int y, int width, int height );
            label( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            void font(nwx::gui::font* f );
            void foreground_color(nwx::gui::color c );
            void background_color(nwx::gui::color c );

        protected:
            virtual void on_paint();

        private:
            void initialize();

            std::string m_text;
            nwx::gui::color m_foreground_color;
            nwx::gui::color m_background_color;
            nwx::gui::font* m_font;
        };
    }
}


#endif // NWX_GDI_LABEL
