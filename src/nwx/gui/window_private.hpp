/**

    Declartion of class window_private.

*/


#ifndef NWX_GUI_WINDOW_PRIVATE
#define NWX_GUI_WINDOW_PRIVATE


#include <nwx/core/use_windows.hpp>
#include "window.hpp"
#include "window_info.hpp"


namespace nwx
{
    namespace gui
    {
        class window::window_private
        {
        public:

            window_private( window* parent );
            ~window_private();

            window_private()                                   = delete;
            window_private( window_private&& )                 = delete;
            window_private( const window_private& )            = delete;
            window_private& operator=( window_private&& )      = delete;
            window_private& operator=( const window_private& ) = delete;

            static window* from_resource( HWND win_res );

            //
            // Message handling
            //

            static LRESULT CALLBACK wnd_proc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );
            LRESULT v_wnd_proc( UINT message, WPARAM wParam, LPARAM lParam );

            //
            // The 
            //

            HWND parent_window_resource() const;
            HWND window_resource;

            //
            // Native window class register and creation
            //

            void register_class( const window_info& info );
            void create_window( const window_info& info );

            //
            //
            //

            void adjust_window_rect( window_info& info );

        private:

            window* m_window;
        };
    }
}


#endif NWX_GUI_WINDOW_PRIVATE
