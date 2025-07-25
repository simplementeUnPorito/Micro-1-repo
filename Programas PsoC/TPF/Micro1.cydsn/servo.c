#include "servo.h"

uint16_t angleToPulse(uint8_t angle){
    if (ANGLE_MIN > angle)
        return PULSE_MIN;
    if (angle > ANGLE_MAX)
        return PULSE_MAX;
    return (uint16_t)(SLOPE_ANGLE_TO_PULSE * angle + OFFSET_ANGLE_TO_PULSE);
}


