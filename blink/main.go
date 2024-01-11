package main

import (
	"machine"
	"time"
)

func main() {
	led := machine.GP5
	led.Configure(machine.PinConfig{Mode: machine.PinOutput})
	ledSwitch := true
	for {
		led.Set(ledSwitch)
		ledSwitch = !ledSwitch
		time.Sleep(time.Millisecond * 300)
	}
}
