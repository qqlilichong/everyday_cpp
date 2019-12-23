
#ifndef E_FOLD_EXPRESSION
#define E_FOLD_EXPRESSION

#include <string>

namespace e_fold_expression {

    template <typename T, typename R>
    auto myadd(T val, R& result)
    {
        result += val ;
    }

    template <typename R>
    auto myadd(const char* val, R& result)
    {
        result += std::stoll(val) ;
    }

    template <typename... ARGS>
    auto myadd(ARGS&&... args)
    {
        decltype(std::stoll("")) result = 0 ;
        (myadd(args, result), ...) ;
        return result ;
    }

    template <typename... ARGS>
    auto mysum(ARGS&&... args)
    {
        return (args + ...) ;
    }

    inline auto ut()
    {
        // expect : 116
        return myadd("1", 2) + myadd(0) + myadd("3") + mysum(100) + mysum(1, 2, 3, 4) ;
    }
}

#endif
