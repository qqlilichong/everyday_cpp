
#include "zlib.h"
#include <string_view>
using namespace std;

int zlib_ut_test()
{
    string_view ver = zlibVersion();
    if (!ver.empty())
    {
        return 116;
    }

    return -1;
}
