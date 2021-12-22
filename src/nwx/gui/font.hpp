/**

    Font.

*/


#ifndef NWX_GUI_FONT
#define NWX_GUI_FONT


#include <nwx/core/resource.hpp>
#include <string>
#include <memory>


namespace nwx
{
    namespace gui
    {
        class font
        {
        public:

            struct quality
            {
                enum type
                {
                    invalid,
                    normal,
                    cleartype,
                    antialiased,
                    last
                };
            };

            //typedef std::tr1::shared_ptr<font> pointer;

            //static font::pointer create( const std::string& family, int height, bool bold = false, bool italic = false, bool underline = false, bool strike_out = false, quality::type quality = quality::normal );
            //static font::pointer bold_font( const std::string& family, int height, quality::type quality = quality::normal );
            //static font::pointer bold_italic_font( const std::string& family, int height, quality::type quality = quality::normal );

            //static font::pointer create( const std::string& family, int height, bool bold = false, bool italic = false, bool underline = false, bool strike_out = false, quality::type quality = quality::normal );
            static font* bold_font( const std::string& family, int height, quality::type quality = quality::normal );
            static font* bold_italic_font( const std::string& family, int height, quality::type quality = quality::normal );

            font(const std::string& family, int height, bool bold, bool italic, bool underline, bool strike_out, quality::type quality);
            ~font();

            nwx::core::font_resource::handle_type resource() const;

        private:

            nwx::core::font_resource m_font_resource;
        };
    }
}


#endif // NWX_GUI_FONT
