/**

    ...

*/


#ifndef NWX_COMCTL_LABEL
#define NWX_COMCTL_LABEL


#include "control.hpp"
#include <string>


namespace nwx
{
    namespace comctl
    {
        class label : public control
        {
        public:
            label( nwx::gui::window* parent );
            label( nwx::gui::window* parent, int x, int y, int width, int height );
            label( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

        private:
            void initialize();

            std::string m_text;
        };
    }
}


#endif // NWX_COMCTL_LABEL
