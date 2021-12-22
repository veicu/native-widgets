/**

    Wrapper for Windows specific handels / pointers

*/


#ifndef NWX_CORE_RESOURCE_HANDLE
#define NWX_CORE_RESOURCE_HANDLE


#include "use_windows.hpp"


namespace nwx
{
    namespace core
    {
        template <typename HandleT>
        class resource
        {
        public:
            typedef HandleT handle_type;

            /**
                Standard constructor.
            */
            resource() : m_handle( 0 )
            {
                // nothing to do ...
            }

            /**
                Extended constructor.
            */
            explicit resource( const handle_type other_handle ): m_handle( other_handle )
            {
                // nothing to do ...
            }

            /*
                Copy constuctor.
            */
            resource( const resource& other ) : m_handle( other.m_handle )
            {
                // nothing to do ...
            }

            /**
                Assignment operator.
            */
            resource& operator=( const resource& other )
            {
                if( this != &other )
                {
                    m_handle = other.m_handle;
                }
                return *this;
            }

            /**
                Set.
            */
            void handle( const handle_type other_handle )
            {
                m_handle = other_handle;
            }

            /**
                Get.
            */
            handle_type handle()
            {
                return m_handle;
            }

            /**
                Get.
            */
            handle_type handle() const
            {
                return m_handle;
            }

        private:
            handle_type m_handle;
        };


        //
        // Some typedefs
        //

        typedef resource<HINSTANCE> instance_resource; // handle to a instance
        typedef resource<HWND>      window_resource;   // handle to a window
        typedef resource<HFONT>     font_resource;     // handle to a font
    }
}


#endif // NWX_CORE_RESOURCE_HANDLE
