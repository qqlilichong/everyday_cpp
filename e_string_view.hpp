
#ifndef E_STRING_VIEW
#define E_STRING_VIEW

#include <string_view>
using namespace std::literals;

namespace e_string_view {

    inline auto ut()
    {
        const auto su8 = u8"string_view"s;
        constexpr auto svu8 = u8"utf8 string_view"sv;
        if (su8 == svu8.substr(5))
        {
            constexpr auto svu16 = u"utf16 string_view"sv;
            constexpr auto svu32 = U"utf32 string_view"sv;
            svu16.substr(5);
            svu32.substr(5);
            return 116;
        }

        return 0;
    }
}

#endif
