package main

import (
	"machine"
	"time"

	"tinygo.org/x/drivers/buzzer"
)

type note struct {
	tone     float64
	duration float64
}

func music_play() {
	bzrPin := machine.GP6
	bzrPin.Configure(machine.PinConfig{Mode: machine.PinOutput})
	bzr := buzzer.New(bzrPin)

	notes := []note{
		{buzzer.C5, buzzer.Quarter},
		{buzzer.C5, buzzer.Quarter},
		{buzzer.G5, buzzer.Quarter},
		{buzzer.G5, buzzer.Quarter},
		{buzzer.A5, buzzer.Quarter},
		{buzzer.A5, buzzer.Quarter},
		{buzzer.G5, buzzer.Half},
		{buzzer.F5, buzzer.Quarter},
		{buzzer.F5, buzzer.Quarter},
		{buzzer.E5, buzzer.Quarter},
		{buzzer.E5, buzzer.Quarter},
		{buzzer.D5, buzzer.Quarter},
		{buzzer.D5, buzzer.Quarter},
		{buzzer.C5, buzzer.Half},
	}

	for _, n := range notes {
		bzr.Tone(n.tone, n.duration)
		time.Sleep(10 * time.Millisecond)
	}
}
