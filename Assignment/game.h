/************
Game module
@Team46
@Authors Tyler Holland tho63 38233429
@Authors Morgan King mlk32 23739221

This module controls the game play of the game catcher which is loosely based
off of the aracde game stacker

The player is first given a menu screen and given the choice of one or two
player modes. From then on the game is controlled through various states. In one
player mode the blocks that are caught are randomly generated and the game has a
win condition when the stack reaches the top of the screen and a lose condition
when the stack reaches the bottom of the screen. Two player mode operates in the
same manner however one player selects where the block is placed.
*************/

#ifndef GAME_H
#define GAME_H

//Includes
#include "system.h"
#include "menu.h"
#include "button.h"
#include "block.h"
#include "pacer.h"
#include "player.h"
#include "ir_comm.h"
#include "tinygl.h"
#include "pio.h"
#include "ledmat.h"
#include "navswitch.h"
#include "../fonts/font5x7_1.h"

//Constants
#define PACER_RATE 500

//Function prototypes
//initialises modules that are used (is run before the main loop)
static void game_init(void);

//main loop for pitcher player
static void pitcher_task(void);

//main loop for catcher player
static void catcher_task(void);

// main loop for a singleplayer game
static void singleplayer_task(void);

// collision detection works out if the ball collides with the catcher player
// tkaes block and column as parameters
static uint8_t collision_detect(tinygl_point_t block, uint8_t position);

#endif
