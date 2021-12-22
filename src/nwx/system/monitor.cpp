/*

    ...

*/


#include "monitor.hpp"
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace system
{


monitor::monitor() :
m_work_left( 0 ),
m_work_right( 0 ),
m_work_top( 0 ),
m_work_bottom( 0 )
{
    POINT ptZero = { 0 };
    HMONITOR hmonPrimary = MonitorFromPoint(ptZero, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO monitorinfo = { 0 };
    monitorinfo.cbSize = sizeof(monitorinfo);
    GetMonitorInfo(hmonPrimary, &monitorinfo);
    const RECT& rcWork = monitorinfo.rcWork;

    m_work_left = rcWork.left;
    m_work_right = rcWork.right;
    m_work_top = rcWork.top;
    m_work_bottom = rcWork.bottom;
}

int monitor::work_left()
{
    return m_work_left;
}

int monitor::work_right()
{
    return m_work_right;
}

int monitor::work_top()
{
    return m_work_top;
}

int monitor::work_bottom()
{
    return m_work_bottom;
}


}
}
