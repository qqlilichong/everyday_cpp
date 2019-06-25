
#ifndef S_V
#define S_V

#include <string>
#include <string_view>
using namespace std::literals ;

namespace s_v {

    inline auto unit_test()
    {
        constexpr auto sv_utf8 = u8"utf8 string_view"sv ;
        constexpr auto sv_utf16 = u"utf16 string_view"sv ;
        constexpr auto sv_utf32 = U"utf32 string_view"sv ;
        sv_utf16.substr(3, 5) ;
        sv_utf32.substr(4, 6) ;
        return std::string{ sv_utf8.substr(3, 3) } ;
    }
}

#endif
