#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "pico/multicore.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"
#include "hardware/adc.h"
#define R0 16
#define B 17
#define R1 18
#define POT 26
void core1_main(){
    while(true){
        int val = 0;
        while( val < 256){
            pwm_set_gpio_level(R0,val * 255);
            pwm_set_gpio_level(R1,val * 255);
            sleep_ms(15);
            val++;
        }
        while( val > 0){
            pwm_set_gpio_level(R0,val * 255);
            pwm_set_gpio_level(R1,val * 255);
            sleep_ms(15);
            val--;
        }
    }
}
int main(){
    stdio_init_all();//not needed,but I don't like pressing BOOTSEL
    //set up the analog to digital converter
    adc_init();
    adc_gpio_init(POT);
    adc_select_input(0);
    //use these pins for pulse-width-modulation
    gpio_set_function(R0, GPIO_FUNC_PWM);
    gpio_set_function(R1, GPIO_FUNC_PWM);
    gpio_set_function(B , GPIO_FUNC_PWM);
    //allocate a 'slice' of the pwm pie
    uint slice_r0 = pwm_gpio_to_slice_num(R0);
    uint slice_b = pwm_gpio_to_slice_num(B);
    uint slice_r1 = pwm_gpio_to_slice_num(R1);
    //configure the pwm
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f); //Idk why 4.f but the docs say so...
    //initialize the pwm outputs
    pwm_init(slice_r0,&config,true);
    pwm_init(slice_b,&config,true);
    pwm_init(slice_r1,&config,true);

    multicore_launch_core1(core1_main);
    while(true){
       int result = adc_read() / 16;//read the value and convert it to sth the pwm can with.
       pwm_set_gpio_level(B,result * 255);

    }
    return 0;
}