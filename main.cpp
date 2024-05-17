
/*

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0006 {

    template<size_t IL, size_t IR>
    using is_sameint = is_same< integral_constant< size_t, IL >, integral_constant< size_t, IR > > ;

    auto case1()
    {
        constexpr size_t a = 666 ;
        constexpr size_t b = 999 ;
        constexpr size_t c = 3 * 3 ;
        constexpr size_t d = 7 + 2 ;

        // ( a == b ) || ( c == d )
        cout << disjunction_v<
                is_sameint< a, b >,
                is_sameint< c, d >
        > << endl ;

        // ( a == b ) && ( c == d )
        cout << conjunction_v<
                is_sameint< a, b >,
                is_sameint< c, d >
        > << endl ;
    }

    auto test()
    {
        cout << "<type_traits> : " << FL << endl ;

        case1() ;

        cout << endl ;
    }

}

*/

////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "e_variadic_templates.hpp"
#include "e_fold_expression.hpp"
#include "e_constexpr.hpp"
#include "e_structured_bindings.hpp"
#include "e_string_view.hpp"
#include "e_deduction_guide.hpp"
using namespace std;

int unit_test()
{
    int result = 0;
    extern void boost_asio_spawn_test();
    extern int lua_ut_test();
    extern int zlib_ut_test();

    result = lua_ut_test();
    cout << "[lua_ut] : " << result << endl;

    result = zlib_ut_test();
    cout << "[zlib_ut] : " << result << endl;

    cout << e_variadic_templates::ut() << endl;
    cout << e_fold_expression::ut() << endl;
    cout << e_constexpr::ut() << endl;
    cout << e_structured_bindings::ut() << endl;
    cout << e_string_view::ut() << endl;
    cout << e_deduction_guide::ut() << endl;

    boost_asio_spawn_test();
    return result;
}

int main()
{
    unit_test();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
