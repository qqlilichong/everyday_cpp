
/*

namespace unit0005 {

    template<class T, size_t... I>
    void printall( T&& t, index_sequence< I... > )
    {
        ( ( cout << get< I >( t ) << endl ), ... ) ;
    }

    template<class T>
    void printall( T&& t )
    {
        printall( std::forward< T&& >( t ),
                  make_index_sequence< tuple_size_v< decay_t< T&& > > >() ) ;
    }

    auto test()
    {
        cout << "<tuple> : " << FL << endl ;

        auto xx = make_tuple( (int)100, (double)3.1415, (char)'Y' ) ;
        printall( xx ) ;

        cout << endl ;
    }
}

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

int unit_test()
{
    std::cout << e_variadic_templates::ut() << std::endl;
    std::cout << e_fold_expression::ut() << std::endl;
    std::cout << e_constexpr::ut() << std::endl;
    std::cout << e_structured_bindings::ut() << std::endl;
    std::cout << e_string_view::ut() << std::endl;
    std::cout << e_deduction_guide::ut() << std::endl;
    return 0;
}

int main()
{
    unit_test();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
