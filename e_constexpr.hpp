
#ifndef E_CONSTEXPR
#define E_CONSTEXPR

namespace e_constexpr {

    template <typename LT, typename... RT>
    auto mysum(LT&& lv, RT&&... rv)
    {
        if constexpr (sizeof...(rv) == 0)
        {
            return lv;
        }
        else
        {
            return lv + mysum(std::forward<RT>(rv)...);
        }
    }

    template <typename T>
    constexpr auto myadd(T&& i)
    {
        return [=](auto&& j) {
            return i + j;
        };
    }

    inline auto ut()
    {
        // expect : 116
        return mysum(1, 2, 3, 4) + myadd(6)(100);
    }
}

#endif
