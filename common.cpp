#include "common.h"
#include <math.h>

unsigned int adv_to_ms(double fps, unsigned int advances) {
    return (int)(round(1 / fps * 1000 * advances));
}

unsigned int ms_to_adv(double fps, unsigned int ms) {
    return (int)(round(ms / 1000 * fps));
}
