/**

    ...

*/


#ifndef NWX_COMCTL_COMBO_BOX
#define NWX_COMCTL_COMBO_BOX


#include "control.hpp"
#include <nwx/core/signal.hpp>
#include <string>


namespace nwx
{
    namespace comctl
    {
        class combo_box : public control
        {
        public:
            combo_box( nwx::gui::window* parent );
            combo_box( nwx::gui::window* parent, int x, int y, int width, int height );

            int add_item( const std::string& txt );
            int insert_item( int index, const std::string& text );
            void remove_item( int index );
            void remove_all_items();
            int item_count();
            std::string item_text( int index );
            int current_item();
            void current_item( int index );
            void current_item( const std::string& txt );

            nwx::core::int_signal selection_changed;

        protected:
            virtual void on_command( int id, int code );

        private:
            void initialize();
        };
    }
}


#endif // NWX_COMCTL_COMBO_BOX
