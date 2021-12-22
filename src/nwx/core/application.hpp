/**

    The application.

*/


#ifndef NWX_CORE_APPLICATION
#define NWX_CORE_APPLICATION


#include "resource.hpp"


namespace nwx
{
    namespace core
    {
        class application
        {
        public:
            application();
            virtual ~application();

            static application* instance();
            static instance_resource resource();

            int exec();

        private:
            void init();
            int message_loop();

            static application* s_self;

            instance_resource m_instance_resource;
        };
    }
}


#endif // NWX_CORE_APPLICATION
