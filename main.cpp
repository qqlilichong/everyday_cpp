
////////////////////////////////////////////////////////////////////////////////////////

#include <tuple>
#include <vector>
#include <variant>
#include <iostream>
using namespace std ;

#define FL __FILE__ << "(" << __LINE__ << ")"

/*

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0001 {

    auto test()
    {
        cout << "<deduction guide> : " << FL << endl ;

        vector vec = { 1, 2, 3, 4, 5 } ;
        for ( auto&& i : vec )
        {
            cout << "number : " << i << endl ;
        }

        cout << endl ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0002 {

    struct A
    {
        const int a = 666 ;

        void operator () ( decltype( a ) p )
        {
            cout << "struct A operator : " << p << endl ;
        }
    } ;

    struct B
    {
        const double b = 1.23 ;

        void operator () ( decltype( b ) p )
        {
            cout << "struct B operator : " << p << endl ;
        }
    } ;

    template<class... Ts>
    struct C : Ts...
    {
        using Ts::operator()... ;

        const char* c = "hehe" ;

        void operator () ( decltype( c ) p )
        {
            cout << "struct C operator : " << p << endl ;
        }
    } ;

    auto test()
    {
        cout << "<variadic template> : " << FL << endl ;

        C< A, B > obj ;
        cout << obj.a << endl ;
        cout << obj.b << endl ;
        cout << obj.c << endl ;

        obj( "operator const char" ) ;
        obj( 3.1415 ) ;
        obj( 7788 ) ;

        cout << endl ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0003 {

    template<class... Ts> struct visitor : Ts... { using Ts::operator()... ; } ;
    template<class... Ts> visitor( Ts... ) -> visitor< Ts... > ;

    auto test()
    {
        cout << "<deduction guide> : " << FL << endl ;

        variant< int, const char*, string_view > var ;
        visitor vs {
                []( int n ) { cout << "int : " << n << endl ; },
                []( const char* p ) { cout << "const char* : " << p << endl ; },
                []( auto&& v ) { cout << "other : " << v << endl ; },
        } ;

        var = 1314 ;
        visit( vs, var ) ;

        var = "raw_string" ;
        visit( vs, var ) ;

        var = "string_view"s ;
        visit( vs, var ) ;

        cout << endl ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0004 {

    template<class... Ts>
    auto add( Ts&&... args )
    {
        return ( args + ... ) ;
    }

    template<class T>
    auto printone( T&& t )
    {
        cout << is_lvalue_reference_v< T&& >
             << is_rvalue_reference_v< T&& >
             << endl ;
    }

    template<class... Ts>
    auto print( Ts&&... args )
    {
        ( printone( std::forward< Ts&& >( args ) ), ... ) ;
    }

    auto test()
    {
        cout << "<fold expression> : " << FL << endl ;

        cout << add( 1, 2, 3, 4, 5 ) << endl ;

        auto sw = "xixi"s ;
        print( 1.23f, 666, sw ) ;

        cout << endl ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////

int theboostcpplibraries_test() ;

*/

template<int I, int... Is>
struct Interface;

template<int I>
struct Interface<I>
{
    static int accumulate()
    {
        return I;
    }
};

template<int I, int... Is>
struct Interface
{
    static int accumulate()
    {
        return I + Interface<Is...>::accumulate();
    }
};

int main()
{
//    for ( auto&& test : {
//            theboostcpplibraries_test,
//    } ) test() ;

    cout << Interface<1, 2, 3, 4, 6, 7>::accumulate() << endl ;

    for ( auto&& val : { 1, 2, 3 } )
    {
        cout << val << endl ;
    }

    return 0 ;
}

////////////////////////////////////////////////////////////////////////////////////////
