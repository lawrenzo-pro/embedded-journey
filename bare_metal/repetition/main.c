#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB = 63;
    PORTB = 0;
    while(1){
        int i = 0;
        while(i < 63){
            PORTB = i;
            i++;
            _delay_ms(500);
        }
        while(i > 0){
            PORTB = i;
            i--;
            _delay_ms(500);
        }
    }
    //statement never reached
}