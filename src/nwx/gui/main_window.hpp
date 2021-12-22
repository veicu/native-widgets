/**

    Declartion of class main_window.

*/


#ifndef NWX_GUI_MAIN_WINDOW
#define NWX_GUI_MAIN_WINDOW


#include "window.hpp"
#include "color.hpp"
#include <string>


namespace nwx
{
    namespace gui
    {
        class main_window : public window
        {
        public:

            enum class window_type
            {
                invalid,
                normal,
                fixed,
                fixed_minimizable,
                popup,
                popup_top_level,
                last
            };

            main_window();
            main_window( int x, int y, int width, int height );
            main_window( const std::string& title, int x, int y, int width, int height, window_type wt = window_type::fixed );
            main_window( const std::string& title, int x, int y, int width, int height, window_type wt, color c );

            void title( const std::string& txt );
            std::string title() const;

        private:

            void initialize( window_type wt, color c );

            std::string m_title;
        };


        // #####     #####     #####     #####     #####     #####     #####     #####     #####     #####

/*
        class fx_main_window : public main_window
        {
        public:
            fx_main_window( const std::string& txt, int x, int y, int width, int height );

        protected:
            virtual LRESULT v_wnd_proc( UINT message, WPARAM wParam, LPARAM lParam );
        private:
            void paint_non_client_area( WPARAM wParam );

            bool m_active;
        };
*/
    }
}


#endif // NWX_GUI_MAIN_WINDOW
