
////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <variant>
#include <iostream>
using namespace std ;

#define FL "************ " << __FILE__ << "(" << __LINE__ << ")" << " ************"

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

        std::variant< int, const char*, string_view > var ;
        visitor vs {
                []( int n ) { cout << "int : " << n << endl ; },
                []( const char* p ) { cout << "const char* : " << p << endl ; },
                []( auto&& v ) { cout << "other : " << v << endl ; },
        } ;

        var = 1314 ;
        std::visit( vs, var ) ;

        var = "raw_string" ;
        std::visit( vs, var ) ;

        var = "string_view"s ;
        std::visit( vs, var ) ;

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
        cout << t
             << "," << std::is_lvalue_reference_v< decltype( t ) >
             << "," << std::is_rvalue_reference_v< decltype( t ) >
             << endl ;
    }

    template<class... Ts>
    auto print( Ts&&... args )
    {
        ( printone( std::forward<Ts>( args ) ), ... ) ;
    }

    auto test()
    {
        cout << "<fold expression> : " << FL << endl ;

        cout << add( 1, 2, 3, 4, 5 ) << endl ;

        auto sw = "xixi"s ;
        print( 1.23f, 666, sw, "haha"s ) ;

        cout << endl ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    for ( auto&& test : {
            unit0001::test,
            unit0002::test,
            unit0003::test,
            unit0004::test,
    } ) test() ;

    return 0 ;
}

////////////////////////////////////////////////////////////////////////////////////////
