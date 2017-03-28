/************
Game module
@Team46
@Authors Tyler Holland | tho63 38233429
@Authors Morgan King | mlk32 23739221

This module controls the game play of the game catcher which is loosely based
off of the aracde game stacker

The player is first given a menu screen and given the choice of one or two
player modes. From then on the game is controlled through various states. In one
player mode the blocks that are caught are randomly generated and the game has a
win condition when the stack reaches the top of the screen and a lose condition
when the stack reaches the bottom of the screen. Two player mode operates in the
same manner however one player selects where the block is placed.
*************/

#include "game.h"

#define WIN_MSG "You Win!!"
#define LOSE_MSG "You Lose!!"
#define WIN_STATE 'W'
#define LOSE_STATE 'L'
#define MARCH_SPEED 500
#define MAX_ROW_INDEX 6

static uint8_t stack_height = 4;
static uint8_t position = 0;
static tinygl_point_t block;
static uint16_t ticks = 0;

typedef enum game_state {
    WAIT,
    ADD,
    SUB,
    WIN,
    LOSE
} game_state_t;

int main(void)
{
    //Initialize modules and pacer
    system_init();
    game_init();
    menu_init();
    uint8_t player = menu_task();

    switch(player){

        case PLAYER_1:
            pitcher_task();
            break;

        case PLAYER_2:
            catcher_task();
            break;

        case SINGLE:
            block = block_init(rand_col(), 0);
            singleplayer_task();
            break;

        default:
            break;

    }
    return 0;
}

//main loop for pitcher player
static void pitcher_task(void)
{
    char finish_state = ' ';
    tinygl_point_t pitcher_point = pitcher_init(0,MAX_ROW_INDEX);
    while (1){
        finish_state = get_ir_char();
        pacer_wait();
        navswitch_update();
        tinygl_update();
        if (finish_state == WIN_STATE){
            text_banner(WIN_MSG);
            break;
        } else if (finish_state == LOSE_STATE){
            text_banner(LOSE_MSG);
            break;
        }
        pitcher_clear(pitcher_point);
        position = pitcher_input(position);
        pitcher_point.x = position;
        pitcher_render(pitcher_point);
        block = block_send_interval(MARCH_SPEED, ticks, block, pitcher_point.x);
        ticks++;
    }
}

//main loop for catcher player
static void catcher_task(void)
{
    uint8_t collision;
    uint8_t recv_val = NO_READ;
    uint8_t temp = 0;

    while (1){
        pacer_wait();
        navswitch_update();
        tinygl_update();

        catcher_clear(position, stack_height);
        collision = collision_detect(block, position);

        temp = (uint8_t) get_ir_char();
        if (temp != NO_READ){
            recv_val = temp;
        }

        if (collision == ADD){
            block = update_block(block, recv_val, 0);
            collision = 0;

        } else if (collision == SUB) {
            block = update_block(block, recv_val, 0);
            collision = 0;

        } else if (collision == LOSE){
            ir_uart_putc(WIN_STATE);
            text_banner(LOSE_MSG);

        } else if (collision == WIN){
            ir_uart_putc(LOSE_STATE);
            text_banner(WIN_MSG);
        }
        block = block_recv_interval(MARCH_SPEED, ticks, block, recv_val);
        ticks++;

        position = catcher_input(position);
        catcher_render(position, stack_height);
    }
}

// main loop for a singleplayer game
static void singleplayer_task(void)
{
    uint8_t collision = 0;

    while (1){
        pacer_wait();
        navswitch_update();

        tinygl_update();

        catcher_clear(position, stack_height);
        collision = collision_detect(block, position);
        if (collision == ADD){
            block = update_block(block, rand_col(), 0);
            collision = 0;

        } else if (collision == SUB) {
            block = update_block(block, rand_col(), 0);
            collision = 0;

        }else if (collision == LOSE){
            text_banner(LOSE_MSG);

        } else if (collision == WIN){
            text_banner(WIN_MSG);

        }
        block = block_recv_interval(MARCH_SPEED, ticks, block, rand_col());
        ticks++;

        position = catcher_input(position);
        catcher_render(position, stack_height);
        }
}

// collision detection works out if the ball collides with the catcher player
// tkaes block and column as parameters
static uint8_t collision_detect(tinygl_point_t block, uint8_t position)
{
    if (((block.y) == stack_height) && (block.x == position)){
        if (stack_height-1 <= 1){
            return WIN;
        }
        stack_height -= 1;
        return ADD;

    } else if (((block.y) == stack_height) && (block.x != position)){
        if (stack_height >= MAX_ROW_INDEX){
            return LOSE;
        }
        stack_height += 1;
        return SUB;
    }
    return WAIT;
}
//Function prototypes
//initialises modules that are used (is run before the main loop)
static void game_init(void)
{
    navswitch_init();
    button_init();
    ledmat_init();
    ir_uart_init();
    pacer_init(PACER_RATE);
    tinygl_init(PACER_RATE);

}
