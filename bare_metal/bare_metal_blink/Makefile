
BUILD_DIR=build
DEVICE = /dev/ttyUSB0
CPU_FREQ =16000000UL
default: compile


compile:
	avr-gcc -Os -DF_CPU=$(CPU_FREQ) -mmcu=atmega328p -c -o $(BUILD_DIR)/main.o main.c
	avr-gcc -o $(BUILD_DIR)/main.bin $(BUILD_DIR)/main.o


flash: compile
	avr-objcopy -O ihex -R .eeprom $(BUILD_DIR)/main.bin $(BUILD_DIR)/main.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVICE) -b 115200 -U flash:w:$(BUILD_DIR)/main.hex

clean:
	rm $(BUILD_DIR)/*