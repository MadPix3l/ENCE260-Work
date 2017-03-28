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

#include "menu.h"
//#include "ir_comm.h"
//#define PACER_RATE 500
//#define MESSAGE_RATE 10

#define MAX_PLAYERS 2
#define MIN_PLAYERS 1
#define SINGLE_CHAR_BUFF 2
#define TITLE "Catcher!"
#define PLAYERS_MSG "Number of Players?..."


/* Initialisation for main menu
*/
void menu_init(void)
{
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

}

/** Display a text banner (scrolling text) until the NAVSWITCH_NORTH button
   is pressed
   @ return 0 */
void text_banner(const char* text)
{
    //Set the desired message
    tinygl_text(text);

    uint8_t pressed = 0;
    while(pressed == 0) //continue scrolling until button is pressed
    {
        //check to see if the navswitch button is pressed
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            pressed = 1;
        }

        pacer_wait();

        //Update functions
        tinygl_update();
        navswitch_update ();

    }
    tinygl_clear();
}


/** Displays a single character passed to the functions
    @input a single char */
void display_character (char character)
{
    char buffer[SINGLE_CHAR_BUFF];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

/** Allows the user to toggle between 1 and 2 players using the NAVSWITCH_NORTH
    and NAVSWITCH_SOUTH. If NAVSWITCH_PUSH is pressed the current number of
    players is returned */
uint8_t select_player(void)
{
    char character = '1';
    uint8_t player =  MIN_PLAYERS;
    uint8_t flag = 0;

    while (flag != 1)
    {
        tinygl_update ();
        navswitch_update();
        //Changing a character

        if (navswitch_push_event_p (NAVSWITCH_NORTH) && player < MAX_PLAYERS){
            character++;
            player++;
        }

        if (navswitch_push_event_p (NAVSWITCH_SOUTH) && player > MIN_PLAYERS){
            character--;
            player--;
        }

        if (navswitch_push_event_p (NAVSWITCH_PUSH)){
            if (player == PLAYER_1){
                player = SINGLE;
            }
            if (player == PLAYER_2){
                ir_uart_putc((char) PLAYER_2);
                player = PLAYER_1;
            }
            flag = 1;
        }

        if (get_ir_char() == (char) PLAYER_2){
            player = PLAYER_2;
            flag = 1;
        }
        display_character (character);

    }
    tinygl_clear();
    return player;
}

/** Runs the start menu of the game prompting the user for input. Input or
    scrolling banners are cleared by pressing the NAVSWITCH_NORTH button */
uint8_t menu_task(void)
{
    uint8_t players;
    text_banner(TITLE);
    text_banner(PLAYERS_MSG);
    players = select_player();

    return players;
}
