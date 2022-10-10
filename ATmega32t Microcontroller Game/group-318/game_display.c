//# File:   game_display.c
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Functions for displaying patterns and messages on LED Matrix


/* Including pre-existing system files */
#include "pio.h"
#include "pacer.h"
#include "tinygl.h"
#include "navswitch.h"
#include "../fonts/font5x7_1.h"
/* Including all the author made header files */
#include "game_timer.h"


#define PACER_RATE 900
#define MESSAGE_RATE 20

/** Define PIO pins driving LED matrix rows  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};


void initialise_rows_and_columns(void)
{
  for (uint8_t i = 0; i < 7; i++) {
    pio_config_set(rows[i], PIO_OUTPUT_HIGH);
  }
  for (uint8_t i = 0; i < 5; i++) {
    pio_config_set(cols[i], PIO_OUTPUT_HIGH);
  }
}



void display_message(char message[])
{
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  tinygl_font_set (&font5x7_1);
  tinygl_text_speed_set (MESSAGE_RATE);
  tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
  tinygl_text (message);

  while(1)
  {
    navswitch_update ();
    /*Intro messaging looping and updating*/
    pacer_wait();
    tinygl_update();

    /* If navswitch pushed, message disappears and game starts*/
    if (navswitch_push_event_p (NAVSWITCH_PUSH))
    {
        initialise_rows_and_columns();
        break;
    }
  }
}


void display_level(int8_t current_level)
{
  switch (current_level) {
    case 1 :
        display_message(" LeveL-1 ");
        break;
    case 2 :
        display_message(" LeveL-2 ");
        break;
    case 3 :
        display_message(" LeveL-3 ");
        break;
    case 4 :
        display_message(" LeveL-4 ");
        break;
    case 5 :
        display_message(" LeveL-5 ");
        break;
    case 6 :
        display_message(" LeveL-6 ");
        break;
    case 7 :
        display_message(" LeveL-7 ");
        break;
    case 8 :
        display_message(" LeveL-8 ");
        break;
    case 9 :
        display_message(" LeveL-9 ");
        break;
    case 10 :
        display_message(" LeveL-10 ");
        break;
    default:
    display_message(" Game Bugged ");
  }
}


void display_dead(void)
{
  for (uint8_t i = 0; i < 7; i++) {
    pio_config_set(rows[i], PIO_OUTPUT_LOW);
    for (uint8_t i = 0; i < 5; i++) {
      pio_config_set(cols[i], PIO_OUTPUT_LOW);
    }
  }

  wait_three_seconds();

  pio_config_set(rows[0], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(rows[6], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(cols[0], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(rows[5], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(cols[4], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(rows[1], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(cols[1], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(cols[3], PIO_OUTPUT_HIGH);
  wait_half_second();
  pio_config_set(rows[2], PIO_OUTPUT_HIGH);
  pio_config_set(rows[4], PIO_OUTPUT_HIGH);
  wait_three_seconds();
  pio_config_set(rows[3], PIO_OUTPUT_HIGH);
}


void display_alive(void)
{
  for (uint8_t i = 0; i < 7; i++) {
    wait_milliseconds();
    pio_config_set(rows[i], PIO_OUTPUT_LOW);
    for (uint8_t i = 0; i < 5; i++) {
      wait_milliseconds();
      pio_config_set(cols[i], PIO_OUTPUT_LOW);
    }
  }
  wait_three_seconds();
}



