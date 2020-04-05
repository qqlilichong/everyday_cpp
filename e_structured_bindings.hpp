
#ifndef E_STRUCTURED_BINDINGS
#define E_STRUCTURED_BINDINGS

#include <map>
#include <tuple>

namespace e_structured_bindings {

    struct myst
    {
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
    };

    inline auto ut()
    {
        auto&& [a, b, c, d] = std::make_tuple(1, 2, 3, 4);

        int result = 0;
        std::map<int, int> mp = {
                {a, b},
                {c, d}
        };
        for (auto&& [k, v] : mp)
        {
            result += k;
            result += v;
        }

        myst obj = {2, 3, 101};
        auto&& [p1, p2, p3] = obj;
        if (p1 == obj.p1)
        {
            result += obj.p1;
        }

        if (p2 == obj.p2)
        {
            result += obj.p2;
        }

        if (p3 == obj.p3)
        {
            result += obj.p3;
        }

        // expect : 116
        return result;
    }
}

#endif
