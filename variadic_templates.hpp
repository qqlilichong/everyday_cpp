
#ifndef VARIADIC_TEMPLATES
#define VARIADIC_TEMPLATES

template <auto LT, auto... RT>
struct vt_sum
{
    static const auto value = LT + vt_sum<RT...>::value ;
};

template <auto LT>
struct vt_sum<LT>
{
    static const auto value = LT ;
};

namespace variadic_templates {
    inline int unit_test()
    {
        int result = 0 ;
        result += vt_sum< 99 >::value ;
        result += vt_sum< 5, 6 >::value ;
        result += vt_sum< 1, 2, 3 >::value ;
        return result ;
    }
}

#endif
