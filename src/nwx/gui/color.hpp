/**

    Declartion of class color.

*/


#ifndef NWX_GUI_COLOR
#define NWX_GUI_COLOR


namespace nwx
{
    namespace gui
    {
        class color
        {
        public:

            color();
            color( unsigned char red, unsigned char green, unsigned char blue );
            color( unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue );

            ~color();

            color( const color& other );
            color& operator=( const color& other );

            unsigned char red() const;
            unsigned char green() const;
            unsigned char blue() const;
            unsigned char alpha() const;

            void red( unsigned char red );
            void green( unsigned char green );
            void blue( unsigned char blue );
            void alpha( unsigned char alpha );

            void rgb( unsigned char red, unsigned char green, unsigned char blue );
            void rgba( unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha );

        private:

            unsigned char m_red;
            unsigned char m_green;
            unsigned char m_blue;
            unsigned char m_alpha;
        };
    }
}


#endif // NWX_GUI_COLOR
