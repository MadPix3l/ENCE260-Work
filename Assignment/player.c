/************
Game module
@Team46
* @Authors Tyler Holland | tho63 38233429
* @Authors Morgan King | mlk32 23739221
*************/

#include "player.h"

#define MIN_HEIGHT 7
#define MAX_COL_INDEX 4

//handles input for the pitcher player returns position of pitcher after input
//takes previous position as a parameter
uint8_t pitcher_input(uint8_t pos){
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        if (pos < MAX_COL_INDEX){
            pos += 1;
        }

    }
    if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        if (pos > 0){
            pos -= 1;
        }
    }
    return pos;
}
//handles input for the catcher player returns position of catcher after input
//takes previous position as a parameter
uint8_t catcher_input(uint8_t col){
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        if (col < MAX_COL_INDEX){
            col += 1;
        }

    }
    if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        if (col > 0){
            col -= 1;
        }
    }
    return col;
}

// initialisation for the pitcher player return the initial position of the pitcher
//takes x and y ledmat coordinates as parameters
tinygl_point_t pitcher_init(tinygl_coord_t pos_x, tinygl_coord_t pos_y){
    tinygl_point_t pitcher_point = tinygl_point(pos_x, pos_y);
    return pitcher_point;
}

// displays the pitcher on the ledmat
// takes pitcher tinygl_point as parameters
void pitcher_render(tinygl_point_t pitcher_point){
    tinygl_draw_point(pitcher_point, 1);
}

// clears the pitcher on the ledmat
// takes pitcher tinygl_point as parameters
void pitcher_clear(tinygl_point_t pitcher_point){
    tinygl_draw_point(pitcher_point, 0);
}

// displays the catcher on the ledmat
// takes highest position x position as parameters
void catcher_render(tinygl_coord_t pos_x2, tinygl_coord_t pos_y1){
    tinygl_point_t point_1 = tinygl_point(pos_x2, pos_y1);
    tinygl_point_t point_2 = tinygl_point(pos_x2, MIN_HEIGHT);
    tinygl_draw_line(point_1, point_2, 1);
}

// clears the catcher on the ledmat
// takes highest position x position as parameters
void catcher_clear(tinygl_coord_t pos_x2, tinygl_coord_t pos_y1){
    tinygl_point_t point_1 = tinygl_point(pos_x2, pos_y1);
    tinygl_point_t point_2 = tinygl_point(pos_x2, MIN_HEIGHT);
    tinygl_draw_line(point_1, point_2, 0);
}

//increases catcher stack_height
// takes previous stack_height as a parameter
void catcher_increase(uint8_t stack_height){
    stack_height++;
}

// decreases catcher stack_height
// takes previous stack_height as a parameter
void catcher_decrease(uint8_t stack_height){
    stack_height--;
}
