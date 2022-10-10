//# File:   game_display.h
//# Author: Haider Saeed (msa-280), Cara Kruger(ckr33)
//# Date:   14 Oct 2021
//# Descr:  Header file for game_display.c.


#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

/* Initialises and turns off all the LEDs */
void initialise_rows_and_columns(void);


/* Takes a message and displays it */
void display_message(char message[]);

/* Displays the level number on LED Matrix */
void display_level(int8_t current_level);

/* Ending game LED pattern if game lost */
void display_dead(void);

/* Game continuing LED pattern if level passed */
void display_alive(void);



#endif //GAME_DISPLAY_H
