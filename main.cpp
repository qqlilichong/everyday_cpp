
#include <iostream>
#include <vector>
using namespace std ;

int main()
{
    vector v1 = { 1, 2, 3 } ;
    auto v2 = std::move( v1 ) ;
    cout << v1.size() << endl ;
    cout << v2.size() << endl ;
    return 0 ;
}
