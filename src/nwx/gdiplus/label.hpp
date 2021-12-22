/**

    ...

*/


#ifndef NWX_GDIPLUS_LABEL
#define NWX_GDIPLUS_LABEL


#include "widget.hpp"
#include <string>


namespace nwx
{
    namespace gdiplus
    {
        class label : public widget
        {
        public:
            label( widget* parent );
            label( widget* parent, int x, int y, int width, int height );
            label( widget* parent, const std::string& txt, int x, int y, int width, int height );

            void text( const std::string& txt );
            std::string text() const;

            virtual void draw( HDC device );

        private:
            void initialize();

            std::string m_text;
        };
    }
}


#endif // NWX_GDIPLUS_LABEL
