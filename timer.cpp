#include "timer.h"

timer::timer(unsigned int adv, unsigned int intro, double fr) {
    advances = adv;
    intro_timer = intro;
    fps = fr;
}

unsigned int timer::get_total_time() {
    return intro_timer + adv_to_ms(fps, advances);
};

unsigned int timer::get_ms_advances() {
    return adv_to_ms(fps, advances);
};
