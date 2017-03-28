/************
Main Menu module
@Team46
* @Authors Tyler Holland | tho63 38233429
* @Authors Morgan King | mlk32 23739221

* A module to determine which player is 'player-1' and who is 'player-2'. At
* runtime the two players are presented with a menu which they can toggle to
* choose between players 1 and 2. The players toggle with the up and down
* navswitch and select by pressing it down. The selection is sent via the IR
* transmitter and whichever player selects first is that player.
*************/
#ifndef MENU_H
#define MENU_H
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_comm.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define MAX_PLAYERS 2
#define MIN_PLAYERS 1
#define MESSAGE_RATE 15
#define PACER_RATE 500

typedef enum player_val {
    SINGLE,
    PLAYER_1,
    PLAYER_2
} player_val_t;


/* Initialisation for main menu
*/
void menu_init(void);

/** Display a text banner (scrolling text) until the NAVSWITCH_NORTH button
   is pressed
   @ return 0 */
void text_banner(const char* text);

/** Displays a single character passed to the functions
    @input a single char */
void display_character(char character);

/** Allows the user to toggle between 1 and 2 players using the NAVSWITCH_NORTH
    and NAVSWITCH_SOUTH. If NAVSWITCH_PUSH is pressed the current number of
    players is returned */
uint8_t select_player(void);


/** Runs the start menu of the game prompting the user for input. Input or
    scrolling banners are cleared by pressing the NAVSWITCH_NORTH button */
uint8_t menu_task(void);

#endif
