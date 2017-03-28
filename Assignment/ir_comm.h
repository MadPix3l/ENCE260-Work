/************
Serial Communication module
@Team46
@Authors Tyler Holland | tho63 38233429
@Authors Morgan King | mlk32 23739221
*************/


#ifndef IR_COMM_H
#define IR_COMM_H


#include "ir_uart.h"

#define NO_READ 255

/* get_ir_char returns a character received via IR if there is one available to
 * be read otherwise a char value 255 is returned
 */
char get_ir_char(void);

#endif
