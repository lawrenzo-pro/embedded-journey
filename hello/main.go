package main

import (
	"machine"

	"tinygo.org/x/drivers/hd44780"
)

func main() {
	i2c := machine.I2C0
	err := i2c.Configure(
		machine.I2CConfig{
			SCL: machine.GPIO5,
			SDA: machine.GPIO4,
		},
	)
	config := hd44780.Config{
		Width:       16,
		Height:      2,
		Font:        2,
		CursorBlink: true,
	}
	dev := hd44780.Device()
	if err != nil {
		println("Couldn't continue!")
	}
}
