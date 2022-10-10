//# File:   game_controls.h
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Header file for game_controls.c.


#ifndef GAME_CONTROLS_H
#define GAME_CONTROLS_H


/* Allows the player to move on the grid */
int8_t player_move(tinygl_point_t new_point, int num_leds, struct tinygl_point correct_points[]);



#endif //GAME_CONTROL_H
