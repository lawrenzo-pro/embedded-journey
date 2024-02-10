#include <util/delay.h>
int main(){
    volatile unsigned int* data_dir_B = 0x24;//here lies the data direction register for portB
    volatile unsigned int* portB = 0x25; //portB lies in address 0x25 of the mcu

    volatile unsigned int* data_dir_D = 0x2A;
    volatile unsigned int* portD = 0x2B;
    //cursed bitwise maths
    //setting pin 5 and 6 output
    *data_dir_D |= 1 << 5;
    *data_dir_D |= 1 << 6;

    *data_dir_B |= 1 << 0; //set pin 8 and 9 as outputs
    *data_dir_B |= 1 << 1;
    while (1)
    {
       *portD |=  1 << 5; 
       _delay_ms(125);
       *portD &= ~(1<<6); // anding with the ones complement (turn pin 6 off)
       _delay_ms(125);
       *portB |= 1 << 1;
       _delay_ms(125);
       *portB |= 1 << 0 ;
       _delay_ms(125);
       *portD |= 1 << 6 ;
        _delay_ms(125);
       *portD &= ~(1<<5);
        _delay_ms(125);
       *portB &= ~(1<<0);
        _delay_ms(125);
       *portB &= ~(1<<1);
       _delay_ms(125);
    }
} 