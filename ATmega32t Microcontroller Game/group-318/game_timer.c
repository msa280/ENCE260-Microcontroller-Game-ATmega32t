//# File:   game_timer.c
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021.
//# Descr:  This file manages functions for time and blue led blinking timing.

/* Including pre-existing system files */
#include "pio.h"
#include "led.h"


static void initialise_timer(void)
{
  TCCR1A = 0x00;
  TCCR1B = 0x05;
  TCCR1C = 0x00;
  TCNT1 = 0;
}


void wait_milliseconds(void)
{
  initialise_timer();
  uint16_t count = 500;
  while (TCNT1 < count)
  {
    continue;
  }
  TCNT1 = 0;
}


void wait_half_second(void)
{
  initialise_timer();
  uint16_t count = 4000;
  while (TCNT1 < count)
  {
    continue;
  }
  TCNT1 = 0;
}


void wait_three_seconds(void)
{
  initialise_timer();
  uint16_t count = 12000;
  while (TCNT1 < count)
  {
    continue;
  }
  TCNT1 = 0;
}


void wait_ten_seconds(void)
{
  initialise_timer();
  uint16_t count = 36000;
  while (TCNT1 < count)
  {
    continue;
  }
  TCNT1 = 0;
}



void blue_led_blink_once(void)
{
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
}


/* Blue LED flashes 3 times if the player selects the correct bomb. */
void blue_led_blinker(void)
{
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
}


void blue_led_berserk(void)
{
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
  wait_milliseconds();
  led_set(LED1, 1);
  wait_milliseconds();
  led_set(LED1, 0);
}
