
#ifndef E_STRUCTURED_BINDINGS
#define E_STRUCTURED_BINDINGS

#include <map>
#include <tuple>

namespace e_structured_bindings {

    inline auto ut()
    {
        auto&& [a, b, c, d] = std::make_tuple(1, 2, 110, 3) ;

        int result = 0 ;
        std::map<int, int> mp = { {a, b}, {c, d} } ;
        for(auto&& [k, v] : mp)
        {
            result += k ;
            result += v ;
        }

        // expect : 116
        return result ;
    }
}

#endif
