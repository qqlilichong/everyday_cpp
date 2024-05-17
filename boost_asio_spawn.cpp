
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>

////////////////////////////////////////////////////////////////////////////////////////

namespace boost_asio_spawn {

    auto server_session(auto &&ioc, auto &&sock)
    {
        boost::asio::spawn(ioc, [&ioc, sock = std::forward<decltype(sock)>(sock)](const boost::asio::yield_context &yield) mutable
        {
            try
            {
                boost::system::error_code err;
                do
                {
                    char data[128] = {0};
                    const auto size = sock.async_read_some(boost::asio::buffer(data), yield[err]);
                    if (err)
                    {
                        break;
                    }

                    std::cout << "[BoostAsio-async_read_some] : " << data << std::endl;
                    boost::asio::async_write(sock, boost::asio::buffer(data, size), yield[err]);
                    if (err)
                    {
                        break;
                    }

                    if (std::string_view(data) == "exit")
                    {
                        ioc.stop();
                        break;
                    }

                } while (!err);
            }
            catch (...)
            {
                throw;
            }
        });
    }

    auto server_acceptor(auto &&ioc)
    {
        boost::asio::spawn(ioc, [&ioc](const boost::asio::yield_context &yield)
        {
            try
            {
                using namespace boost::asio::ip;
                tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 7070));
                boost::system::error_code err;
                do
                {
                    tcp::socket socket(ioc);
                    acceptor.async_accept(socket, yield[err]);
                    if (!err)
                    {
                        server_session(ioc, std::move(socket));
                    }
                } while (!err);
            }
            catch (...)
            {
                throw;
            }
        });
    }

    void test()
    {
        boost::asio::io_context ioc;
        server_acceptor(ioc);
        ioc.run();
    }
}

void boost_asio_spawn_test()
{
    boost_asio_spawn::test();
}
