#pragma once
#include <cxsher.hpp>
namespace Cxsher{
    namespace Debug{
        class Log{
        public:
            Log(){}
            template<typename T>
            Log& info(T t){
                std::clog << "\x1b[1;34m" << t << "\x1b[0m\n";
                return *this;
            }
            template<typename T>
            Log& error(T t){
                std::cerr << "\x1b[1;31m" << t << "\x1b[0m\n";
                return *this;
            }
            template<typename T>
            Log& warn(T t){
                std::cerr << "\x1b[1;33m" << t << "\x1b[0m\n";
                return *this;
            }
            template<typename T>
            Log& operator()(T t){
                return info(t);
            }
        };
        extern Log logger;
    }
}