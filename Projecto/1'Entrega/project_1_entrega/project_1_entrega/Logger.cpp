//
//  project_1_entrega - Logger.cpp
//

#include "Game.h"
#include "Logger.h"
#include <iostream>

Log::Log(){
    _debug = DEBUG_LOG;
    _info = INFO_LOG;
    _error = ERROR_LOG;
};

Log::~Log(){};

void Log::debug(const std::string & s){
    if(_debug)
        std::cout << "[DEBUG]:" << s << std::endl;
}

void Log::info(const std::string & s){
    if(_info)
        std::cout << "[INFO]:" << s << std::endl;
}

void Log::error(const std::string & s){
    if(_error)
        std::cout << "[ERROR]:" << s << std::endl;
}

