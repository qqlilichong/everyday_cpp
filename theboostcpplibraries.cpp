
////////////////////////////////////////////////////////////////////////////////////////

// std
#include <iostream>
#include <memory>
#include <list>

// boost
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

#define FL __FILE__ << "(" << __LINE__ << ")"

////////////////////////////////////////////////////////////////////////////////////////

namespace boostcpplib {

    // I. RAII and Memory Management
    inline namespace chapter01 {

        auto Unit_SmartPointers()
        {
            // scoped_ptr
            {
                // 特点 : 只能在作用域内使用, 不可复制, 不可转移
                boost::scoped_ptr<int> pData( new int(1) ) ;

                // 错误用法 : 不能复制
                // auto pDataCopy = pData ;
                // return pData

                // 释放
                pData.reset() ;

                // 重新绑定 : 前面的数据被释放, 绑定新的数据
                pData.reset(new int(2)) ;

                // 访问数据 : .get(), *, ->
                const int *pRawData = pData.get() ;
                std::cout << FL << "[scoped_ptr][*pRawData] : " << *pRawData << std::endl ;
                std::cout << FL << "[scoped_ptr][pData] : " << *pData << std::endl ;

                // 标准库中类似组件
                std::unique_ptr<int> pData1( new int(1) ) ;
                std::unique_ptr<int> pData2( std::make_unique<int>(2) ) ;
                auto pData3{ std::make_unique<int>(3) } ;

                // 用法相似
                pData1.get() ;
                pData1.reset() ;

                // 不同点是可以使用转移
                pData2 = std::move(pData3) ;
                std::cout << FL << "[unique_ptr][move] : " << *pData2 << std::endl ;
                pData2 = std::make_unique<int>(100) ;
                std::cout << FL << "[unique_ptr][move] : " << *pData2 << std::endl ;

                // 数组管理使用 scoped_array
                boost::scoped_array<int> pDataArray( new int[100] ) ;
                pDataArray.get() ;
            }

            // shared_ptr
            {
                // 特点 : 计数型管理, 可复制, 可转移
                boost::shared_ptr<int> pData( new int(1) ) ;
                boost::shared_ptr<int> pDataSame = pData ;

                // 引用相同的数据
                std::cout << FL << "[shared_ptr][get] : " << pData.get() << std::endl ;
                std::cout << FL << "[shared_ptr][get] : " << pDataSame.get() << std::endl ;
                std::cout << FL << "[shared_ptr][*] : " << *pData << std::endl ;
                std::cout << FL << "[shared_ptr][*] : " << *pDataSame << std::endl ;

                // 必须全部释放后, 指向的资源才会自动释放
                pDataSame.reset() ;
                std::cout << FL << "[shared_ptr][*] : " << *pData << std::endl ;
                pData.reset() ;

                // 高级特性 : 可自定义销毁函数
                // 对所有 分配-释放 体系的函数都可以采用这种方法进行自动的资源管理
                // malloc-free, CreateEvent-CloseHandle, socket-closesocket
                boost::shared_ptr<int> pUserData( new int(100), [](const int *ptr) {
                    std::cout << FL << "[shared_ptr][deleter] : " << *ptr << std::endl ;
                    delete ptr ;
                } ) ;

                std::cout << FL << "[shared_ptr][reset]" << std::endl ;
                pUserData.reset() ;

                // 标准库中类似组件
                auto pStdData{ std::make_shared<int>(1) } ;

                // 数组管理使用 shared_array
                boost::shared_array<int> pDataArray( new int[10] ) ;
            }

            // weak_ptr
            {
                // 弱引用智能指针
                // 行为类似于shared_ptr, 但是不会影响计数器
                // 常用的使用场景一般是解决类与类之间的循环引用问题
                // 标准库 std::weak_ptr
            }

            // intrusive_ptr
            {
                // 侵入型智能指针
                // 行为类似于shared_ptr, 但是需要自己维护计数器
                // 标准库未采用
            }
        }

        auto Unit_PointerContainer()
        {
            // 智能指针容器用法类似于标准容器
            // 不同之于在之使用上更方法, 还在算法上有所扩展

            // 标准容器用法
            boost::shared_ptr<int> pData01( new int(1) ) ;
            boost::shared_ptr<int> pData02( new int(2) ) ;
            boost::shared_ptr<int> pData03( new int(3) ) ;
            std::list<boost::shared_ptr<int>> oStdList ;
            oStdList.push_back( pData01 ) ;
            oStdList.push_back( pData02 ) ;
            oStdList.push_back( pData03 ) ;
            std::cout << FL << "[std::list<boost::shared_ptr<int>>][back()] : " << oStdList.back() << std::endl ;
            std::for_each(oStdList.begin(), oStdList.end(), [](const boost::shared_ptr<int>& val) {
                std::cout << FL << "[std::list<boost::shared_ptr<int>>] : " << *val << std::endl ;
            } ) ;

            // 指针容器用法
            boost::ptr_list<int> oPtrList ;
            oPtrList.push_back( new int(1) ) ;
            oPtrList.push_back( new int(2) ) ;
            oPtrList.push_back( new int(3) ) ;
            std::cout << FL << "[boost::ptr_list<int>][back()] : " << oPtrList.back() << std::endl ;
            std::for_each(oPtrList.begin(), oPtrList.end(), [](const int &val) {
                std::cout << FL << "[boost::ptr_list<int>] : " << val << std::endl ;
            } ) ;
        }

        auto Unit_ScopeExit()
        {
            // 使用宏进行 RAII 模式的资源管理
            // 使用高级特性可以完全替代
            // 这个特性只是为向下兼容保留
        }

        auto Unit_Pool()
        {

        }

        auto test()
        {
            for ( auto&& unit : {
                    Unit_SmartPointers,
                    Unit_PointerContainer,
                    Unit_ScopeExit,
                    Unit_Pool,
            } ) unit() ;
        }
    }

    // II. String Handling
    namespace chapter02 {
    }

    // III. Containers
    namespace chapter03 {
    }
}

////////////////////////////////////////////////////////////////////////////////////////

int theboostcpplibraries_test()
{
    boostcpplib::test() ;
    return 0 ;
}

////////////////////////////////////////////////////////////////////////////////////////
