/************
Serial Communication module
@Team46
@Authors Tyler Holland | tho63 38233429
@Authors Morgan King | mlk32 23739221
*************/

#include "ir_comm.h"
static char character;

/* get_ir_char returns a character received via IR if there is one available to
 * be read otherwise a char value 255 is returned
 */
char get_ir_char(void){

    if (ir_uart_read_ready_p()){
        character = ir_uart_getc();
        return character;
    }
    return 255;
}
