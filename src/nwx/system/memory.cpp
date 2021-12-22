/*

    ...

*/


#include "memory.hpp"
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace system
{

double memory()
{
    double max_value = 0;
    double value = 0;

    MEMORYSTATUSEX stat;
    stat.dwLength = sizeof(MEMORYSTATUSEX);
    ::GlobalMemoryStatusEx(&stat);
    //max_value = (double)(__int64)(stat.ullTotalPageFile + stat.ullTotalPhys);
    max_value = (double)(__int64)(stat.ullTotalPhys) / 1024;

    value = max_value;
    //value = (double)(__int64)(stat.ullTotalPageFile + stat.ullTotalPhys - stat.ullAvailPageFile - stat.ullAvailPhys);

    return value;
}


}
}
