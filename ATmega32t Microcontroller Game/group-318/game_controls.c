//# File:   game_controls.c
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Functions for player in-game movements


/* Including pre-existing system files */
#include <stdlib.h>
#include "pio.h"
#include "navswitch.h"
#include "tinygl.h"
/* Including all the author made header files */
#include "game_display.h"
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


/* Lights up the player position LED */
static void player_position_led (int8_t col, int8_t row, bool on)
{
    if (on)
    {
        pio_output_low (rows[row]);
        pio_output_low (cols[col]);
    }
    else
    {
        pio_output_high (rows[row]);
        pio_output_high (cols[col]);
    }
}

/* Checks if a tinygl point element exist in an array */
static int8_t element_check(struct tinygl_point array[], int array_size, tinygl_point_t new_point)
{
  int i = 0;
  while (i < array_size)
  {
    if ((array[i].x == new_point.x) & (array[i].y == new_point.y))
    {
      return 1;
    }
    i += 1;
  }
  return 0;
}

/*Check direction that the player would like to move, and move them.
@param tinygl_point_t point
@return void
*/
int8_t player_move(tinygl_point_t new_point, int num_leds, struct tinygl_point correct_points[])
{
    tinygl_init(PACER_RATE);
    int selected_leds = 0;
    struct tinygl_point *selected_points = malloc(sizeof(struct tinygl_point) * num_leds);

    for (int i = 0; i < num_leds; i++)
    {
      selected_points[i] = tinygl_point(-1, -1);
    }

    while(1)
    {
      navswitch_update();
      player_position_led(new_point.x, new_point.y, 1);

      if (selected_leds == num_leds)
      {
        initialise_rows_and_columns();
        return 1;
      }

      if (navswitch_push_event_p (NAVSWITCH_EAST)) {

        player_position_led(new_point.x, new_point.y, 0);
        if ((new_point.x >= 0) & (new_point.x < 4)) {
            new_point.x += 1;
        }
        player_position_led(new_point.x, new_point.y, 1);
      }

      else if (navswitch_push_event_p (NAVSWITCH_WEST))
      {
        player_position_led(new_point.x, new_point.y, 0);
        if ((new_point.x > 0) & (new_point.x <= 4)) {
            new_point.x -= 1;
        }
        player_position_led(new_point.x, new_point.y, 1);
      }

      else if (navswitch_push_event_p (NAVSWITCH_NORTH))
      {
        player_position_led(new_point.x, new_point.y, 0);
        if ((new_point.y > 0) & (new_point.y <= 6)) {
            new_point.y -= 1;
        }
        player_position_led(new_point.x, new_point.y, 1);
      }

      else if (navswitch_push_event_p (NAVSWITCH_SOUTH))
      {
        player_position_led(new_point.x, new_point.y, 0);
        if ((new_point.y >= 0) & (new_point.y < 6)) {
            new_point.y += 1;
        }
        player_position_led(new_point.x, new_point.y, 1);
      }

      if (navswitch_push_event_p (NAVSWITCH_PUSH))
      {
        int found = 0;
        int already_selected = 0;
        /* Looping through all the valid points to check if the selected point is correct */
        found = element_check(correct_points, num_leds, tinygl_point(new_point.x, new_point.y));
        already_selected = element_check(selected_points, num_leds, tinygl_point(new_point.x, new_point.y));
        /* Checks if the row and col matches with correct leds */
        if ((found == 1) & (already_selected == 0))
        {
          selected_points[selected_leds] = tinygl_point(new_point.x, new_point.y);
          /* If correct, blue led blinks 3 times */
          blue_led_blinker();
          //correctly_selected[selected_leds] = new_point.x;
          /*Increment the num of correct leds selected by the player */
          selected_leds += 1;
          /* Break the for loop if found */
        }
        else if ((found == 1) & (already_selected == 1))
        {
          blue_led_blink_once();
          continue;
        }
        else if ((found == 0) & (already_selected == 0))
        {
          blue_led_berserk();
          initialise_rows_and_columns();
          return 0;
          break;
        }
      }
    }
    return 0;
}
