#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "display.c"
#define MODE_BTN 1
#define SET_BTN 2
#define OK_BTN  3
#define ADD_BTN 4
#define ALM_BTN 5
#define LED 14
#define LED_IND 20
#define BUZZER 15
int count = 0;
int hours = 0;
int minutes = 0;
int target = 0;
int get_count(){
    return count;
}
int get_target(){
    return target;
}
void set_count(int new_count){
    count = new_count;
}
void set_target(int new_target){
    target = new_target;
}
int get_hour(){
    int hours = count / 100;
    if(hours >= 24){ hours = 0;}
    return hours;
}
int get_minute(){
    int minutes = count % 100;
    return minutes;
}

void clock(){
        
}
void init(){
    gpio_init(LED);
    gpio_init(LED_IND);
    gpio_init(BUZZER);
    gpio_set_dir(LED,GPIO_OUT);
    gpio_set_dir(LED_IND,GPIO_OUT);
    gpio_set_dir(BUZZER,GPIO_OUT);
    for(int i = 1;i <= 5; i++){
        gpio_init(i);
        gpio_set_dir(i,GPIO_IN);
        gpio_pull_down(i);
    }
}
void set(){
    gpio_put(LED,1);
    bool state = false;
    bool ok = false;
    int num_minute = get_minute();
    int num_hour = get_hour();
    int num_t = get_count();
    while(!ok){
        while(!state){
            if(num_t >= 2400){
                num_t = 0;
            }
            if(gpio_get(OK_BTN)){
                printf("Aha!");
                gpio_put(BUZZER, 1);
                busy_wait_ms(200);
                gpio_put(BUZZER,0);
                state = true;
            }
            if(num_minute >= 60 ){
                num_minute = 0;
                num_hour++;
            }
            if(gpio_get(ADD_BTN)){
                num_minute = num_minute + 1;
                busy_wait_ms(120);
            }
            num_t = (num_hour * 100) + num_minute;
            print_num(num_t, 30);
            clear_all();
        }
        if(gpio_get(SET_BTN)){
            ok = true;
            printf("Done! \n");
        }
        if(gpio_get(OK_BTN)){
            state = false;
        }
        if(num_hour >= 24){
            num_hour = 0;
        }
        if(gpio_get(ADD_BTN)){
            num_hour = num_hour + 1;
            busy_wait_ms(120);
        }
        num_t = (num_hour * 100) + num_minute;
        printf("%d \n" , num_t);
        print_num(num_t, 40);
        clear_all();
    }
    gpio_put(LED,0);
    set_count(num_t);
    printf("%d \n",count);
}
void set_alarm(){
    gpio_put(LED_IND,1);
    bool state = false;
    bool ok = false;
    int num_t = get_target();
    int num_minute = num_t % 100;
    int num_hour = num_t / 100;
    while(!ok){
        while(!state){
            if(num_t >= 2400){
                num_t = 0;
            }
            if(gpio_get(OK_BTN)){
                printf("Aha!");
                gpio_put(BUZZER, 1);
                busy_wait_ms(200);
                gpio_put(BUZZER,0);
                state = true;
            }
            if(num_minute >= 60 ){
                num_minute = 0;
                num_hour++;
            }
            if(gpio_get(ADD_BTN)){
                num_minute = num_minute + 1;
                busy_wait_ms(120);
            }
            num_t = (num_hour * 100) + num_minute;
            set_target(num_t);
            print_num(target, 30);
            clear_all();
        }
        if(gpio_get(SET_BTN)){
            ok = true;
            printf("Done! \n");
        }
        if(gpio_get(OK_BTN)){
            state = false;
        }
        if(num_hour >= 24){
            num_hour = 0;
        }
        if(gpio_get(ADD_BTN)){
            num_hour = num_hour + 1;
            busy_wait_ms(120);
        }
        num_t = (num_hour * 100) + num_minute;
        printf("%d \n" , num_t);
        set_target(num_t);
        print_num(target, 40);
        clear_all();
    }
    gpio_put(LED_IND,0);
}
void change_mode(uint gpio, uint32_t event){
    if(gpio == MODE_BTN){
        set();
        busy_wait_ms(150);
    }
    if(gpio == ALM_BTN){
        set_alarm();
        busy_wait_ms(150);
    }
}
bool cleared = true;
bool tick(struct repeating_timer *t){
    cleared = false;
    minutes = get_minute();
    hours = get_hour();
    minutes++;
    if(minutes % 60 == 0 && minutes != 0){
            hours++;
            minutes = 0;
    }
    set_count((hours * 100) + minutes);
}
void alarm(){
    for(int i = 0; i < 20;i++){
        if(gpio_get(OK_BTN)){
            cleared = true;
            break;
        }
        gpio_put(BUZZER,1);
        sleep_ms(200);
        gpio_put(BUZZER,0);
        sleep_ms(200);
    }
}
void show_time(){
    //I cannot believe it took me this long to figure this out.
    count = get_count();
    print_num(count, 1);
}
int main()
{
    stdio_init_all();
    init();
    display_init();
    const int minute = 60 * 1000;
    gpio_set_irq_enabled_with_callback(MODE_BTN,GPIO_IRQ_EDGE_RISE,true,change_mode);
    gpio_set_irq_enabled_with_callback(ALM_BTN,GPIO_IRQ_EDGE_RISE,true,change_mode);
    struct repeating_timer timer;
    add_repeating_timer_ms(minute,tick,NULL,&timer);
    while(true){
        show_time();
        if(get_count() == get_target()&&!cleared){
           alarm();
        }
    }
    return 0;
}
