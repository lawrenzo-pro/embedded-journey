#include <util/delay.h>
typedef unsigned char byte;
int main(void){
    //I shall not be afraid of direct register access;
    volatile byte * data_dir_reg = 0x2A;
    volatile byte * in_reg = 0x29;
    volatile byte * out_reg = 0x2B;
   *data_dir_reg = 0b11000000; 
    byte state_1 = 0;
    byte state_2 = 0;
    while(1){
        if((*in_reg & 0b00100000) == 0b00100000){
            state_1 = !state_1;
            _delay_ms(200);
        }
        if((*in_reg & 0b00010000) == 0b00010000){
            state_2 = !state_2;
            _delay_ms(200);
        } 
        if(state_1){
            *out_reg = 0b10000000;
        }
        else{
            *out_reg &= ~(0b10000000); // OUTREG AND (NOT 128) ; unset bit 7
        }
        if(state_2){
            *out_reg = 0b01000000;
        }
        else{
            *out_reg &= ~(0b01000000); // OUTREG AND (NOT 64) ; unset bit 6
        }
    }
}