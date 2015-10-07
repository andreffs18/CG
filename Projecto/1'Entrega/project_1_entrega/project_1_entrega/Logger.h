//
//  project_1_entrega - Logger.h
//

#ifndef __project_1_entrega__Logger__
#define __project_1_entrega__Logger__

#include <stdio.h>
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

#endif /* defined(__project_1_entrega__Logger__) */