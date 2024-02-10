#include <stdio.h>
//just testing bit masks.....
int main(){
    int x = 0;
    x = (1 << 5);
    x =(x & (1<<5)) == (1<<5);
    printf("%d \n", x);
    x = (1 << 5);
    x = x | (1 << 4);
    printf("%d \n", x);
    x = (x &(1<<4)) == (1<<4);
    printf("%d \n", x);
    x = (1 << 5);
    x = x & ~(1 << 4);
    printf("%d \n", x);
}