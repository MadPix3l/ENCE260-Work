/************
Game module
@Team46
* @Authors Tyler Holland | tho63 38233429
* @Authors Morgan King | mlk32 23739221
*************/

#ifndef PLAYER_H
#define PLAYER_H
#include "navswitch.h"
#include "tinygl.h"

#define PITCHER_LED 0x40
#define CATCHER_START_ROW 0x70


//handles input for the pitcher player returns position of pitcher after input
//takes previous position as a parameter
uint8_t pitcher_input(uint8_t pos);

//handles input for the catcher player returns position of catcher after input
//takes previous position as a parameter
uint8_t catcher_input(uint8_t col);

// initialisation for the pitcher player return the initial position of the pitcher
//takes x and y ledmat coordinates as parameters
tinygl_point_t pitcher_init(tinygl_coord_t pos_x, tinygl_coord_t pos_y);

// displays the pitcher on the ledmat
// takes pitcher tinygl_point as parameters
void pitcher_render(tinygl_point_t pitcher);

// clears the pitcher on the ledmat
// takes pitcher tinygl_point as parameters
void pitcher_clear(tinygl_point_t pitcher);

// displays the catcher on the ledmat
// takes highest position x position as parameters
void catcher_render(tinygl_coord_t pos_x2, tinygl_coord_t pos_y1);

// clears the catcher on the ledmat
// takes highest position x position as parameters
void catcher_clear(tinygl_coord_t pos_x2, tinygl_coord_t pos_y1);

//increases catcher stack_height
// takes previous stack_height as a parameter
void catcher_increase(uint8_t stack_height);

// decreases catcher stack_height
// takes previous stack_height as a parameter
void catcher_decrease(uint8_t stack_height);
#endif
