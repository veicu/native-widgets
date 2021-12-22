/*

    ...

*/


#ifndef NWX_SYSTEM_MONITOR
#define NWX_SYSTEM_MONITOR


namespace nwx
{
    namespace system
    {
        class monitor
        {
        public:
            monitor();

            int work_left();
            int work_right();
            int work_top();
            int work_bottom();

        private:
            int m_work_left;
            int m_work_right;
            int m_work_top;
            int m_work_bottom;
        };
    }
}


#endif //NWX_SYSTEM_MONITOR
