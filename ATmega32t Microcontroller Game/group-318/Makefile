# File:   Makefile
# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
# Date:   14 Oct 2021
# Descr:  Compiler for the game file. 

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers -I../../fonts -I../../drivers/avr -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


# Compile: create object files from C source files.

game.o: game.c ../../drivers/avr/system.h	../../drivers/led.h ../../drivers/avr/pio.h	../../utils/tinygl.h	../../drivers/navswitch.h	../../utils/pacer.h	../../drivers/display.h ../../fonts/font5x7_1.h ../../utils/font.h game_timer.h	game_display.h	game_levels.h	game_controls.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: ../../drivers/led.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/led.h
	$(CC) -c $(CFLAGS) $< -o $@

game_timer.o:	game_timer.c	game_timer.h
	$(CC) -c $(CFLAGS) $< -o $@

game_display.o:	game_display.c	game_display.h
	$(CC) -c $(CFLAGS) $< -o $@

game_levels.o: game_levels.c game_levels.h
	$(CC) -c $(CFLAGS) $< -o $@

game_controls.o: game_controls.c game_controls.h
	$(CC) -c $(CFLAGS) $< -o $@




# Link: create ELF output file from object files.
game.out: game.o system.o led.o pio.o	timer.o display.o	navswitch.o ledmat.o font.o pacer.o tinygl.o	game_timer.o	game_display.o	game_levels.o	game_controls.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start
