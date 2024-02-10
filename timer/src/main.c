#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "stdio.h"
#include "displib.c"

#define RED 20
#define BLUE 21
#define ACTIVE_BUZZER 9
#define BTN_1 7
#define BTN_2 8
#define BTN_3 10
void init_all(){
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_init(BLUE);
    gpio_set_dir(BLUE,GPIO_OUT);
    gpio_init(ACTIVE_BUZZER);
    gpio_set_dir(ACTIVE_BUZZER, GPIO_OUT);
    gpio_init(BTN_1);
    gpio_init(BTN_2);
    gpio_init(BTN_3);
    gpio_set_dir(BTN_1,GPIO_IN);
    gpio_set_dir(BTN_2,GPIO_IN);
    gpio_set_dir(BTN_3,GPIO_IN);
    gpio_pull_down(BTN_1);
    gpio_pull_down(BTN_2);
    gpio_pull_down(BTN_3);
    stdio_init_all();
    display_init();
}
void alert(){
    bool state = true;
    while(state){
        if(gpio_get(BTN_3)){
            state = false;
        }
        gpio_put(ACTIVE_BUZZER, 1);
        sleep_ms(200);
        gpio_put(ACTIVE_BUZZER, 0);
        sleep_ms(200);
    }
}
void countdown(int duration){
    int display;
    while(duration >= 0){
        if(duration >= 10){
            display = duration / 10;
        }
        else {
            display = duration ;
        }
        display_put(display);
        sleep_ms(60*1000);
        clear();
        duration--;
    }
   display_put(duration);
   alert();
}
void indicate(int times){
    for(int i = 0; i <= times; i++){
        gpio_put(RED,true);
        sleep_ms(150);
        gpio_put(RED,false);
        sleep_ms(150);
    }
}
void tens(int num){
      for(int i = 0; i <= num; i++){
       gpio_put(BLUE,true);
        sleep_ms(100);
        gpio_put(BLUE,false);
        sleep_ms(100);
    }
}
void set(int *count){
    bool set = false;
    int num = *count;
    int display;
    while(!set){
        if(gpio_get(BTN_3)){
            set = true;
            *count = num;
        }
        if(gpio_get(BTN_1)){
            num += 1;
            sleep_ms(250);
        }
        if(gpio_get(BTN_2)){
            num -= 1;
            sleep_ms(250);
        }
        if (num < 0){
            num = 9;
            display = num;
        }
        else if (num >= 10){
            display = num / 10;
        }
        else{
            display = num;
        }
        clear();
        display_put(display);
    }
    indicate(3);
}

int main(){
    init_all();
    int count = 0;
    while(1){
        set(&count);
        countdown(count);
    }
}
