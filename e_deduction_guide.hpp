
#ifndef E_DEDUCTION_GUIDE
#define E_DEDUCTION_GUIDE

#include <vector>
#include <variant>
#include <string_view>

namespace e_deduction_guide {

    template <class... Ts>
    struct varvis : Ts... { using Ts::operator()...; };

    template <class... Ts>
    varvis(Ts...) -> varvis<Ts...>;

    inline auto ut()
    {
        varvis varvismap {
            [](auto var) {
                return 100;
            },
            [](const std::string& var) {
                return 10;
            },
            [](std::string_view var) {
                return 6;
            },
        };

        int result = 0;
        using uservar = std::variant<int, std::string, std::string_view>;
        std::vector arrs{uservar{0}, uservar{"0"s}, uservar{"0"sv}};
        for (auto&& var : arrs)
        {
            result += std::visit(varvismap, var);
        }

        // expect : 116
        return result;
    }
}

#endif
