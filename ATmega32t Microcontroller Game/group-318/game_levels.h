//# File:   game_levels.h
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Header file for game_levels.c.


#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H



/* Different levels of the game. */
struct tinygl_point *level_one (void);
struct tinygl_point *level_two (void);
struct tinygl_point *level_three (void);
struct tinygl_point *level_four (void);
struct tinygl_point *level_five (void);
struct tinygl_point *level_six (void);
struct tinygl_point *level_seven (void);
struct tinygl_point *level_eight (void);
struct tinygl_point *level_nine (void);
struct tinygl_point *level_ten (void);

/* Plays the current level and returns an array of valid tinygl points */
struct tinygl_point *show_level(int8_t current_level);


#endif //GAME_LEVELS_H
