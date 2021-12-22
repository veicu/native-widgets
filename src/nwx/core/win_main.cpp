/**

    ...

*/


#include "use_windows.hpp"
#include <vector>


extern int main( int, char** );


/**
    The MS Windows specific main function.
*/
int APIENTRY WinMain( HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR lpCmdLine, int /*nCmdShow*/ )
{
    int argc = 0;
    std::vector<char*> argv;

    char exe_path[MAX_PATH];
    ::GetModuleFileNameA( NULL, exe_path, ARRAYSIZE( exe_path ) );
    argv.push_back( exe_path );
    argc++;

    char* arg = lpCmdLine;

    while( *arg != 0 )
    {
        argv.push_back( arg );
        argc++;

        while( *arg != 0 && *arg != ' ' )
        {
            arg++;
        }

        while( *arg != 0 && *arg == ' ' )
        {
            *arg = 0;
            arg++;
        }
    }

    int result = main( argc, argv.data() );
    return result;
}
