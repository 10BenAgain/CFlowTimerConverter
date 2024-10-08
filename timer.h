#ifndef TIMER_H
#define TIMER_H

#include "common.h"

class timer
{
public:
    timer(unsigned int adv, unsigned int intro, double fr);
    unsigned int get_total_time();
    unsigned int get_ms_advances();

private:
    double fps;
    unsigned int advances;
    unsigned int intro_timer;
};

#endif // TIMER_H
