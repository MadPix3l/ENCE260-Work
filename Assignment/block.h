/*
 * Block Module
 * @Team46
 * @Authors Tyler Holland | tho63 38233429
 * @Authors Morgan King | mlk32 23739221
 * A module to define the characteristics of the block. This will work as a
 * stand alone set of functions to initialise the block for the stacker game.
 * the block is defined in terms of x and y coordinates which are displayed as
 * points on the dot matrix screen.
 */

#ifndef BLOCK_H
#include <stdlib.h>
#include "tinygl.h"

#define ROWS 7
#define COLS 5

//initialisation for the ball (block)
// takes the initial coordinates for the block
tinygl_point_t block_init(tinygl_coord_t pos_x, tinygl_coord_t pos_y);

//updates the y position of the block
//takes the block and then the direction (up or down)
tinygl_point_t move_block(tinygl_point_t block, uint8_t direction);

//one the ball march needs to be reset from a collison update block resets it
//takes the block and the new x and y coordinates
tinygl_point_t update_block(tinygl_point_t block, uint8_t x, uint8_t y);

//random generator to decided next column for the block to spawn in
uint8_t rand_col(void);

//march the ball down toward catcher
// takes limit (move speed), current ticks the block and the column as
//parameters
tinygl_point_t block_recv_interval(uint16_t limit, uint16_t ticks, tinygl_point_t block, uint8_t column);

// match ball away from pitcher
// takes limit (move speed), current ticks the block and the column as
//parameters
tinygl_point_t block_send_interval(uint16_t limit, uint16_t ticks, tinygl_point_t block, uint8_t pitcher_pos_x);

#endif
