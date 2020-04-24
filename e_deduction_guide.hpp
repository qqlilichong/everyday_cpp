
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

    template<class TUP, class CALL, size_t... I>
    void tupcall(TUP&& tup, CALL&& call, std::index_sequence<I...>)
    {
        (call( std::get<I>(tup)), ...);
    }

    template<class TUP, class CALL>
    void tupcall(TUP&& tup, CALL&& call)
    {
        tupcall(std::forward<TUP>(tup), std::forward<CALL>(call),
                std::make_index_sequence<std::tuple_size_v<std::decay_t<TUP>>>());
    }

    template<class... T>
    auto tupmake(T&&... t)
    {
        return std::make_tuple(std::forward<T>(t)...);
    }

    inline auto ut()
    {
        varvis varvismap {
            [](auto var) {
                return 10;
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

        varvis vartupmap {
            [&](auto) {
                result += 666;
            },
            [&](const int& var) {
                result += 10;
            },
            [&](const double& var) {
                result += 20;
            },
            [&](const char& var) {
                result += 60;
            },
        };
        tupcall(tupmake((int)123, (double)3.1415, (char)'Y'), vartupmap);

        // expect : 116
        return result;
    }
}

#endif
