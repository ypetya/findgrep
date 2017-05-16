//
// Created by Peter_Kiss on 2017. 05. 08..
//

#ifndef CPP_UTILILTIES_MEASURERUNTIME_H
#define CPP_UTILILTIES_MEASURERUNTIME_H

#include <chrono>

using namespace std::chrono;

class MeasureRuntime {
private:
    milliseconds start;
public:
    MeasureRuntime();
    void stop();

};


#endif //CPP_UTILILTIES_MEASURERUNTIME_H
