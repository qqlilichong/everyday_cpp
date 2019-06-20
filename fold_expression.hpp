
#ifndef FOLD_EXPRESSION
#define FOLD_EXPRESSION

template <auto LT, auto... RT>
struct fe_sum
{
    static constexpr auto value = LT + (RT + ...) ;
};

template <auto LT>
struct fe_sum<LT>
{
    static constexpr auto value = LT ;
};

namespace fold_expression {
    inline int unit_test()
    {
        int result = 0 ;
        result += fe_sum< 4 >::value ;
        result += fe_sum< 5, 6, 7 >::value ;
        return result ;
    }
}

#endif
