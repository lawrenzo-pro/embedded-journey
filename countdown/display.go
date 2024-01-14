package main

import (
	"machine"
	"time"
)

var display_pins = [8]machine.Pin{
	machine.GP2,  //0
	machine.GP3,  // 1
	machine.GP4,  // 2
	machine.GP5,  // 3
	machine.GP16, // 4
	machine.GP17, // 5
	machine.GP18, // 6
	machine.GP19, // 7
}
var digits = map[int][]machine.Pin{
	0: {display_pins[0], display_pins[1], display_pins[2], display_pins[4], display_pins[5], display_pins[6]},
	1: {display_pins[0], display_pins[6]},
	2: {display_pins[0], display_pins[1], display_pins[3], display_pins[4], display_pins[5]},
	3: {display_pins[0], display_pins[1], display_pins[3], display_pins[5], display_pins[6]},
	4: {display_pins[0], display_pins[2], display_pins[3], display_pins[6]},
	5: {display_pins[1], display_pins[2], display_pins[3], display_pins[5], display_pins[6]},
	6: display_pins[1:7],
	7: {display_pins[0], display_pins[1], display_pins[6]},
	8: display_pins[0:7],
	9: {display_pins[0], display_pins[1], display_pins[2], display_pins[3], display_pins[5], display_pins[6]},
}

func init_display() {
	cfg := machine.PinConfig{
		Mode: machine.PinOutput,
	}
	for _, pin := range display_pins {
		pin.Configure(cfg)
	}
}
func display_num(num int) {
	for _, arr := range digits[num] {
		arr.Set(true)
	}
}
func disp_light(t int) {
	state := true
	for {
		display_pins[7].Set(state)
		time.Sleep(time.Millisecond * time.Duration(t))
		state = !state
	}
}
func clear_display() {
	for _, pin := range display_pins {
		pin.Set(false)
	}
}
