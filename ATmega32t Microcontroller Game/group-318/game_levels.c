//# File:   game_levels.c
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Functions for controlling in-game levels

/* Including pre-existing system files */
#include <stdlib.h>
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
/* Including all the author made header files */
#include "game_display.h"

/* Defining rates for functions */
#define PACER_RATE 900
#define MESSAGE_RATE 20

/* While loop that keeps showing level LEDs unless navswitch pushed */
static void display_updater(void)
{
  while(1)
  {
    pacer_wait();
    tinygl_update();
    /* Keeps updating navswitch to check for input */
    navswitch_update();
    /* Turns off all LEDS once player is ready to play and navswitch is pushed */
    if (navswitch_push_event_p(NAVSWITCH_PUSH))
    {
      tinygl_clear();
      initialise_rows_and_columns();
      break;
    }
  }
}


struct tinygl_point *level_one (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 1);
  level_points[0] = tinygl_point (0, 0);
  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

/* Returns an array of valid LEDs as tinygl_points to be matched with player
moves. */
struct tinygl_point *level_two (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 2);
  level_points[0] = tinygl_point (1, 1);
  level_points[1] = tinygl_point (3, 5);
  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

struct tinygl_point *level_three (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 3);
  level_points[0] = tinygl_point (0, 0);
  level_points[1] = tinygl_point (0, 6);
  level_points[2] = tinygl_point (4, 0);
  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

struct tinygl_point *level_four (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 4);
  level_points[0] = tinygl_point (4, 3);
  level_points[1] = tinygl_point (1, 2);
  level_points[2] = tinygl_point (2, 5);
  level_points[3] = tinygl_point (0, 6);
  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

struct tinygl_point *level_five (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 5);
  level_points[0] = tinygl_point (0, 5);
  level_points[1] = tinygl_point (3, 6);
  level_points[2] = tinygl_point (4, 4);
  level_points[3] = tinygl_point (3, 0);
  level_points[4] = tinygl_point (1, 2);
  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

struct tinygl_point *level_six (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 6);
  level_points[0] = tinygl_point (3, 6);
  level_points[1] = tinygl_point (3, 3);
  level_points[2] = tinygl_point (1, 2);
  level_points[3] = tinygl_point (2, 0);
  level_points[4] = tinygl_point (0, 4);
  level_points[5] = tinygl_point (2, 3);

  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  tinygl_pixel_set (level_points[5], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}



struct tinygl_point *level_seven (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 7);
  level_points[0] = tinygl_point (1, 6);
  level_points[1] = tinygl_point (1, 0);
  level_points[2] = tinygl_point (3, 1);
  level_points[3] = tinygl_point (4, 4);
  level_points[4] = tinygl_point (4, 6);
  level_points[5] = tinygl_point (1, 5);
  level_points[6] = tinygl_point (0, 3);

  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  tinygl_pixel_set (level_points[5], 1);
  tinygl_pixel_set (level_points[6], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}


struct tinygl_point *level_eight (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 8);
  level_points[0] = tinygl_point (4, 0);
  level_points[1] = tinygl_point (0, 0);
  level_points[2] = tinygl_point (0, 6);
  level_points[3] = tinygl_point (4, 4);
  level_points[4] = tinygl_point (2, 4);
  level_points[5] = tinygl_point (3, 1);
  level_points[6] = tinygl_point (1, 4);
  level_points[7] = tinygl_point (3, 6);


  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  tinygl_pixel_set (level_points[5], 1);
  tinygl_pixel_set (level_points[6], 1);
  tinygl_pixel_set (level_points[7], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}


struct tinygl_point *level_nine (void)
{
  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 9);
  level_points[0] = tinygl_point (3, 3);
  level_points[1] = tinygl_point (1, 3);
  level_points[2] = tinygl_point (0, 0);
  level_points[3] = tinygl_point (1, 0);
  level_points[4] = tinygl_point (3, 0);
  level_points[5] = tinygl_point (0, 5);
  level_points[6] = tinygl_point (1, 4);
  level_points[7] = tinygl_point (4, 5);
  level_points[8] = tinygl_point (4, 6);

  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  tinygl_pixel_set (level_points[5], 1);
  tinygl_pixel_set (level_points[6], 1);
  tinygl_pixel_set (level_points[7], 1);
  tinygl_pixel_set (level_points[8], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}


struct tinygl_point *level_ten (void)
{

  /* Initialises the tinygl and pacer */
  pacer_init (PACER_RATE);
  tinygl_init (PACER_RATE);
  /* Create new array for tinygl_points and adding the points to the array */
  struct tinygl_point *level_points = malloc(sizeof(struct tinygl_point) * 10);
  level_points[0] = tinygl_point (2, 2);
  level_points[1] = tinygl_point (3, 1);
  level_points[2] = tinygl_point (0, 0);
  level_points[3] = tinygl_point (0, 1);
  level_points[4] = tinygl_point (0, 3);
  level_points[5] = tinygl_point (0, 5);
  level_points[6] = tinygl_point (4, 1);
  level_points[7] = tinygl_point (5, 6);
  level_points[8] = tinygl_point (4, 6);
  level_points[9] = tinygl_point (3, 6);

  /* Setting the desired pixels to turn on */
  tinygl_pixel_set (level_points[0], 1);
  tinygl_pixel_set (level_points[1], 1);
  tinygl_pixel_set (level_points[2], 1);
  tinygl_pixel_set (level_points[3], 1);
  tinygl_pixel_set (level_points[4], 1);
  tinygl_pixel_set (level_points[5], 1);
  tinygl_pixel_set (level_points[6], 1);
  tinygl_pixel_set (level_points[7], 1);
  tinygl_pixel_set (level_points[8], 1);
  tinygl_pixel_set (level_points[9], 1);
  /* Loop that updates the LED display. If navswitch pushed, game starts */
  display_updater();
  return level_points;
}

struct tinygl_point *show_level(int8_t current_level)
{
  switch (current_level)
  {
    case 1 :
        return level_one();
    case 2 :
        return level_two();
    case 3:
        return level_three();
    case 4:
        return level_four();
    case 5:
        return level_five();
    case 6:
        return level_six();
    case 7:
        return level_seven();
    case 8:
        return level_eight();
    case 9:
        return level_nine();
    case 10:
        return level_ten();
    default:
    return level_ten();
  }
}
