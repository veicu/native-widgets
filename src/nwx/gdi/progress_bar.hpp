#ifndef NWX_GDI_PROGRESS_BAR
#define NWX_GDI_PROGRESS_BAR


#include "control.hpp"
#include <nwx/gui/color.hpp>

#include <string>


namespace nwx
{
    namespace gdi
    {
        class progress_bar : public control
        {
        public:
            progress_bar( nwx::gui::window* parent );
            progress_bar( nwx::gui::window* parent, int x, int y, int width, int height );
            progress_bar( nwx::gui::window* parent, const std::string& txt, int x, int y, int width, int height );

            void minimum( double min );
            double minimum() const;

            void maximum( double max );
            double maximum() const;

            void value( double value );
            double value() const;

        protected:
            virtual void on_paint();

        private:
            void initialize();

            double m_min;
            double m_max;
            double m_value;
            int m_pixel_width;
        };
    }
}


#endif // NWX_GDI_PROGRESS_BAR
