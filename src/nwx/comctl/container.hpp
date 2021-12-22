/**

    ...

*/


#ifndef NWX_COMCTL_CONTAINER
#define NWX_COMCTL_CONTAINER


#include <nwx/gui/widget.hpp>
#include <vector>


namespace nwx
{
    namespace comctl
    {
        class container : public nwx::gui::widget
        {
        public:
            container( nwx::gui::window* parent );
            container( nwx::gui::window* parent, int x, int y, int width, int height );

            virtual ~container();

            //
            // Children
            //

            void add_child( nwx::gui::window* child );

        private:
            std::vector<nwx::gui::window*> m_children;
        };
    }
}


#endif // NWX_COMCTL_CONTAINER
