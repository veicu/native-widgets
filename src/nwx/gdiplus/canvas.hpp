/**

    ...

*/


#ifndef NWX_GDIPLUS_CANVAS
#define NWX_GDIPLUS_CANVAS


#include <nwx/core/use_windows.hpp>
#include <nwx/gui/color.hpp>
#include <string>


namespace nwx
{
    namespace gdiplus
    {
        class canvas_private;

        class canvas
        {
        public:
            canvas( int width, int height );
            ~canvas();

            HDC device();
            void create_dc();
            void delete_dc();

            void resize( int width, int height );

            //
            // drawing functions
            //

            void clear();

            void fill_rectangle( int x, int y, int width, int height, const nwx::gui::color& color );

            void draw_text( int x, int y, const nwx::gui::color& color, const std::string& text );

        private:
            canvas_private* d;
        };
    }
}


#endif // NWX_GDIPLUS_CANVAS
