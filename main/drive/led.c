#include "led.h"


#include "driver/pwm.h"

#define PWM_R_OUT_IO_NUM   12
#define PWM_G_OUT_IO_NUM   13
#define PWM_B_OUT_IO_NUM   15


// PWM 周期 1000us(1Khz)
#define PWM_PERIOD    (1000)
// 占空比duties table, real_duty = duties[x]/PERIOD
uint32_t duties[4] = {
    500, 500, 500, 500,
};
// 相位 table, delay = (phase[x]/360)*PERIOD
float phase[4] = {
    0, 0, 90.0, -90.0,
};

const uint32_t led_pin_num[4] = {
    PWM_R_OUT_IO_NUM,
    PWM_G_OUT_IO_NUM,
    PWM_B_OUT_IO_NUM
};
void led_init(){
     pwm_init(PWM_PERIOD, duties, 4, led_pin_num);
    // pwm_set_phases(phase);
    pwm_start();
}
