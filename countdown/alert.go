package main

import (
	"machine"
	"time"
)

var active_buzzer_pin = machine.GP9

func init_alert() {
	active_buzzer_pin.Configure(machine.PinConfig{
		Mode: machine.PinOutput,
	})
}
func alert(t int, times int) {
	state := true
	for i := 0; i < times; i++ {
		active_buzzer_pin.Set(state)
		time.Sleep(time.Millisecond * time.Duration(t))
		state = !state
	}
}
