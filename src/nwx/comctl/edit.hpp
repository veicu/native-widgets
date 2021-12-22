/**

    ...

*/


#ifndef NWX_COMCTL_EDIT
#define NWX_COMCTL_EDIT


#include "control.hpp"
#include <string>


namespace nwx
{
    namespace comctl
    {
        class edit : public control
        {
        public:
            edit( nwx::gui::window* parent );
            edit( nwx::gui::window* parent, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text();

        private:
            void initialize();
        };
    }
}


#endif // NWX_COMCTL_EDIT
