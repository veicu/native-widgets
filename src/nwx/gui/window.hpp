/**

    Declartion of class window.

*/


#ifndef NWX_GUI_WINDOW
#define NWX_GUI_WINDOW


#include <memory>
//#include "window_info.hpp"


namespace nwx
{
    namespace gui
    {
        class window
        {
        public:

            window( window* parent );
            window( window* parent, int x, int y, int width, int height );

            virtual ~window();

            //
            // Position and Size
            //

            int x() const;
            int y() const;
            int width() const;
            int height() const;

            void x( int x );
            void y( int y );
            void width( int width );
            void height( int height );

            virtual void pos( int x, int y );
            virtual void size( int width, int height );
            virtual void geometry( int x, int y, int width, int height );

            //
            //
            //

            void show();
            void hide();

            //
            //
            //

            void update();

            //
            //
            //

            enum class z_order_type
            {
                invalid,
                bottom,
                normal,
                top,
                topmost,
                last
            };

            void z_order( z_order_type z );

            //
            // State
            //

            void enable( bool state );
            bool enabled();

            //
            // Events
            //

            virtual void on_create();
            virtual void on_paint();
            virtual void on_command( int id, int code );
            virtual void on_mouse_down();
            virtual void on_mouse_up();
            virtual void on_double_click();
            virtual void on_mouse_enter();
            virtual void on_mouse_leave();

            //
            // Font
            //

            void use_default_font();

            //
            //
            //

            bool m_erase_background;

        private:

            window* m_parent;

            //
            // Position and Size
            //

            int m_x;
            int m_y;
            int m_width;
            int m_height;

            //
            //
            //

        protected:

            class window_private;
            std::unique_ptr<window_private> d;
        };
    }
}


#endif // NWX_GUI_WINDOW
