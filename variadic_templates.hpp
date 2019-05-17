
#ifndef VARIADIC_TEMPLATES
#define VARIADIC_TEMPLATES

template <auto LT, auto... RT>
struct tc_sum
{
    static const auto value = LT + tc_sum<RT...>::value ;
};

template <auto LT>
struct tc_sum<LT>
{
    static const auto value = LT ;
};

namespace variadic_templates {
    inline int unit_test()
    {
        int result = 0 ;
        result += tc_sum< 99 >::value ;
        result += tc_sum< 5, 6 >::value ;
        result += tc_sum< 1, 2, 3 >::value ;
        return result ;
    }
}

#endif
