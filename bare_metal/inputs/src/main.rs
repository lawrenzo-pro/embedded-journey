#![no_std]
#![no_main]
use panic_halt as _;
#[arduino_hal::entry]
fn main() ->! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);
    let btn1 = pins.d2.into_pull_up_input();
    let btn2 = pins.d3.into_pull_up_input();
    let btn3 = pins.d4.into_pull_up_input();
    let mut led1 = pins.d5.into_output();
    let mut led2 = pins.d6.into_output();
    let mut led3 = pins.d7.into_output();
    loop {
        if btn1.is_low(){
            led1.toggle();
        }
        if btn2.is_low(){
            led2.toggle();
        }
        if btn3.is_low(){
            led3.toggle();
        }
        arduino_hal::delay_ms(300);
    }
}