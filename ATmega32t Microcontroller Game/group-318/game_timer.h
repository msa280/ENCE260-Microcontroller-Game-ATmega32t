//# File:   game_timer.h
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Header file for game_timer.c.

#ifndef GAME_TIMER_H
#define GAME_TIMER_H

/* Waits for one millisecond */
void wait_milliseconds(void);

/* Waits for half a second */
void wait_half_second(void);

/* Waits for three seconds */
void wait_three_seconds(void);

/* Waits for ten seconds */
void wait_ten_seconds(void);

/* Blinks blue led once */
void blue_led_blink_once(void);

/* Blinks blue led three times */
void blue_led_blinker(void);

/* Blinks blue led multiple times */
void blue_led_berserk(void);


#endif //GAME_TIMER_H
