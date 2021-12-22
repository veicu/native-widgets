/**

    Declartion of class main_window.

*/


#ifndef NWX_GDIPLUS_MAIN_WINDOW
#define NWX_GDIPLUS_MAIN_WINDOW


#include "widget.hpp"
#include "canvas.hpp"
#include <nwx/gui/window.hpp>
#include <string>


namespace nwx
{
    namespace gdiplus
    {
        class main_window_private;

        class main_window : public nwx::gui::window
        {
        public:

            enum class window_type
            {
                invalid,
                normal,
                normal_top_level,
                normal_top_level_no_focus,
                tool_window,
                tool_window_top_level,
                tool_window_top_level_no_focus,
                last
            };

            main_window( const std::string& txt, int x, int y, int width, int height, window_type wt = window_type::normal );

            virtual ~main_window();

            virtual void geometry( int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            void update();

            void draw( HDC device );
            HDC device();

            void cv_clear();
            canvas* cv()
            {
                return &m_canvas;
            }

        private:
            void initialize( window_type wt );

            std::string m_text;

            main_window_private* d;

            canvas m_canvas;

            std::vector<widget*> m_children;
        };
    }
}


#endif // NWX_GDIPLUS_MAIN_WINDOW
