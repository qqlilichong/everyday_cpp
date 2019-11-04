
#ifndef VARIADIC_TEMPLATES
#define VARIADIC_TEMPLATES

namespace variadic_templates {

    template <auto LV, auto... RV>
    struct mysum
    {
        static constexpr auto value = LV + mysum<RV...>::value ;
    };

    template <auto LV>
    struct mysum<LV>
    {
        static constexpr auto value = LV ;
    };

    inline auto unit_test()
    {
        // expect : 116
        return mysum< 99 >::value + mysum< 5, 6 >::value + mysum< 1, 2, 3 >::value ;
    }
}

#endif
