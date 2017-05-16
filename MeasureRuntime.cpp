//
// Created by Peter_Kiss on 2017. 05. 08..
//

#include <cstdio>
#include "MeasureRuntime.h"

MeasureRuntime::MeasureRuntime() {
    this->start = duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch());
}

void MeasureRuntime::stop() {
    duration<double> elapsed_ms = duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()) - start;
    printf("%f milliseconds\n", elapsed_ms.count());
}
