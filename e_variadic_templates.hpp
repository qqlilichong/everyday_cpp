
#ifndef E_VARIADIC_TEMPLATES
#define E_VARIADIC_TEMPLATES

namespace e_variadic_templates {

    template <auto LV, auto... RV>
    struct mysum
    {
        constexpr static auto value = LV + mysum<RV...>::value ;
    };

    template <auto LV>
    struct mysum<LV>
    {
        constexpr static auto value = LV ;
    };

    inline auto ut()
    {
        // expect : 116
        return mysum<99>::value + mysum<5, 6>::value + mysum<1, 2, 3>::value ;
    }
}

#endif
