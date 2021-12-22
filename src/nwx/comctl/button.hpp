/**

    ...

*/


#ifndef NWX_COMCTL_BUTTON
#define NWX_COMCTL_BUTTON


#include "control.hpp"
#include <nwx/core/signal.hpp>
#include <string>


namespace nwx
{
    namespace comctl
    {
        class button : public control
        {
        public:
            button( nwx::gui::window* parent );
            button( nwx::gui::window* parent, int x, int y, int width, int height );
            button( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            nwx::core::void_signal clicked;

        protected:
            virtual void on_command( int id, int code );

        private:
            void initialize();

            std::string m_text;
        };
    }
}


#endif // NWX_COMCTL_BUTTON
