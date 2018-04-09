
#include <iostream>
using namespace std ;

#include <boost/thread.hpp>

int main()
{
    boost::thread th( []{
        cout << "Hello,World" << endl ;
    } ) ;

    th.join() ;
    return 0 ;
}
