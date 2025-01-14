/**

    ...

*/

#ifndef NWX_CONSOLE_CONSOLE
#define NWX_CONSOLE_CONSOLE

#include <memory>
#include <string>

namespace nwx
{
    namespace console
    {
        enum class color
        {
            black,
            dark_blue,
            dark_green,
            dark_cyan,
            dark_red,
            dark_magenta,
            dark_yellow,
            gray,
            dark_gray,
            blue,
            green,
            cyan,
            red,
            magenta,
            yellow,
            white
        };

        class console;
        class coloring;
        class marking;

        class coloring
        {
        public:
            coloring(std::shared_ptr<nwx::console::console> p_console, color p_foreground = color::white, color p_background = color::black);
            ~coloring() = default;

            coloring( coloring&& )                 = default;
            coloring( const coloring& )            = default;
            coloring& operator=( coloring&& )      = default;
            coloring& operator=( const coloring& ) = default;

            marking operator()(const std::string& s);

            friend std::ostream & operator<<(std::ostream& os, const coloring& c);

        protected:
             std::shared_ptr<nwx::console::console> console;
             color foreground;
             color background;
        };

        class marking : public coloring
        {
        public:
            marking(std::shared_ptr<nwx::console::console> p_console, color p_foreground, color p_background, const std::string& p_text);
            ~marking() = default;

            marking( marking&& )                 = default;
            marking( const marking& )            = default;
            marking& operator=( marking&& )      = default;
            marking& operator=( const marking& ) = default;

            friend std::ostream & operator<<(std::ostream& os, const marking& m);

        private:
            const std::string& text;
        };

        class console : public std::enable_shared_from_this<console>
        {
        public:
            console();
            ~console();

            console( console&& )                 = delete;
            console( const console& )            = delete;
            console& operator=( console&& )      = delete;
            console& operator=( const console& ) = delete;

            void pos( int x, int y );

            int width();
            int height();

            void clear();

            void set_color( color foreground );
            void set_color( color foreground, color background );
            void set_color( int x, int y, int length, color foreground, color background );
            void reset_color();

            int read();

            coloring colorize(color p_foreground = color::white, color p_background = color::black);

        private:
            class console_impl;
            std::unique_ptr<console_impl> d;
        };

        std::ostream& operator<<(std::ostream& os, const coloring& c);
        std::ostream& operator<<(std::ostream& os, const marking& m);

    }
}

#endif
