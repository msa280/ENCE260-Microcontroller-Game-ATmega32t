//# File:   game.c
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Main game file. This is where the whole game code has been setup.

/* Including pre-existing system files */
#include "system.h"
#include <stdlib.h>
#include <stddef.h>
#include "led.h"
#include "tinygl.h"

/* Including all the author made header files */
#include "game_timer.h"
#include "game_display.h"
#include "game_levels.h"
#include "game_controls.h"


/* Main function which runs the game. */
int main (void)
{
    system_init();
    led_init();

    display_message(" BOMB DEFUSERS  By: Haider & Cara");
    wait_half_second();
    led_set(LED1, 0);

    /* Games initial parameters set */
    tinygl_point_t current_position = {.x = 2, .y = 6};
    int8_t level_passed = 0;
    int8_t player_score = 0;
    int8_t current_level = 1;

    while (current_level <= 10)
    {
      display_level(current_level);
      struct tinygl_point *correct_points = malloc(sizeof(struct tinygl_point) * current_level);
      correct_points = show_level(current_level);
      level_passed = player_move(current_position, current_level, correct_points);

      if (level_passed)
      {
        free(correct_points);
        display_alive();
        player_score += 10;
        current_level += 1;
      }
      else
      {
        free(correct_points);
        break;
      }
    }

    led_set(LED1, 1);

    display_dead();
    display_message(" X GAME OVER X");

    wait_ten_seconds();
    /* Blue led turns off 10 seconds after game is over */
    led_set(LED1, 0);
    return 0;
}
