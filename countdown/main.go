package main

import (
	"machine"
	"time"
)

func main() {
	init_display()
	init_alert()
	led := machine.GP20
	min_led := machine.GP21
	led.Configure(machine.PinConfig{
		Mode: machine.PinOutput,
	})
	min_led.Configure(machine.PinConfig{
		Mode: machine.PinOutput,
	})
	btn := machine.GP7
	btn2 := machine.GP8
	btn3 := machine.GP10
	btn.Configure(machine.PinConfig{
		Mode: machine.PinInputPulldown,
	})
	btn2.Configure(machine.PinConfig{
		Mode: machine.PinInputPulldown,
	})
	btn3.Configure(machine.PinConfig{
		Mode: machine.PinInputPulldown,
	})
	count := 0
	for {
		set_count(&count, btn2, btn, led, btn3)
		countdown(count, min_led, led)
	}
	//alert(500, 10)

}
func set_count(count *int, p machine.Pin, q machine.Pin, r machine.Pin, s machine.Pin) {
	num := 0
	set := false
	for {
		if set {
			*count = num
			break
		}
		if p.Get() {
			set = true
			set_led(r)
		}
		if q.Get() {
			num += 1
		}
		if s.Get() {
			music_play()
		}
		if num >= 10 {
			num = 0
		}
		display_num(num)
		time.Sleep(time.Millisecond * 150)
		clear_display()
	}
}
func countdown(count int, p machine.Pin, r machine.Pin) {
	display_num(count)
	i := count
	go min_blink(p)
	go sec_blink(r)
	for {
		display_num(i)
		if i <= 0 {
			break
		}
		time.Sleep(time.Minute * 10)
		clear_display()
		i -= 1
	}
	alert(500, 10)
}
func set_led(p machine.Pin) {
	state := true
	for i := 0; i <= 5; i++ {
		p.Set(state)
		time.Sleep(time.Millisecond * 100)
		state = !state
	}
}
func min_blink(p machine.Pin) {
	state := true
	for {
		for i := 0; i <= 2; i++ {
			p.Set(state)
			time.Sleep(time.Millisecond * 150)
			p.Set(!state)
			time.Sleep(time.Millisecond * 150)
		}
		time.Sleep(time.Minute * 1)
	}
}
func sec_blink(p machine.Pin) {
	state := true
	for {
		p.Set(state)
		time.Sleep(time.Millisecond * 500)
		p.Set(!state)
		time.Sleep(time.Millisecond * 500)
	}
}
