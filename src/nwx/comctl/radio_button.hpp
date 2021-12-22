/**

    ...

*/


#ifndef NWX_COMCTL_RADIO_BUTTON
#define NWX_COMCTL_RADIO_BUTTON


#include "control.hpp"
#include <nwx/core/signal.hpp>
#include <string>


namespace nwx
{
    namespace comctl
    {
        class radio_button : public control
        {
        public:
            radio_button( nwx::gui::window* parent );
            radio_button( nwx::gui::window* parent, int x, int y, int width, int height );
            radio_button( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            void selected( bool state );

            nwx::core::void_signal clicked;

        protected:
            virtual void on_command( int id, int code );

        private:
            void initialize();

            std::string m_text;
        };
    }
}


#endif // NWX_COMCTL_RADIO_BUTTON
