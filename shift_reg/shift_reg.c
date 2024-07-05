#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "math.h"
#include "pico/rand.h"
#include <stdio.h>
#define DAT 1
#define LAT 2
#define CLK 3
uint8_t magic(int value);
void update_reg(uint8_t value){
    value = magic(value);
    gpio_put(DAT,1);
    gpio_put(LAT, 0);
    for(int i = 0; i < 8; i++){
        if(value & (1<<i)){
            gpio_put(DAT,1);
        }
        else{
            gpio_put(DAT,0);
        }
        gpio_put(CLK,0);
        gpio_put(CLK,1);
    }
    gpio_put(LAT, 1);
}
uint8_t magic(int num){
    int size = 8;
    int power = log2(num);
    int offset = 0;
    if(power < size - 1){
        offset = size - (power+1);
    }
    int dest[8];
    power = power + offset;
    int i = 0;
    while(power >= 0){
        int val = pow(2,power);
        int rem = num % val;
        int bit = num / val;
        num = rem;
        dest[i] = bit;
        printf("%d ", bit);
        i++;
        power--;
    }
    printf("\n");
    uint8_t val = 
    dest[0] * 128 + dest[1] * 1 + dest[2] *  2 + dest[3] * 4 + 
    dest[4] * 8 + dest[5] * 16 + dest[6] * 32 + dest[7] * 64 ;
    return val;
}
void all_blue(){
    uint8_t value = 2 + 8 + 32 + 128;
    update_reg(value);
}
void all_green(){
    //impl later
    uint8_t value = 1 + 4 + 16 + 64;
    update_reg(value);
}
void shuffle(uint64_t time, int num){
    for(int i = 0; i <= num; i++){
        all_blue();
        sleep_ms(time);
        all_green();
        sleep_ms(time);
    }
}
void cycle(uint64_t time, int num){
    for(int i = 0; i <= num; i++){
        for(int j = 0; j <= 7; j++){
            uint8_t value = pow(2, j);
            update_reg(value);
            sleep_ms(time);
        }
    }
}
void bin_counter(int DELAY){
     int value = 0;
        while(value < 255){
         update_reg(value);
         value++;
         sleep_ms(DELAY);
        }
        while(value > 0){
         update_reg(value);
         value--;
         sleep_ms(DELAY);
        }
}
void chase(uint64_t time, int num){
    for(int i = 0;i<= num; i++){
        //2 1 4 16 64 128 32 8 2
        update_reg(2);
        sleep_ms(time);
        int i = 1;
        while(i <= 64){
            update_reg(i);
            i *= 4;
            sleep_ms(time);
        }
        i = 128;
        while(i >= 2){
            update_reg(i);
            i = i / 4;
            sleep_ms(time);
        }
    }
}
void random_pattern(uint64_t time,int num){
    for(int i = 0; i <= num; i++){
        uint8_t value = (uint8_t)get_rand_32();
        update_reg(value);
        sleep_ms(time);
    }
}
int main(){
    stdio_init_all();
    gpio_init(DAT);
    gpio_init(LAT);
    gpio_init(CLK);
    gpio_set_dir(DAT,GPIO_OUT);
    gpio_set_dir(LAT,GPIO_OUT);
    gpio_set_dir(CLK,GPIO_OUT);
    while(1){
       bin_counter(60);
       shuffle(300,30);
       cycle(50,30); 
       chase(50,40);
       random_pattern(70,180);
    }
}