
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std ;

////////////////////////////////////////////////////////////////////////////////////////

#define BOOST_COROUTINES_NO_DEPRECATION_WARNING
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>

////////////////////////////////////////////////////////////////////////////////////////

namespace boost_asio_spawn {

    auto server_session( auto&& ios, auto&& sock )
    {
        auto co = [ &ios, sock = std::move( sock ) ] ( auto yield ) mutable
        {
            cout << "server_session begin : " << &sock << endl ;

            try
            {
                while ( true )
                {
                    boost::system::error_code ec ;

                    char data[ 128 ] = { 0 } ;
                    const auto size = sock.async_read_some( boost::asio::buffer( data ), yield[ ec ] ) ;
                    if ( ec )
                    {
                        break ;
                    }

                    cout << "get data : " << data << endl ;
                    boost::asio::async_write( sock, boost::asio::buffer( data, size ), yield[ ec ] ) ;
                    if ( ec )
                    {
                        break ;
                    }
                }
            }

            catch ( ... )
            {

            }

            cout << "server_session end : " << &sock << endl ;
        } ;

        boost::asio::spawn( ios, std::move( co ) ) ;
    }

    auto server_acceptor( auto&& ios )
    {
        auto co = [ &ios ] ( auto yield )
        {
            using namespace boost::asio::ip ;

            try
            {
                tcp::acceptor acceptor( ios, tcp::endpoint( tcp::v4(), 7070 ) ) ;
                while ( true )
                {
                    boost::system::error_code ec ;
                    tcp::socket socket( ios ) ;
                    acceptor.async_accept( socket, yield[ ec ] ) ;
                    if ( !ec )
                    {
                        server_session( ios, std::move( socket ) ) ;
                    }
                }
            }

            catch ( ... )
            {

            }
        } ;

        boost::asio::spawn( ios, std::move( co ) ) ;
    }

    auto test()
    {
        boost::asio::io_context ios ;
        server_acceptor( ios ) ;
        ios.run() ;
    }
}

void boost_test()
{
    //boost_asio_spawn::test() ;
}
