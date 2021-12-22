/**

    ...

*/


#ifndef NWX_GDIPLUS_WIDGET
#define NWX_GDIPLUS_WIDGET


#include <vector>
#include <nwx/core/use_windows.hpp>


namespace nwx
{
    namespace gdiplus
    {
        class painter;

        class widget
        {
        public:
            widget( widget* parent );
            widget( widget* parent, int x, int y, int width, int height );

            virtual ~widget();

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

            virtual void position( int x, int y );
            virtual void dimension( int width, int height );
            virtual void geometry( int x, int y, int width, int height );

            virtual void draw( HDC device );

        protected:
            widget* parent();

        private:
            widget* m_parent;

            std::vector<widget*> m_children;

            //
            // Position and Size
            //

            int m_x;
            int m_y;
            int m_width;
            int m_height;
        };
    }
}


#endif // NWX_GDIPLUS_WIDGET
