int disp_select[]= {16,17,18,19};
int dp = 13;
int display_pins[]={6,7,8,9,10,11,12};

//2d arrays are awesome!.
int nums[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},
                    {0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},
                    {1,1,1,0,0,0,0},{1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};
void display_init(){
    for(int i = 0; i < 4;i++){
        gpio_init(disp_select[i]);
        gpio_set_dir(disp_select[i],GPIO_OUT);
    }
    for(int i = 0; i < 7;i++){
        gpio_init(display_pins[i]);
        gpio_set_dir(display_pins[i],GPIO_OUT);
        gpio_put(display_pins[i], 1);
    }
    gpio_init(dp);
    gpio_set_dir(dp,GPIO_OUT);
    gpio_put(dp, 1);
}
void print_to_display(int digit,int num){
    gpio_put(disp_select[digit], 1);
    if(num >= 10 || num < 0){
        num = 0;
    }
    for(int i = 0; i < 7; i++){
        gpio_put(display_pins[i], !nums[num][i]);
    }
}
void clear_single_display(int digit){
    gpio_put(disp_select[digit], 0);
    for(int i = 0; i < 7; i++){
        gpio_put(display_pins[i], 1);
    }
}
void clear_all(){
     for(int i = 0; i < 4; i++){
        gpio_put(disp_select[i],0);
        for(int j = 0; j< 7; j++){
            gpio_put(display_pins[j],1);
        }
    }
}
void print_num(int num,int delay_ms){
    int thousands = num / 1000;
    int hundreds = (num%1000) / 100;
    int tens = (num%100) / 10;
    int ones = (num % 10);
    int iter_time = delay_ms / 1;
    for(int i = 0; i < iter_time;i++){
        print_to_display(3,thousands);
        busy_wait_us(250);
        clear_single_display(3);
        print_to_display(2,hundreds);
        busy_wait_us(250);
        clear_single_display(2);
        print_to_display(1,tens);
        busy_wait_us(250);
        clear_single_display(1);
        print_to_display(0,ones);
        busy_wait_us(250);
        clear_single_display(0);
    }
}