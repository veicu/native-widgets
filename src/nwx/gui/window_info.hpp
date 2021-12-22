/**

    Holds the registration information for new MS-Windows windows.

*/


#ifndef NWX_GUI_WINDOW_INFO
#define NWX_GUI_WINDOW_INFO


#include "color.hpp"
#include <string>


namespace nwx
{
    namespace gui
    {
        class window_info
        {
        public:
            window_info();

            std::string class_name;
            std::string window_name;

            int register_class_style;

            int create_window_reg_style;
            int create_window_ext_style;

            color background;
        };
    }
}

#endif // NWX_GUI_WINDOW_INFO
