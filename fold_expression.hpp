
#ifndef FOLD_EXPRESSION
#define FOLD_EXPRESSION

#include <string>
#include <sstream>

namespace fold_expression {

    template <typename... ARGS>
    auto mysum(ARGS&&... args)
    {
        return (... + args) ;
    }

    template <typename T>
    auto myfunc(T&& p)
    {
        std::stringstream ss ;
        ss << p ;
        return ss ;
    }

    template <typename... ARGS>
    auto mycall(ARGS&&... args)
    {
        return (myfunc(args), ...) ;
    }

    inline auto unit_test()
    {
        mycall(int(1), double(2.3)) ;

        const std::string s1 = "AAA" ;
        const std::string s2 = "BBB" ;
        return mysum(s2) + mysum(s1, s2) ;
    }
}

#endif
