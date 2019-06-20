
#ifndef VARIADIC_TEMPLATES
#define VARIADIC_TEMPLATES

namespace variadic_templates {

    template <auto LT, auto... RT>
    struct mysum
    {
        static const auto value = LT + mysum<RT...>::value ;
    };

    template <auto LT>
    struct mysum<LT>
    {
        static const auto value = LT ;
    };

    inline auto unit_test()
    {
        return mysum< 99 >::value + mysum< 5, 6 >::value + mysum< 1, 2, 3 >::value ;
    }
}

#endif
