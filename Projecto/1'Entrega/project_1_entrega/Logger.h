//
//  project_1_entrega - Logger.h
//
#ifndef __LOGGER_H_INCLUDED__
#define __LOGGER_H_INCLUDED__

#include <iostream>

class Log{
private:
    bool _debug, _info, _error;
public:
    Log();
    ~Log();
    void debug(const std::string & s);
    void info(const std::string & s);
    void error(const std::string & s);
};

#endif /* defined(__LOGGER_H_INCLUDED__) */