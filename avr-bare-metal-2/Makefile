# =========================================================
# MCU Configuration
# =========================================================

MCU = atmega328p
F_CPU = 16000000UL

# =========================================================
# Toolchain
# =========================================================

CC = avr-gcc
OBJCOPY = avr-objcopy

# =========================================================
# Compiler Flags
# =========================================================

CFLAGS = -mmcu=$(MCU)
CFLAGS += -DF_CPU=$(F_CPU)
CFLAGS += -Os
CFLAGS += -Wall -Wextra

# =========================================================
# Target Name
# =========================================================

TARGET = main

# =========================================================
# Build Rules
# =========================================================

.PHONY: all flash clean

all: $(TARGET).hex

# Generate ELF executable
$(TARGET).elf: main.c
	$(CC) $(CFLAGS) -o $(TARGET).elf main.c

# Convert ELF -> HEX
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

# =========================================================
# Flash MCU
# =========================================================

flash: $(TARGET).hex
	avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:$(TARGET).hex:i

# =========================================================
# Clean Build Files
# =========================================================

clean:
	rm -f *.elf *.hex *.o
