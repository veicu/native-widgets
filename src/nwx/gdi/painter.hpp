#ifndef NWX_GDI_PAINTER
#define NWX_GDI_PAINTER


#include <nwx/gui/color.hpp>
#include <nwx/gui/font.hpp>

#include <string>


namespace nwx
{
    namespace gui
    {
        class widget;
    }

    namespace gdi
    {
        class widget;
        class painter_private;

        class painter
        {
        public:

            painter( nwx::gui::widget* w, bool double_buffer = false );
            ~painter();

            void use_double_buffer();

            void draw_rect( int x, int y, int width, int height );
            void fill_rect( int x, int y, int width, int height );
            void draw_text( const std::string& text, int x, int y, int width, int height );
            void draw_text_plus( const std::string& text, int x, int y, int width, int height );

            void no_pen();
            void pen( const nwx::gui::color& c );

            void no_brush();
            void brush( const nwx::gui::color& c );

            void text_color( const nwx::gui::color& c );
            void font(nwx::gui::font* f );

        private:

            nwx::gui::widget* m_widget;
            painter_private* d;

            nwx::gui::color m_pen_color;
            nwx::gui::color m_brush_color;
            nwx::gui::color m_text_color;
        };
    }
}

#endif // NWX_GDI_PAINTER
